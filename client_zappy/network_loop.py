from client import Client
from commands import *
import threading

def network_loop(client):
        #response_thread = threading.Thread(target=client.get_response_continuously)
        #response_thread.start()
        
        while True:
            # Handle sending commands here
            print("atempting to send forward command")
            send_forward_command(client)
            break  # Remove this line once sending commands is implemented

        #response_thread.join()
        client.sock.close()
