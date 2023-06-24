##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-aurelien.duval
## File description:
## get_server_response_for_commands
##

from typing import Dict
from commands.decision import decide_broadcast, decide_connect_nbr, decide_eject, decide_ejected, decide_fork, decide_forward, decide_heard, decide_incantation, decide_inventory, decide_left, decide_look, decide_right, decide_set, decide_take, died

response_dict = {
    'Forward': 'ok',
    'Right': 'ok',
    'Left': 'ok',
    'Look': r'\[([^,\[\]]*\s*,\s*)*([^,\[\]]*)\]',
    'Inventory': r"\[([\w\s]+ \d+)(, [\w\s]+ \d+)*\]",
    'Broadcast': 'ok',
    'Connect_nbr': r"\b(?:0|[1-9]\d*)\b",
    'Fork': 'ok',
    'Eject': r'ok|ko',
    'Take': r'ok|ko',
    'Set': r'ok|ko',
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
    'Broadcast': decide_broadcast,
    'Connect_nbr': decide_connect_nbr,
    'Fork': decide_fork,
    'Eject': decide_eject,
    'Take': decide_take,
    'Set': decide_set,
    'Incantation': decide_incantation,
    'Dead': died,
    'Message': decide_heard,
    'Ejected': decide_ejected
}