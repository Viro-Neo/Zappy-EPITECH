from client import Client
import re

def send_take_object_command(client: Client, object: str):
    command = f"Take {object}"
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Take object")
        client.write_response_to_socket(command)

def send_set_object_command(client: Client, object: str):
    command = f"Set {object}"
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Set object")
        client.write_response_to_socket(command)

def send_incantation_command(client: Client):
    command = "Incantation"
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Incantation")
        client.write_response_to_socket(command)
