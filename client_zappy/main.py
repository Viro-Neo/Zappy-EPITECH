import sys
import getopt
from client import Client

def print_usage():
    print("USAGE:\t./zappy_ai -p port -n name -h machine"
          "\n\tport\tis the port number"
          "\n\tname\tis the name of the team"
          "\n\tmachine\tis the name of the machine; localhost by default")

def main():
    argv = sys.argv[1:]
    port = None
    name = None
    machine = "localhost"

    try:
        opts, args = getopt.getopt(argv, "p:n:h:help")
    except getopt.GetoptError:
        print_usage()
        sys.exit(84)
    
    for opt, arg in opts:
        if opt in ["-help"]:
            print_usage()
            exit(0)
        elif opt in ['-p']:
            port = int(arg)
        elif opt in ['-n']:
            name = arg
        elif opt in ['-h']:
            machine = arg
    if port is None or name is None:
        print_usage()
        sys.exit(84)
    client = Client(port, name, machine)
    client.connect_to_server()
