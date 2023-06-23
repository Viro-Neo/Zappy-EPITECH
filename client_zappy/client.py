import socket
import threading
import re
from command_response_actions_dict import *

class Client:
    def __init__(self, port, team, machine):
        self.port = port
        self.team = team
        self.machine = machine
        self.sock = None
        self.level = 1
        self.inventory = init_items()
        self.missing = []
        self.cmd_buff = []
        self.direction = []
        self.direction_index = 0
        self.reposition = []
        self.reposition_index = 0
        self.setting_items = init_items()
        self.status = 0
        self.team_items = init_items()

    def connect_to_server(self):
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            server_address = (self.machine, self.port)
            self.sock.connect(server_address)
            print(f"Connected to server {self.machine} on port {self.port}")
        except Exception as e:
            print(f"Error connecting to server: {str(e)}")
            exit(84)

            sock.connect(server_address)
            print(f"connected to server {self.machine} on port {self.port}")
        except:
            print("Can't connect to server. Please try again later.\n")
    
    def get_response_continuously(self):
        try:
            response = self.sock.recv(1024).decode()
            print(f"Got a continuous response : {response}")
            self.check_response(response)
        except Exception as e:
            print(f"Error receiving response: {str(e)}")
    
    def check_response(self, response: str) -> int:
        for cmd in self.cmd_buff:
            if re.match(response_dict[cmd], response):
                action_dict[cmd](self, response)
                return 1
        for stray in stray_response_dict:
            if re.match(stray_response_dict[stray], response):
                action_dict[stray](self, response)
                return 2
        return 0

    def write_response_to_socket(self, response: str):
        try:
            self.sock.send(response.encode())
        except Exception as e:
            print(f"Error sending response: {str(e)}")
            exit(84)

def init_items():
    items = {}
    items["linemate"] = 0
    items["deraumere"] = 0
    items["sibur"] = 0
    items["mendiane"] = 0
    items["phiras"] = 0
    items["thystame"] = 0
    return items