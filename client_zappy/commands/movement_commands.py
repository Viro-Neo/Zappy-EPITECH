import threading

def send_forward_command(client):
    command = "Forward"
    client.write_response_to_socket(command)


def send_right_command(client):
    command = "Right"
    client.write_response_to_socket(command)

def send_left_command(client):
    command = "Left"
    client.write_response_to_socket(command)


def process_response(response):
    response_list = [x.strip() for x in response.split(',')]
    response_table = [[item] for item in response_list]
    return response_table

def send_look_command(client):
    command = "Look"
    client.write_response_to_socket(command)


def send_inventory_command(client) -> str:
    command = "Inventory"
    client.write_response_to_socket(command)

def send_broadcast_text_command(client):
    command = "Broadcast text"
    client.write_response_to_socket(command)