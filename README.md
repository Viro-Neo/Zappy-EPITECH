# Zappy Project Documentation


## Table of Contents
### Introduction
### Project Overview
### Usage


## 1. Introduction
The Zappy project is a multiplayer game developed as part of the curriculum at Epitech. It involves creating a server and multiple clients that interact with each other in a virtual world. The goal of the game is to gather resources and level up in order to win.

This documentation provides an overview of the Zappy project, including system requirements, installation instructions, and details about the server and client APIs.

## 2. Project Overview
The Zappy project consists of two main components: the server and the client. The server manages the game world, handles client connections, and enforces the game rules. The clients connect to the server, send commands, and receive updates about the game state.

The game world is a grid-based map where players control avatars and perform actions such as moving, gathering resources, and interacting with other players. The server simulates the game world and broadcasts updates to all connected clients.


5. Usage
Starting the Server
To start the server, use the following command:

php
Copy code
./zappy_server -p <port> -x <width> -y <height> -n <team_names> -c <clients_per_team> [-t <time>]
Replace the placeholders with the desired values:

<port>: The port number for the server to listen on.
<width>: The width of the game world.
<height>: The height of the game world.
<team_names>: Comma-separated names of the teams participating in the game.
<clients_per_team>: The number of clients allowed per team.
<time> (optional): The time limit for the game in milliseconds. If not specified, the default value is used.
Connecting Clients
To connect a client to the server, use the following command:

./zappy_ai -n <team_name> -p <port> [-h <hostname>]
Replace the placeholders with the desired values:

<team_name>: The name of the team the client wants to join.
<port>: The port number on which the server is listening.
<hostname> (optional): The hostname or IP address of the server. If not specified, the client will attempt to connect to localhost.
Client Commands
Once connected, the client can send various commands to the server. Some example commands are:

Forward: Move the client's avatar one space forward.
Right: Rotate the client's avatar 90 degrees to the right.
Take <resource>: Gather a resource from the current cell.
Set <resource>: Drop a resource onto the current cell.
Broadcast <message>: Send a message to all other clients.
  
  
  
  To be continued
