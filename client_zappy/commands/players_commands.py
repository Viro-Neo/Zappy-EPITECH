from client import Client

def send_connect_nbr_command(client):
    command = "Connect_nbr"
    client.write_response_to_socket(command)

def send_fork_command(client):
    command = "Fork"
    client.write_response_to_socket(command)

def send_eject_command(client):
    command = "Eject"
    client.write_response_to_socket(command)
