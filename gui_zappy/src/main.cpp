/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** main
*/

#include "Gui.hpp"

int main(int ac, char **av)
{
   try {
       Gui gui(ac, av);
   } catch (const std::exception &e) {
       std::cerr << e.what() << std::endl;
       Gui::printUsage();
       return 84;
   }
}
