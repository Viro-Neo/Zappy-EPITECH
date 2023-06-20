/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ServerCommunication
*/

//changer utiliser les SCOKET DE LA SFML SALE CON
#ifndef SERVERCOMMUNICATION_HPP_
#define SERVERCOMMUNICATION_HPP_
    #include <signal.h>
    #include <errno.h>
    #include <netdb.h>
    #include <string>
    #include <memory>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <SFML/Network.hpp>
    #include "HostentByName.hpp"
    #include <vector>
class ServerCommunication {
    public:
        ServerCommunication(std::string port, std::string host);
        ~ServerCommunication();
        // read the data sent by the server using sfml socket.
        int readFromServer();
        // write the data inside the string msg on the socket so the server can read it using sfml sockets.
        int writeToServer(std::string msg);
        // As the name suggest when you call this function it will connect to the server with the port and host set in the constructor
        void connectToServer(void);
        // It gives you the first command reiceved from the server and it will pop it from the vector. The function will return an empty string if there is no more command.
        std::string popCmd();
    protected:
    private:
        sf::TcpSocket _clientSocket;
        sf::Socket::Status status;
        const std::string _port;
        const std::string _host;
        std::vector<std::string> _cmdList;
};



#endif /* !SERVERCOMMUNICATION_HPP_ */
