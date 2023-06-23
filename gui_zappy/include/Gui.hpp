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
    #include "FunctionManager.hpp"
    #include <iostream>
    #include <unistd.h>
    #include <memory>
    #include "FunctionManager.hpp"
    #include <list>

class Gui {
    public:
        Gui() = default;
        Gui(int ac, char **av);
        ~Gui() = default;
        static void printUsage();
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
        FunctionManager _cmdHandler;
        Map _map;
        struct Tile _tileClicked;
        bool _interfaceOn;
};


#endif //B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP
