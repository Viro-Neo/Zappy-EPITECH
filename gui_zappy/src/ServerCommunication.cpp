/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ServerCommunication
*/

#include "ServerCommunication.hpp"


ServerCommunication::ServerCommunication(const std::string port, const std::string host) : _port(port), _host(host), _info(HostentByName(host))
{
    this->_client_socket = socket(AF_INET, SOCK_STREAM, 0);
    this->_client_address.sin_addr.s_addr = inet_addr(host.data());
    this->_client_address.sin_family = AF_INET;
    this->_client_address.sin_port = htons(atoi(port.data()));
    // TODO(zach & vando): make logs
}


ServerCommunication::~ServerCommunication()
{
    close(this->_client_socket);
}

void ServerCommunication::connectToServer(void)
{
    if (connect(this->_client_socket, (struct sockaddr *)&this->_client_address, sizeof(_client_address)) == -1)
        throw std::exception(); //TODO(zach): make error handling 
    //else
    //  TODO(zach & vando): make logs
}

void ServerCommunication::selectHandler(void)
{
    FD_ZERO(&this->_fdset);
    FD_SET(STDIN_FILENO, &this->_fdset);
    FD_SET(this->_client_socket, &this->_fdset);
    if (select(this->_client_socket + 1, &this->_fdset, nullptr, nullptr, nullptr) == -1 && errno != EINTR)
        throw std::exception(); //TODO(zach): make error handling
}

bool ServerCommunication::isRead()
{
    if (FD_ISSET(STDIN_FILENO, &this->_fdset))
        return false;
    else if (FD_ISSET(this->_client_socket, &this->_fdset))
        return true;
}

int ServerCommunication::readFromServer()
{
    char msg[4096];
    int status = recv(this->_client_socket, msg, 4096, 0);
    if (status = 0) {
        this->~ServerCommunication();
        throw std::exception(); //TODO(zach): make error handling
    }
    if (status = -1) { 
        throw std::exception(); //TODO(zach): make error handling
    }
    std::string result = msg;
    int size = 0;
    while (result != "" || result.find('\n') == std::string::npos) {
        int index = result.find('\n', size);
        this->_cmdList.push_back(result.substr(size, index - 1));
        size = index + 1;
    }
}

int ServerCommunication::writeToServer()
{
    char msg[1024] = {0};
    read(STDIN_FILENO, msg, 1024 - 1);

    write(this->_client_socket, msg, 1024);
    return 0;
}


