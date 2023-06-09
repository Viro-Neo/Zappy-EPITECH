import socket
import threading

class Client:
    def __init__(self, port, team, machine):
        self.port = port
        self.team = team
        self.machine = machine
        self.sock = None
        self.lock = threading.Lock()

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
    def receive_server_response(self):
        while True:
            try:
                response = self.sock.recv(1024).decode()
                print(f"Server response: {response}", end = '')
                return response
                # Handle response here
            except:
                pass
    
    def get_response_continuously(self):
        while True:
            try:
                self.lock.acquire()
                response = self.receive_server_response()
                print("Got a continuous response")
            except Exception as e:
                print(f"Error receiving response: {str(e)}")
                break
            finally:
                self.lock.release()

    def write_response_to_socket(self, response):
        try:
            self.sock.send(response.encode())
            print("Response sent successfully.")
        except Exception as e:
            print(f"Error sending response: {str(e)}")
            exit(84)
