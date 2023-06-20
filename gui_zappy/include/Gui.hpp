/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** Gui.hpp
*/

#ifndef B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP
    #define B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP

    #include <exception>
    #include <iostream>

class Gui {
    public:
        Gui() = default;
        Gui(int ac, char **av);
        ~Gui() = default;
        static void printUsage();

        std::string getPort() const;
        std::string getHost() const;

    private:
        std::string _port;
        std::string _host;
};

#endif //B_YEP_400_PAR_4_1_ZAPPY_AURELIEN_DUVAL_GUI_HPP
