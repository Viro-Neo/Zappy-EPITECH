from client import Client
import re

def send_take_object_command(client):
    command = "Take object"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")

def send_set_object_command(client):
    command = "Set object"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")

def send_incantation_command(client):
    command = "Incantation"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        pattern = r"Elevation underway\nCurrent level: \d+"
        if re.match(pattern, response):
            client.level += 1
        elif response == "ko":
            pass
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")
