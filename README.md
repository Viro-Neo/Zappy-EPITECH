# Zappy Project Documentation


## Table of Contents
### Introduction
### Project Overview
### Communication between server and AI
### Usage


# Zappy AI

## 1. Introduction
The Zappy project is a multiplayer game developed as part of the curriculum at Epitech. It involves creating a server and multiple clients that interact with each other in a virtual world. The goal of the game is to gather resources and level up in order to win.

This documentation provides an overview of the Zappy project. Three binaries are created, the server, the ai and the GUI:

* A server, created in C, that generates the inhabitants’ world.
* A graphical client, created in C++, that can be used to watch what happens in the world.
* A client, created in python language, that drives an inhabitant through orders sent to the server

## 2. Project Overview

The Zappy project consists of two main components: the server and the client. The server manages the game world, handles client connections, and enforces the game rules. The clients connect to the server, send commands, and receive updates about the game state.

The game world is a grid-based map where players control avatars and perform actions such as moving, gathering resources, and interacting with other players. The server simulates the game world and broadcasts updates to all connected clients.


In the beginning of the game, a team has n slot available (represented on the board by an egg waiting for a client to connect). Each player is driven by a client. The clients cannot communicate or  exchange data outside of the game (no matter what it is it should be
passed via the server). In the beginning, the player has 10 life units, which means they can survive for 1260 time units, or 1260/f seconds.


A player can reproduce thanks to the fork command. The execution of this command leads to the production of an egg. Once it’s layed, the player who has layed it can take care of their business. Once the egg is layed, a new slot is added to the team.


# 3. Communication between server and AI

The dialogue between the ai client and the server is carried out via tcp sockets.
The port that is used must be indicated in parameters.
The client sends its requests, without waiting for them to be done.
The server sends back a message confirming the correct execution of the requests.


# 4. Usage

To connect a client to the server, use the following command:

```./zappy_ai -p <port> -n <team_name> [-h <hostname>]```

Replace the placeholders with the desired values:

<team_name>: The name of the team the client wants to join.
<port>: The port number on which the server is listening.
<hostname> (optional): The hostname or IP address of the server. If not specified, the client will attempt to connect to localhost.

  Client Commands
Once connected, the client can send various commands to the server. Here are the commands:
 
Forward: Move the client's avatar one space forward.
Right: Rotate the client's avatar 90 degrees to the right.
Left: Rotate the client's avatar 90 degrees to the left.
Look: 
Inventory:
Broadcast <message>: Send a message to all other clients.
Connect_nbr:
Fork:
Eject:
Take <resource>: Gather a resource from the current cell.
Set <resource>: Drop a resource onto the current cell.
Incantation: 

  
# Zappy Server
  
  
