import math
from inventory import check_inventory
from inventory import ritual_needs
from inventory import check_tile_for_players
from broadcast import check_broadcast_pattern
from commands.movement_commands import *
from commands.players_commands import *
from commands.object_commands import *
from commands.status import *


def decide_forward(client, response: str):
    client.cmd_buff.remove("Forward")

def decide_right(client, response: str):
    client.cmd_buff.remove("Right")

def decide_left(client, response: str):
    client.cmd_buff.remove("Left")

def check_tile_for_players(client, tile: str):
    players = tile.count("player")
    if players < ritual_needs[client.level]["players"]:
        return False
    return True


def decide_look(client, response: str):
    client.cmd_buff.remove("Look")
    response_list = [x.strip() for x in response.split(',')]
    print(response_list)
    available_items = ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]

    if any(item in response_list for item in available_items) and client.status == JOINING:
        client.status = SETTING
        return

    if any(item in response_list for item in client.missing):
        for item in client.missing:
            if item in response_list:
                print(f"I found the item I need to level up: {item}")
                if "Take" not in client.cmd_buff:
                    send_take_object_command(client, item)
                print(f"I pick up the item: {item}")
                return

    if "food" in response_list:
        print("I found food!")
        if "Take" not in client.cmd_buff:
            send_take_object_command(client, "food")
        print("I pick up the food!")
        return

    rarest_item = None
    rarest_count = float('inf')
    for item in available_items:
        count = response_list.count(item)
        if count < rarest_count:
            rarest_item = item
            rarest_count = count

    if rarest_item is not None:
        print(f"I found the rarest item: {rarest_item}")
        if "Take" not in client.cmd_buff:
            send_take_object_command(client, rarest_item)
        print(f"I pick up the item: {rarest_item}")
        return

    nearest_item = None
    nearest_distance = float('inf')
    starting_position = response_list.index(client.missing[0])
    for index, tile in enumerate(response_list):
        if any(item in tile for item in available_items):
            distance = abs(starting_position - index)
            if distance < nearest_distance:
                nearest_item = tile
                nearest_distance = distance

    if nearest_item is not None:
        if nearest_distance > 0:
            send_forward_command(client)
            print("I go forward")
        elif nearest_distance < 0:
            send_right_command(client)
            print("I go right")
        else:
            send_left_command(client)
            print("I go left")

    decide_look(client, response)






def decide_inventory(client, response: str):
    client.cmd_buff.remove("Inventory")
    if client.status != NORMAL:
        return
    client.missing = check_inventory(client, response)
    global_missing = True
    for item in client.missing:
        if client.missing[item] > client.team_items[item]:
            global_missing = False
            break
    if global_missing == False and client.level != 1:
        send_broadcast_text_command(client, f"{client.team} {client.level} READY")
        client.status = CALLING
    elif global_missing == False and client.level == 1:
        for item in ritual_needs[client.level]:
            if item == "players":
                continue
            for i in range(min(client.inventory[item], ritual_needs[client.level][item])):
                client.setting_items.append(item)
            client.status = SETTING

def decide_broadcast(client, response: str):
    client.cmd_buff.remove("Broadcast")

def decide_connect_nbr(client, response: str):
    client.cmd_buff.remove("Connect_nbr")

def decide_fork(client, response: str):
    client.cmd_buff.remove("Fork")

def decide_eject(client, response: str):
    client.cmd_buff.remove("Eject")

def decide_take(client, response: str):
    client.cmd_buff.remove("Take")

def decide_set(client, response: str):
    client.cmd_buff.remove("Set")

def decide_incantation(client, response: str):
    client.cmd_buff.remove("Incantation")
    client.status = 0
    client.level += 1

def died(client, response: str):
    client.status = DEAD

def decide_heard(client, response: str):
    check_broadcast_pattern(response, client)

def decide_ejected(client, response: str):
    print("Should make decision after being ejected")
