#include <iostream>
#include "Game.h"

void Game::init()
{
    parser = InputParser();
    loadAreas();
    std::cout << "Type \"h\" or \"help\" for help." << std::endl;
}

void Game::loadAreas()
{
    areas.emplace_back("start room");
    areas.emplace_back("room 1");
    areas.emplace_back("room 2");
    areas.emplace_back("room 3");
    areas.emplace_back("room 4");
    areas.emplace_back("room 5");
    areas.emplace_back("room 6");
}

void Game::run()
{
    while(!step()){}
}

bool Game::step()
{
    std::string input;
    cin >> input;
    switch (parser.parseInput(input)) {
        case GO_NORTH:
            std::cout << "going north\n";
            break;
        case GO_EAST:
            std::cout << "going east\n";
            break;
        case GO_SOUTH:
        std::cout << "going south\n";
            break;
        case GO_WEST:
        std::cout << "going west\n";
            break;
        case HELP:
            std::cout << "type \"n\" or \"north\" to go north,\n";
            std::cout << "type \"e\" or \"east\" to go east,\n";
            std::cout << "type \"s\" or \"south\" to go south,\n";
            std::cout << "type \"w\" or \"west\" to go west,\n";
            break;
        default:
        std::cout << "Incorrect input! Type \"h\" or \"help\" for help." << std::endl;
    }
    return false;
}
