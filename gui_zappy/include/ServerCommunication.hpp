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
class ServerCommunication {
    public:
        ServerCommunication();
        ~ServerCommunication();
        int readFromServer();
        int writeToServer();
    protected:
    private:
        sockaddr_in client_address;
        hostent info;
};



#endif /* !SERVERCOMMUNICATION_HPP_ */
