/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GetOpt.cpp
*/

#include "GetOpt.hpp"

GetOpt::GetOpt(int ac, char **av)
{
    int opt = 0;

    while ((opt = getopt(ac, av, "p:h:")) != -1) {
        switch (opt) {
            case 'p':
                _port = optarg;
                break;
            case 'h':
                _host = optarg;
                break;
            default:
                Gui::printUsage();
                throw std::invalid_argument("No argument found");
        }
    }
    if (_port.empty() || _host.empty()) {
        Gui::printUsage();
        throw std::invalid_argument("Argument missing");
    }
}

std::string GetOpt::getPort() const
{
    return _port;
}

std::string GetOpt::getHost() const
{
    return _host;
}
