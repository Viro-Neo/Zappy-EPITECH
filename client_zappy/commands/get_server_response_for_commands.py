##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## get_server_response_for_commands
##

from commands.movement_commands import send_inventory_command
from client import Client
from typing import Dict
import re

command_dict = {
    'Forward': 'ok',
    'Right': 'ok',
    'Left': 'ok',
    'Look': r'\[([^,\[\]]*\s*,\s*)*([^,\[\]]*)\]',
    'Inventory': r"\[([\w\s]+ \d+)(, [\w\s]+ \d+)*\]",
    'Broadcast text': 'ok',
    'Connect_nbr': r"\b(?:0|[1-9]\d*)\b",
    'Fork': 'ok',
    'Eject': r'ok|ko',
    'Take object': r'ok|ko',
    'Set object': r'ok|ko',
    'Incantation': r'Elevation underway Current level: [1-7]|ko'
}

def check_response(response: str, client: Client):
    if response == "dead":
        print("response was dead, should die!")
        return "dead"
    for cmd in client.cmd_buff:
        if re.match(command_dict[cmd], response):
            print(f"correct response {response} to command {cmd}")
            return "good"
    print("response is not linked to any queued command")
    return "invalid"
