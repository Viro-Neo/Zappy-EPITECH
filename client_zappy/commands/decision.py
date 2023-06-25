import math
from inventory import check_inventory
from inventory import ritual_needs
from inventory import check_tile_for_players
from broadcast import check_broadcast_pattern
from commands.movement_commands import *
from commands.players_commands import *
from commands.object_commands import *
from commands.status import *
from commands.look_movement import setup_movement


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

tile_order = [0, 2, 1, 3, 6, 12, 5, 7, 11, 13, 4, 8, 10, 14, 9, 15]

def pick_up_decision(client, tile, no) -> bool:
    print(f"in pick_up decision for tile {no}")
    rarity_sorted = ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
    for item in client.missing:
        print(f"checking for item {item}")
        if item in tile:
            if no == 0 and "Take" not in client.cmd_buff:
                print(f"attempting to pick up {item}")
                send_take_object_command(client, item)
                client.taking.append(item)
            return True
    if "food" in tile:
        if no == 0 and "Take" not in client.cmd_buff:
            print(f"attempting to pick up food")
            send_take_object_command(client, "food")
            client.taking.append("food")
        return True
    for item in rarity_sorted:
        if item in tile:
            if no == 0 and "Take" not in client.cmd_buff:
                print(f"attempting to pick up {item}")
                send_take_object_command(client, item)
                client.taking.append(item)
            return True
    return False

def decide_look(client, response: str):
    client.cmd_buff.remove("Look")
    tile_list = [x.strip() for x in response.split(',')]
    tiles = []
    for tile in tile_list:
        tiles.append(tile.strip("[]").split(' '))
    for i in range(len(tiles), 16):
        tiles.append([])
    
    if check_tile_for_players(client, tiles[0]) and client.status == JOINING:
        client.status == SETTING
        return

    for tile_no in tile_order:
        if pick_up_decision(client, tiles[tile_no], tile_no):
            if tile_no > 0:
                setup_movement(client, tile_no)
            return

def decide_inventory(client, response: str):
    client.cmd_buff.remove("Inventory")
    if client.status != NORMAL:
        return
    client.missing = check_inventory(client, response)
    global_missing = True
    for item in client.missing:
        if client.missing[item] <= client.team_items[item]:
            global_missing = False
            break
    if client.missing == {}:
        global_missing = False
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
    if response == "ko" or client.taking[0] == "food":
        client.taking.pop(0)
        return
    if client.level > 1:
        send_broadcast_text_command(client, f"{client.team} {client.level} {client.taking[0]}")
    client.taking.pop(0)

def decide_set(client, response: str):
    client.cmd_buff.remove("Set")

def decide_incantation(client, response: str):
    client.cmd_buff.remove("Incantation")
    client.status = 0
    if response == "ko":
        return
    client.level += 1
    print("succesfully leveled up after incantation")

def died(client, response: str):
    client.status = DEAD

def decide_heard(client, response: str):
    check_broadcast_pattern(response, client)

def decide_ejected(client, response: str):
    print("Should make decision after being ejected")
