#include <iostream>
#include "../headers/Game.h"

void Game::init()
{
    loadAreas();
    loadItemWeights();
    loadItemNames();
    loadRooms();
    cout << "\nType \"h\" or \"help\" for help.\n\n";
    player.setCurrentRoom(*firstRoom);
    (*firstRoom).printRoom();

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
    rooms[0].placeItem(Item(itemNames[1], itemWeights[1]));
    rooms[0].placeItem(Item(itemNames[0], itemWeights[0]));

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
}

void Game::handleInput(string &input) {
    switch (Parser::parseInput(input)) {
        case HELP:
            cout << "\tMove to north, type: 'n' or 'north'.\n"
                    "\tMove to south, type: 's' or 'south'.\n"
                    "\tMove to west, type: 'w' or 'west'.\n"
                    "\tMove to east, type: 'e' or 'east'.\n"
                    "\tPick up items, type: 'p' or 'pick'.\n"
                    "\tDrop items, type: 'd' or 'drop'.\n" << endl;
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
        case PICK_UP_ITEM:
            player.pickUpItems();
            break;
        case DROP_ITEM:
            player.dropItem();
            break;
        default:
            cout << "\nType \"h\" or \"help\" for help.\n\n";
    }
}


void Game::loadItemNames() {
    itemNames.emplace_back(ItemName("Golden key"));
    itemNames.emplace_back(ItemName("Silver key"));
    itemNames.emplace_back(ItemName("Leather chestplate"));
    itemNames.emplace_back(ItemName("Leather boots"));
    itemNames.emplace_back(ItemName("Leather gloves"));
    itemNames.emplace_back(ItemName("Leather legplate"));
    itemNames.emplace_back(ItemName("Leather hat"));
    itemNames.emplace_back(ItemName("Iron sword"));
    itemNames.emplace_back(ItemName("Shield"));
    itemNames.emplace_back(ItemName("Wooden bow"));
    itemNames.emplace_back(ItemName("Arrows"));
    itemNames.emplace_back(ItemName("Knife"));
    itemNames.emplace_back(ItemName("Human skeleton"));
    itemNames.emplace_back(ItemName("Demon skull"));
    itemNames.emplace_back(ItemName("Chains"));
    itemNames.emplace_back(ItemName("Unidentified eyeball"));
    itemNames.emplace_back(ItemName("Old book"));
}

void Game::loadItemWeights() {
    itemWeights.emplace_back(ItemWeight(1));
    itemWeights.emplace_back(ItemWeight(1));
    itemWeights.emplace_back(ItemWeight(3));
    itemWeights.emplace_back(ItemWeight(3));
    itemWeights.emplace_back(ItemWeight(3));
    itemWeights.emplace_back(ItemWeight(3));
    itemWeights.emplace_back(ItemWeight(2));
    itemWeights.emplace_back(ItemWeight(5));
    itemWeights.emplace_back(ItemWeight(3));
    itemWeights.emplace_back(ItemWeight(3));
    itemWeights.emplace_back(ItemWeight(2));
    itemWeights.emplace_back(ItemWeight(2));
    itemWeights.emplace_back(ItemWeight(6));
    itemWeights.emplace_back(ItemWeight(4));
    itemWeights.emplace_back(ItemWeight(8));
    itemWeights.emplace_back(ItemWeight(0));
    itemWeights.emplace_back(ItemWeight(0));
    itemWeights.emplace_back(ItemWeight(7));
}
