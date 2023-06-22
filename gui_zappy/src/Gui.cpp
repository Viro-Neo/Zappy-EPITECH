/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Gui.cpp
*/

#include "Gui.hpp"

Gui::Gui(int ac, char **av) : _win(sf::VideoMode(1300, 600), "Zappy")
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
    this->_comm.readFromServer();
    std::string mapSize = this->_comm.popCmd();
    while (mapSize != "" && mapSize.substr(0, 3) != "msz")
    {
        mapSize = this->_comm.popCmd();
    }
    int firstArg = mapSize.find(' ') + 1;
    int width = atoi( mapSize.substr(firstArg, mapSize.find(' ', firstArg) - firstArg).data());
    int secondArg = mapSize.find(' ', firstArg) + 1;
    int height = atoi(mapSize.substr(secondArg, mapSize.find(' ', secondArg) - secondArg).data());
    this->_map.resizeMap(10, 10);
    this->_map.updateTexture();
}

void Gui::guiLoop()
{
    while (this->_win.isOpen()) {
        sf::Event event;
        while (this->_win.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                this->_win.close();
        }
        this->_win.clear(sf::Color::Black);

        this->_win.draw(this->_map);

        this->_win.display();
    }
}

std::string Gui::getPort() const
{
    return _port;
}

std::string Gui::getHost() const
{
    return _host;
}
