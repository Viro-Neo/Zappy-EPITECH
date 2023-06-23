/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Player
*/

#ifndef PLAYER_HPP_
    #define PLAYER_HPP_
    #include <SFML/Graphics.hpp>

struct Inventory
{
    int FOOD;
    int LINEMATE;
    int DERAUMERE;
    int SIBUR;
    int MENDIANE;
    int PHIRAS;
    int THYSTAME;
};

class Player {
    public:
        Player();
        ~Player();
        int getLevel();
        void setLevel(int lv);
        sf::Vector2u getPos();
        void setPos(sf::Vector2u pos);
        Inventory inventory;
    protected:
    private:
        sf::Vector2u pos;
        int level;
        std::string _teamName;
        bool _incantation;
};

#endif /* !PLAYER_HPP_ */
