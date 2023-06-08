from client import Client
import re

def send_take_object_command(client):
    command = "Take object"
    client.write_response_to_socket(command)

def send_set_object_command(client):
    command = "Set object"
    client.write_response_to_socket(command)

def send_incantation_command(client):
    command = "Incantation"
    client.write_response_to_socket(command)
