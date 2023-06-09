from client import Client
import threading

def send_forward_command(client):
    command = "USER"
    client.write_response_to_socket(command)

    try:
        client.lock.acquire()
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")
    finally:
        client.lock.release()


def send_right_command(client):
    command = "Right"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")

def send_left_command(client):
    command = "Left"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")


def process_response(response):
    response_list = [x.strip() for x in response.split(',')]
    response_table = [[item] for item in response_list]
    return response_table

def send_look_command(client):
    command = "Look"
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



def send_inventory_command(client: Client) -> str:
    command = "Inventory"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        pattern = r"Linemate\nLibur \d+"
    except OSError as e:
        print(f"Error receiving response: {str(e)}")


def send_broadcast_text_command(client):
    command = "Broadcast text"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")