/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** FunctionManager.cpp
*/

#include "FunctionManager.hpp"

FunctionManager::FunctionManager()
{
    _fct["msz"] = &msz;
    _fct["bct"] = &bct;
    _fct["tna"] = &tna;
    _fct["pnw"] = &pnw;
    _fct["ppo"] = &ppo;
    _fct["plv"] = &plv;
    _fct["pin"] = &pin;
    _fct["pex"] = &pex;
    _fct["pbc"] = &pbc;
    _fct["pic"] = &pic;
    _fct["pie"] = &pie;
    _fct["pfk"] = &pfk;
    _fct["pdr"] = &pdr;
    _fct["pgt"] = &pgt;
    _fct["pdi"] = &pdi;
    _fct["enw"] = &enw;
    _fct["ebo"] = &ebo;
    _fct["edi"] = &edi;
    _fct["sgt"] = &sgt;
    _fct["seg"] = &seg;
    _fct["smg"] = &smg;
    _fct["suc"] = &suc;
    _fct["sbp"] = &sbp;
}

void FunctionManager::callFunction(std::string command, Map &myMap)
{
    std::list<std::string> arguments;
    ParseServerCommands parser;

    if (command.empty())
        return;
    parser.parseCommand(command);
    _fct[arguments.front()](arguments, myMap);
}

std::map<std::string, void (*)(std::list<std::string> arg, Map &myMap)> FunctionManager::getFct() const
{
    return _fct;
}

void FunctionManager::setFct(const std::map<std::string, void (*)(std::list<std::string> arg, Map &myMap)> &fct)
{
    _fct = fct;
}

void FunctionManager::msz(std::list<std::string> arg, Map &myMap) // msz x y
{
    if (arg.size() != 2)
        return;
    int width = std::stoi(arg.front());
    arg.pop_front();
    int height = std::stoi(arg.front());
    myMap.resizeMap(width, height);
    myMap.updateTexture();
}

void FunctionManager::bct(std::list<std::string> arg, Map &myMap) // bct x y q0 q1 q2 q3 q4 q5 q6 (also looped for each tile if needed)
{
    if (arg.size() != 9)
        return;
    Tile t;
    t.x = std::stoi(arg.front());
    arg.pop_front();
    t.y = std::stoi(arg.front());
    arg.pop_front();
    t.FOOD = std::stoi(arg.front());
    arg.pop_front();
    t.LINEMATE = std::stoi(arg.front());
    arg.pop_front();
    t.DERAUMERE = std::stoi(arg.front());
    arg.pop_front();
    t.SIBUR = std::stoi(arg.front());
    arg.pop_front();
    t.MENDIANE = std::stoi(arg.front());
    arg.pop_front();
    t.PHIRAS = std::stoi(arg.front());
    arg.pop_front();
    t.THYSTAME = std::stoi(arg.front());
    myMap.setTile(t);
}

void FunctionManager::tna(std::list<std::string> arg, Map &myMap) // tna N (looped for each team)
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::pnw(std::list<std::string> arg, Map &myMap) // pnw #n X Y O L N
{
    if (arg.size() != 6)
        return;
}

void FunctionManager::ppo(std::list<std::string> arg, Map &myMap) // ppo #n X Y O
{
    if (arg.size() != 4)
        return;
}

void FunctionManager::plv(std::list<std::string> arg, Map &myMap) // plv #n L
{
    if (arg.size() != 2)
        return;
}

void FunctionManager::pin(std::list<std::string> arg, Map &myMap) // pin #n X Y q0 q1 q2 q3 q4 q5 q6
{
    if (arg.size() != 10)
        return;
}

void FunctionManager::pex(std::list<std::string> arg, Map &myMap) // pex #n
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::pbc(std::list<std::string> arg, Map &myMap) // pbc #n M
{
    if (arg.size() != 2)
        return;
}

void FunctionManager::pic(std::list<std::string> arg, Map &myMap) // pic X Y L #n #n #n (looped for each player in the tile)
{
    if (arg.size() != 5)
        return;
}

void FunctionManager::pie(std::list<std::string> arg, Map &myMap) // pie X Y R (1 if win, 0 if loose)
{
    if (arg.size() != 3)
        return;
}

void FunctionManager::pfk(std::list<std::string> arg, Map &myMap) // pfk #n
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::pdr(std::list<std::string> arg, Map &myMap) // pdr #n R
{
    if (arg.size() != 2)
        return;
}

void FunctionManager::pgt(std::list<std::string> arg, Map &myMap) // pgt #n R
{
    if (arg.size() != 2)
        return;
}

void FunctionManager::pdi(std::list<std::string> arg, Map &myMap) // pdi #n
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::enw(std::list<std::string> arg, Map &myMap) // enw #e #n X Y
{
    if (arg.size() != 4)
        return;
}

void FunctionManager::ebo(std::list<std::string> arg, Map &myMap) // ebo #e
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::edi(std::list<std::string> arg, Map &myMap) // edi #e
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::sgt(std::list<std::string> arg, Map &myMap) // sgt T
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::seg(std::list<std::string> arg, Map &myMap) // seg N
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::smg(std::list<std::string> arg, Map &myMap) // smg M
{
    if (arg.size() != 1)
        return;
}

void FunctionManager::suc(std::list<std::string> arg, Map &myMap) // suc
{
    if (!arg.empty())
        return;
}

void FunctionManager::sbp(std::list<std::string> arg, Map &myMap) // sbp
{
    if (!arg.empty())
        return;
}
