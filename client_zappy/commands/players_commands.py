
def send_connect_nbr_command(client):
    command = "Connect_nbr"
    
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Connect_nbr")
        client.write_response_to_socket(command)

def send_fork_command(client):
    command = "Fork"
    
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Fork")
        client.write_response_to_socket(command)

def send_eject_command(client):
    command = "Eject"
    
    if len(client.cmd_buff) < 10:
        client.cmd_buff.append("Eject")
        client.write_response_to_socket(command)
