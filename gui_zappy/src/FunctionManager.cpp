/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-aurelien.duval
** File description:
** FunctionManager.cpp
*/

#include "FunctionManager.hpp"

FunctionManager::FunctionManager()
{
    _fct["msz"] = &Map::setMapSize;
    _fct["bct"] = &Map::setTileContent;
    _fct["tna"] = &Map::setTeamName;
    _fct["pnw"] = &Map::addPlayer;
    _fct["ppo"] = &Map::setPlayerPosition;
    _fct["plv"] = &Map::setPlayerLevel;
    _fct["pin"] = &Map::setPlayerInventory;
    _fct["pex"] = &Map::playerExpulse;
    _fct["pbc"] = &Map::playerBroadcast;
    _fct["pic"] = &Map::playerIncantation;
    _fct["pie"] = &Map::playerIncantationEnd;
    _fct["pfk"] = &Map::playerFork;
    _fct["pdr"] = &Map::playerDropRessource;
    _fct["pgt"] = &Map::playerTakeRessource;
    _fct["pdi"] = &Map::playerDie;
    _fct["enw"] = &Map::eggLaying;
    _fct["eht"] = &Map::eggHatching;
    _fct["ebo"] = &Map::eggBroken;
    _fct["edi"] = &Map::eggDie;
    _fct["sgt"] = &Map::setTimeUnit;
    _fct["seg"] = &Map::endGame;
    _fct["smg"] = &Map::serverMessage;
    _fct["suc"] = &Map::unknownCommand;
    _fct["sbp"] = &Map::badParameter;
}

void FunctionManager::callFunction(std::string command, Map myMap)
{
    std::list<std::string> arguments;
    ParseServerCommands parser;

    if (command.empty())
        return;
    parser.parseCommand(command);
    _fct[arguments.front()](arguments, myMap);
}

std::map<std::string, void (*)(std::list<std::string> arg, Map myMap)> FunctionManager::getFct() const
{
    return _fct;
}

void FunctionManager::setFct(const std::map<std::string, void (*)(std::list<std::string> arg, Map myMap)> &fct)
{
    _fct = fct;
}
