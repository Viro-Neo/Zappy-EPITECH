##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## get_server_response_for_commands
##

from commands.movement_commands import send_inventory_command
from client import Client
from typing import Dict
from decisions import *
import re

response_dict = {
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

stray_response_dict = {
    'Dead': 'dead',
    'Message': r'message (\d+), (.+)',
    'Ejected': r'eject: [A-Za-z]'
}

action_dict = {
    'Forward': decide_forward,
    'Right': decide_right,
    'Left': decide_left,
    'Look': decide_look,
    'Inventory': decide_inventory,
    'Broadcast text': decide_broadcast,
    'Connect_nbr': decide_connect_nbr,
    'Fork': decide_fork,
    'Eject': decide_eject,
    'Take object': decide_take,
    'Set object': decide_set,
    'Incantation': decide_incantation,
    'Dead': died,
    'Message': decide_heard,
    'Ejected': decide_ejected
}

def check_response(response: str, client: Client):
    for cmd in client.cmd_buff:
        if re.match(response_dict[cmd], response):
            action_dict[cmd](client, response)
            return 1
    for stray in stray_response_dict:
        if re.match(stray_response_dict[stray], response):
            action_dict[stray](client, response)
            return 2
    return 0
