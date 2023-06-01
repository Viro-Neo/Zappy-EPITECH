from client import Client

def send_connect_nbr_command(client):
    command = "Connect_nbr"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response.isnumeric():
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")

def send_fork_command(client):
    command = "Fork"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")

def send_eject_command(client):
    command = "Eject"
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")
