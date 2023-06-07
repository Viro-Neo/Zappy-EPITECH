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
        int readFromServer();
        int writeToServer(std::string msg);
        void connectToServer(void);
        std::string &popCmd();
    protected:
    private:
        sf::TcpSocket _clientSocket;
        sf::Socket::Status status;
        const std::string _port;
        const std::string _host;
        std::vector<std::string> _cmdList;
};



#endif /* !SERVERCOMMUNICATION_HPP_ */
