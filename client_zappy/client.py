import socket
import threading

class Client:
    def __init__(self, port, team, machine):
        self.port = port
        self.team = team,
        self.machine = machine

    def connect_to_server(self):
        try:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock = sock
            server_address = (self.machine, self.port)
            sock.connect(server_address)
            print(f"connected to server {self.machine} on port {self.port}")
        except:
            print("Can't connect to server. Please try again later.\n")
    
    def receive_server_response(self):
        while True:
            response = self.sock.recv(1024).decode()
            print(f"Server response is : {response}") # should be replaced by response handling
    
    def networkLoop(self):
        responseThread = threading.Thread(target=self.receive_server_response)
        responseThread.start()
        while True:
            break #should be removed when sending command is implemented
            # handle sending command
        responseThread.join()
        self.sock.close()
