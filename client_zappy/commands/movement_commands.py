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


def send_look_command(client):
    command = "Look"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            nested_list = [[item.strip()] if item.strip() else [] for item in response.split(',')]
        #    print(nested_list) -> Parsed output, remove it at the end
    except OSError as e:
        print(f"Error receiving response: {str(e)}")


def send_inventory_command(client: Client) -> str:
    command = "Inventory"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            return response
        else:
            print(f"Unknown server response: {response}")
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