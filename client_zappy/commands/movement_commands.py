from client import Client
import threading

def send_forward_command(client):
    command = "Forward"
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

def send_look_command(client: Client):
    command = "Look"
    client.write_response_to_socket(command)

    try:
        response = "stone, stone, item,,,,,,,"  # client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            response_list = [x.strip() for x in response.split(',')]
            print(response_list)
            nearest_food = None
            nearest_distance = float('inf')
            starting_position = response_list.index("stone")

            print("I go forward first of all")
            send_forward_command(client)

            for index, tile in enumerate(response_list):
                if tile in client.missing:
                    distance = abs(starting_position - index)
                    if distance < nearest_distance:
                        nearest_food = index
                        nearest_distance = distance

            if nearest_food is not None:
                if nearest_food < starting_position:
                    send_left_command(client)
                    print("I go left")
                elif nearest_food > starting_position:
                    send_forward_command(client)
                    print("I go forward")
                else:
                    print("I go right")
                    send_right_command(client)

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