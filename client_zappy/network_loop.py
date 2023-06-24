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
            #print(f"client status : {client.status}")
            #print(f"missing items : {client.missing}")
            #print(f"inventory : {client.inventory}")
            #print(f"setting items : {client.setting_items}")
            if client.status == DEAD:
                break
            if client.status == SETTING:
                if "Set" not in client.cmd_buff:
                    set_needed_items(client)
                continue
            if client.status == JOINING:
                join_incant()
                continue
            if "Look" not in client.cmd_buff:
                send_look_command(client)
            if "Inventory" not in client.cmd_buff:
                send_inventory_command(client)

        response_thread.join()
        client.sock.close()

def set_needed_items(client: Client):
    if len(client.setting_items) == 0:
        client.status = WAITING
        return
    print(f"setting items : {client.setting_items}")
    while len(client.setting_items) > 0:
        if len(client.cmd_buff) == 10:
            continue
        send_set_object_command(client, client.setting_items[0])
        client.setting_items.pop(0)

def all_items_set(items):
    for item in items:
        if items[item] > 0:
            return False
    return True 

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
