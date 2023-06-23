/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Gui.hpp
*/

#ifndef B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP
    #define B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP

    #include <exception>
    #include <Map.hpp>
    #include <SFML/Graphics.hpp>
    #include "GetOpt.hpp"
    #include "ServerCommunication.hpp"
    #include <iostream>
    #include <unistd.h>
    #include <memory>
    #include <list>

class Gui {
    public:
        Gui() = default;
        Gui(int ac, char **av);
        ~Gui() = default;
        void initGui();
        void guiLoop();
        std::string getPort() const;
        std::string getHost() const;


    private:
        void eventHandler();
        std::string _port;
        std::string _host;
        ServerCommunication _comm;
        sf::RenderWindow _win;
        Map _map;
};

void msz(std::list<std::string> argList, Map &myMap);

#endif //B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP
