#include <iostream>
#include "../headers/Game.h"

void Game::init()
{
    loadAreas();
    cout << "Type \"h\" or \"help\" for help." << endl;
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
    // Player input
    string input;
    getline(cin, input);

    // Handle input
    handleInput(input);

    // Update screen

    return true;
}

void Game::handleInput(string &input) {
    switch (Parser::parseInput(input)) {
        case HELP:
            cout << "Help screen." << endl;
            break;
        case GO_NORTH:
            cout << "Going north." << endl;
            break;
        case GO_EAST:
            cout << "Going east." << endl;
            break;
        case GO_SOUTH:
            cout << "Going south." << endl;
            break;
        case GO_WEST:
            cout << "Going west." << endl;
            break;
        default:
            cout << "Type \"h\" or \"help\" for help." << endl;
    }
}
