import socket

class Client:
    def __init__(self, port, team, machine):
        self.port = port
        self.team = team,
        self.machine = machine

    def connect_to_server(self):
        try:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            server_address = (self.machine, self.port)
            sock.connect(server_address)
            print(f"connected to server {self.machine} on port {self.port}")
        except:
            print("Can't connect to server. Please try again later.\n")
