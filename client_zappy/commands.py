def send_forward_command(client):
    command = "Forward"
    client.write_response_to_socket(command)

    try:
        response = client.sock.recv(1024).decode()
        if response == "ok" or response == "ko":
            print(response)
        else:
            print(f"Unknown server response: {response}")
    except OSError as e:
        print(f"Error receiving response: {str(e)}")
