from client import Client

def send_forward_command(client):
    command = "USER "
    client.write_response_to_socket(command)

    try:
        response = client.receive_server_response()
        if response == "ok" or response == "ko":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")
