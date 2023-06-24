/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Incantation
*/

#ifndef INCANTATION_HPP_
#define INCANTATION_HPP_
    #include <SFML/Graphics.hpp>
    #include <vector>
    #include <Player.hpp>
class Incantation {
    public:
        Incantation(int level, sf::Vector2u pos, Player starter, std::vector<Player> participent);
        ~Incantation();
    protected:
    private:
        int _level;
        sf::Vector2u _pos;
        Player _starter;
        std::vector<Player> _participent;
};

#endif /* !INCANTATION_HPP_ */
