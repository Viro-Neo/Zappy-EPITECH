/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ServerCommunication
*/


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
    #include "HostentByName.hpp"
    #include <vector>
class ServerCommunication {
    public:
        ServerCommunication(std::string port, std::string host);
        ~ServerCommunication();
        int readFromServer();
        int writeToServer();
        void connectToServer(void);
        void selectHandler(void);
        //return true if u need to read 0 if not
        bool isRead();
    protected:
    private:
        struct sockaddr_in _client_address;
        HostentByName _info;
        int _client_socket;  
        const std::string _port;
        const std::string _host;
        fd_set _fdset;
        std::vector<std::string> _cmdList;
};



#endif /* !SERVERCOMMUNICATION_HPP_ */
