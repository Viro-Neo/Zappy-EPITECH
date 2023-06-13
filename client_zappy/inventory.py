from commands.movement_commands import send_inventory_command
from client import Client
from typing import Dict

ritual_needs = {
    1: {
        'players': 1,
        'linemate': 1,
        'deraumere': 0,
        'sibur': 0,
        'mendiane': 0,
        'phiras': 0,
        'thystame': 0
    },
    2: {
        'players': 2,
        'linemate': 1,
        'deraumere': 1,
        'sibur': 1,
        'mendiane': 0,
        'phiras': 0,
        'thystame': 0
    },
    3: {
        'players': 2,
        'linemate': 2,
        'deraumere': 0,
        'sibur': 1,
        'mendiane': 0,
        'phiras': 2,
        'thystame': 0
    },
    4: {
        'players': 4,
        'linemate': 1,
        'deraumere': 1,
        'sibur': 2,
        'mendiane': 0,
        'phiras': 1,
        'thystame': 0
    },
    5: {
        'players': 4,
        'linemate': 1,
        'deraumere': 2,
        'sibur': 1,
        'mendiane': 3,
        'phiras': 0,
        'thystame': 0
    },
    6: {
        'players': 6,
        'linemate': 1,
        'deraumere': 2,
        'sibur': 3,
        'mendiane': 0,
        'phiras': 1,
        'thystame': 0
    },
    7: {
        'players': 6,
        'linemate': 2,
        'deraumere': 2,
        'sibur': 2,
        'mendiane': 2,
        'phiras': 2,
        'thystame': 1
    }
}

def init_inventory() -> Dict[str, int]:
    inventory = {}
    inventory["food"] = 0
    inventory["linemate"] = 0
    inventory["deraumere"] = 0
    inventory["sibur"] = 0
    inventory["mendiane"] = 0
    inventory["phiras"] = 0
    inventory["thystame"] = 0

    return inventory

def get_inventory(client: Client) -> Dict[str, int]:
    # get string describing inventory from server
    inventory_str = send_inventory_command(client)

    # we initialize a dict to store the items
    inventory = init_inventory()

    # we split the string into a list of items and their quantity
    items = inventory_str.split(",")

    # iterate through items in the inventory and add them to the dict
    for item in items:
        item = item.strip()
        item_name, item_quantity = item.split()
        item_quantity = int(item_quantity)
        inventory[item_name] = item_quantity
    
    print(f"player inventory is {inventory}")
    
    return inventory

def check_inventory(client: Client):
    # get the inventory
    inventory = get_inventory(client)

    missing = {}

    # we check if we are missing items for the next levelup
    for item in ritual_needs[client.level]:
        if item == "players":
            continue
        q = ritual_needs[client.level][item]
        if q > inventory[item]:
            missing[item] = q - inventory[item]

    print(f"missing items are {missing}")
    return missing
