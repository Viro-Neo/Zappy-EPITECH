/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Gui.cpp
*/

#include "Gui.hpp"

Gui::Gui(int ac, char **av)
{
    if (ac == 2 && std::string(av[1]) == "-help")
        throw std::invalid_argument("Help");
    GetOpt getOpt(ac, av);
    _port = getOpt.getPort();
    _host = getOpt.getHost();
    _comm.setHost(_host);
    _comm.setPort(_port);
    std::cout << "Port: " << _port << std::endl;
    std::cout << "Host: " << _host << std::endl;
}

void Gui::printUsage()
{
    std::cout << "USAGE: ./zappy_gui -p port -h machine" << std::endl;
    std::cout << "\tport\tis the port number" << std::endl;
    std::cout << "\tmachine\tis the name of the machine; localhost by default" << std::endl;
}

void Gui::initGui()
{
    try {
        this->_comm.connectToServer(); 
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    this->_comm.writeToServer("msz\n");
    sleep(2);
    this->_comm.readFromServer();
    std::string mapSize = this->_comm.popCmd();
    printf("mapSize is %s\n", mapSize.data());
}

std::string Gui::getPort() const
{
    return _port;
}

std::string Gui::getHost() const
{
    return _host;
}
