from client import Client
from commands.movement_commands import *
from commands.object_commands import *
from commands.players_commands import *
import threading

def network_loop(client):
        #response_thread = threading.Thread(target=client.get_response_continuously)
        #response_thread.start()
        
        while True:
            # Handle sending commands here
            print("atempting to send forward command")
            send_forward_command(client)
            send_left_command(client)
            send_right_command(client)
            send_look_command(client)
            send_inventory_command(client)
            send_broadcast_text_command(client)
            break  # Remove this line once sending commands is implemented

        #response_thread.join()
        client.sock.close()
