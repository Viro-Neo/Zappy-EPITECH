from client import Client
import threading

def send_forward_command(client: Client):
    command = "Forward"
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Forward")
        client.write_response_to_socket(command)

def send_right_command(client: Client):
    command = "Right"
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Right")
        client.write_response_to_socket(command)

def send_left_command(client: Client):
    command = "Left"
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Left")
        client.write_response_to_socket(command)



def process_response(response):
    response_list = [x.strip() for x in response.split(',')]
    response_table = [[item] for item in response_list]
    return response_table

def send_look_command(client: Client):
    command = "Look"
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Look")
        client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        response = client.receive_server_response()
        print("Tile ")
        #else:
        #    response_table = process_response(response)
        #    print(response_table)
    except OSError as e:
        print(f"Error receiving response: {str(e)}")



def send_inventory_command(client: Client):
    command = "Inventory"
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Inventory")
        client.write_response_to_socket(command)



def send_broadcast_text_command(client: Client, text: str):
    command = f"Broadcast {text}"
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Broadcast text")
        client.write_response_to_socket(command)
