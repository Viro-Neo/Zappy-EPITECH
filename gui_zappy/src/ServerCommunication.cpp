/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** ServerCommunication
*/

#include "ServerCommunication.hpp"


ServerCommunication::ServerCommunication(const std::string port, const std::string host) : _port(port), _host(host)
{
}


ServerCommunication::~ServerCommunication()
{
}

void ServerCommunication::connectToServer(void)
{
    this->status = this->_clientSocket.connect(this->_host, std::atoi(this->_port.data()));
    if (this->status != sf::Socket::Done) {
        throw std::exception(); //TODO(zach) : do error handling
    }
    this->writeToServer("GRAPHIC\n");
}

std::string ServerCommunication::popCmd()
{
    if (this->_cmdList.empty())
        return "";
    std::string cmd = this->_cmdList.back();
    this->_cmdList.pop_back();
    return cmd;
}

int ServerCommunication::readFromServer()
{
    char msg[4096] = "";
    std::string result;
    std::size_t received;

    if (this->_clientSocket.receive(msg, 4096, received) != sf::Socket::Done) {
        throw std::exception(); //TODO(zach): do error  handling
    }
    result = msg;
    int size = 0;
    while (result != "" || result.find('\n') == std::string::npos) {
        int index = result.find('\n', size);
        this->_cmdList.push_back(result.substr(size, index - 1));
        size = index + 1;
    }
}

int ServerCommunication::writeToServer(std::string cmd)
{
    if (this->_clientSocket.send(cmd.data(), 100) != sf::Socket::Done)
        throw std::exception(); //TODO(zach): do error handling
}
