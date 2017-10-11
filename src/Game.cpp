#include <iostream>
#include "../headers/Game.h"

void Game::init()
{
    loadAreas();
    loadRooms();
    player.setCurrentRoom(*firstRoom);
    (*firstRoom).printRoom();

    cout << "Type \"h\" or \"help\" for help." << endl;
}

void Game::loadAreas()
{
    areas.emplace_back(Area("Starting room"));
    areas.emplace_back(Area("second room"));
    areas.emplace_back(Area("ending room"));
}

void Game::loadRooms() {
    rooms.emplace_back(Room(areas[0]));
    rooms.emplace_back(Room(areas[1]));
    rooms.emplace_back(Room(areas[2]));

    rooms[0].setNorthernRoom(rooms[1]);

    rooms[1].setSouthernRoom(rooms[0]);
    rooms[1].setNorthernRoom(rooms[2]);

    rooms[2].setSouthernRoom(rooms[1]);

    firstRoom = &rooms[0];
    lastRoom = &rooms[2];

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
    player.getCurrentRoom().printRoom();

    return player.getCurrentRoomPointer() == lastRoom;

    return false;
}

void Game::handleInput(string &input) {
    InputType convInput = Parser::parseInput(input);
    switch (convInput) {
        case HELP:
            cout << "\tMove to north, type: 'n' or 'north'.\n"
                    "\tMove to south, type: 's' or 'south'.\n"
                    "\tMove to west, type: 'w' or 'west'.\n"
                    "\tMove to east, type: 'e' or 'east'.\n"
                    "\tPick up items, type: 'p' or 'pick'." << endl;
            break;
        case GO_NORTH:
            player.move(GO_NORTH);
            break;
        case GO_EAST:
            player.move(GO_EAST);
            break;
        case GO_SOUTH:
            player.move(GO_SOUTH);
            break;
        case GO_WEST:
            player.move(GO_WEST);
            break;
        default:
            cout << "Type \"h\" or \"help\" for help." << endl;
    }
}
