import math
from inventory import check_inventory
from inventory import ritual_needs
from broadcast import check_broadcast_pattern
from commands.movement_commands import *
from commands.players_commands import *
from commands.object_commands import *
from status import *

def decide_forward(client, response: str):
    client.cmd_buff.remove("Forward")

def decide_right(client, response: str):
    client.cmd_buff.remove("Right")

def decide_left(client, response: str):
    client.cmd_buff.remove("Left")

def decide_look(client, response: str):
    client.cmd_buff.remove("Look")
    response_list = [x.strip() for x in response.split(',')]
    print(response_list)
    nearest_food = None # replace with missing
    nearest_distance = float('inf')
    starting_position = response_list.index("stone")
    print("I go forward first of all")
    send_forward_command(client)

    for index, tile in enumerate(response_list):
        if tile in client.missing:
            distance = abs(starting_position - index)
            if distance < nearest_distance:
                nearest_food = index
                nearest_distance = distance

    if nearest_food is not None:
        if "food" in client.missing:
            if nearest_food < starting_position:
                send_left_command(client)
                print("I go left")
            elif nearest_food > starting_position:
                send_forward_command(client)
                print("I go forward")
            else:
                print("I go right")
                send_right_command(client)
        else:
            nearest_item = response_list[nearest_food]
            print(f"I found the nearest {nearest_item}!")
            send_take_object_command(client, nearest_item)
    else:
        print("No missing items found in the visible tiles.")


    decide_look(client, response)


def decide_inventory(client, response: str):
    client.cmd_buff.remove("Inventory")
    if client.status != NORMAL:
        return
    client.missing = check_inventory(client, response)
    global_missing = True
    for item in client.missing:
        if client.missing[item] > client.team_items.missing:
            global_missing = False
            break
    if global_missing == False and client.level != 1:
        send_broadcast_text_command(client, f"{client.team} {client.level} READY")
        client.status = CALLING
    elif global_missing == False and client.level == 1:
        for item in ritual_needs[client.level]:
            if client.inventory[item] > 0:
                client.setting_items[item] += (min(client.inventory[item], ritual_needs[client.level][item]))
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