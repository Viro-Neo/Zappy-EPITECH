from client import Client
from commands.movement_commands import *
from commands.object_commands import *
from commands.players_commands import *
import threading

def network_loop(client):
        #response_thread = threading.Thread(target=client.get_response_continuously)
        #response_thread.start()
        
        while True:
            if client.status == SETTING:
                set_needed_items()
                continue
            if client.status == JOINING:
                join_incant()
                continue
            send_look_command()
            send_inventory_command()

        #response_thread.join()
        client.sock.close()
