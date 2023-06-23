from client import Client
from commands.movement_commands import *
from commands.object_commands import *
from commands.players_commands import *
from commands.status import *
import threading

def network_loop(client: Client):
        response_thread = threading.Thread(target=client.get_response_continuously)
        response_thread.start()
        
        while True:
            if client.status == SETTING:
                set_needed_items()
                continue
            if client.status == JOINING:
                join_incant()
                continue
            send_look_command()
            send_inventory_command()

        response_thread.join()
        client.sock.close()

def set_needed_items(client: Client):
    if len(client.setting_items) == 0:
        client.status = WAITING
        return
    while len(client.cmd_buff) < 10:
        for item in client.setting_items:
            for i in range (client.setting_items[item]):
                if len(client.cmd_buff) == 10:
                    break
                send_set_object_command(client, item)
                client.setting_items[item] -= 1

def join_incant(client: Client):
    while len(client.cmd_buff) < 10:
        if len(client.reposition) > 0:
            if client.reposition[0] == "Left":
                send_left_command(client)
                client.reposition.pop(0)
            else:
                send_right_command(client)
                client.reposition.pop(0)
            continue
        if client.direction[client.direction_index] == "Forward":
            send_forward_command(client)
        elif client.direction[client.direction_index] == "Left":
            send_left_command(client)
        else:
            send_right_command(client)
        client.direction_index = client.direction_index % len(client.direction)
