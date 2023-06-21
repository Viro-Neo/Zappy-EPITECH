from inventory import check_inventory
from inventory import ritual_needs
from broadcast import check_broadcast_pattern
from commands.movement_commands import *

def decide_forward(client, response: str):
    pass

def decide_right(client, response: str):
    pass

def decide_left(client, response: str):
    pass

def decide_look(client, response: str):
    response = "stone, stone, item,,,,,,,"  # client.receive_server_response()
    response_list = [x.strip() for x in response.split(',')]
    print(response_list)
    nearest_food = None
    nearest_distance = float('inf')
    starting_position = response_list.index("stone")
    print("I go forward first of all")
    send_forward_command(client)
    for index, tile in enumerate(response_list):
        if tile in client.missing:
            distance = abs(starting_position - index)
            if distance < nearest_distance:
                nearest_food = index
                nearest_distance = distance
    if nearest_food is not None:
        if nearest_food < starting_position:
            send_left_command(client)
            print("I go left")
        elif nearest_food > starting_position:
            send_forward_command(client)
            print("I go forward")
        else:
            print("I go right")
            send_right_command(client)

def decide_inventory(client, response: str):
    client.missing = check_inventory(client, response)
    

def decide_broadcast(client, response: str):
    check_broadcast_pattern(response, client)

def decide_connect_nbr(client, response: str):
    pass

def decide_fork(client, response: str):
    pass

def decide_eject(client, response: str):
    pass

def decide_take(client, response: str):
    pass

def decide_set(client, response: str):
    pass

def decide_incantation(client, response: str):
    pass

def died(client, response: str):
    pass

def decide_heard(client, response: str):
    print("Should make decision based on what i heard")

def decide_ejected(client, response: str):
    print("Should make decision after being ejected")