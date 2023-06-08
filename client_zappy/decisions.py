from inventory import check_inventory

def decide_forward(client, response: str):
    pass

def decide_right(client, response: str):
    pass

def decide_left(client, response: str):
    pass

def decide_look(client, response: str):
    print("Should make decisions based on what I see")

def decide_inventory(client, response: str):
    check_inventory(client, response)
    print("Should make decision based on inventory")

def decide_broadcast(client, response: str):
    pass

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
