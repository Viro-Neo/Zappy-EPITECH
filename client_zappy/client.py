import socket
import threading

class Client:
    def __init__(self, port, team, machine):
        self.port = port
        self.team = team
        self.machine = machine
        self.sock = None

    def connect_to_server(self):
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            server_address = (self.machine, self.port)
            self.sock.connect(server_address)
            print(f"Connected to server {self.machine} on port {self.port}")
        except Exception as e:
            print(f"Error connecting to server: {str(e)}")
            exit(84)

    def receive_server_response(self):
        while True:
            try:
                response = self.sock.recv(1024).decode()
                print(f"Server response: {response}")
                # Handle response here
            except Exception as e:
                print(f"Error receiving response: {str(e)}")
                break

    def network_loop(self):
        response_thread = threading.Thread(target=self.receive_server_response)
        response_thread.start()
        
        while True:
            # Handle sending commands here
            break  # Remove this line once sending commands is implemented

        response_thread.join()
        self.sock.close()

    def write_response_to_socket(self, response):
        try:
            self.sock.send(response.encode())
            print("Response sent successfully.")
        except Exception as e:
            print(f"Error sending response: {str(e)}")
            exit(84)