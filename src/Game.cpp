#include <iostream>
#include "../headers/Game.h"

void Game::init()
{
    loadAreas();
    loadItemWeights();
    loadItemNames();
    loadRooms();
    connectRooms();
    removeObseleteConnections();
    placeInitialItems();
    cout << "Type \"h\" or \"help\" for help.\n";
    player.setCurrentRoom(*firstRoom);
    firstRoom->printRoom();

}

void Game::run()
{
    while(step());
    cout << "...";
    cin.get();
    isGameWon ? printWinMessage() : printLoseMessage();
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

    if (player.getCurrentRoomPointer() == lastRoom) isGameWon = true;
    if (player.getCurrentRoomPointer() == deathRoom) player.changeHealth(-100);

    return player.getCurrentRoomPointer() != lastRoom && player.isAlive();
}

void Game::handleInput(string &input) {
    switch (Parser::parseInput(input)) {
        case HELP:
            cout << "\tMove to north, type: 'n' or 'north'.\n"
                    "\tMove to south, type: 's' or 'south'.\n"
                    "\tMove to west, type: 'w' or 'west'.\n"
                    "\tMove to east, type: 'e' or 'east'.\n"
                    "\tPick up items, type: 'p' or 'pick'.\n"
                    "\tDrop items, type: 'd' or 'drop'.\n"
                    "\tList items, type: 'l' or 'list'.\n" << endl;
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
        case LIST_ITEMS:
            player.showInventory();
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
    itemWeights.emplace_back(ItemWeight(0));
    itemWeights.emplace_back(ItemWeight(1));
    itemWeights.emplace_back(ItemWeight(2));
    itemWeights.emplace_back(ItemWeight(3));
    itemWeights.emplace_back(ItemWeight(4));
    itemWeights.emplace_back(ItemWeight(5));
    itemWeights.emplace_back(ItemWeight(6));
    itemWeights.emplace_back(ItemWeight(7));
    itemWeights.emplace_back(ItemWeight(8));
}

void Game::loadAreas()
{
    areas.emplace_back(Area("You stumble inside a forest. The trees are dense, but you can make out a path."));
    areas.emplace_back(Area("This meadow is is vast and filled with creatures you've never seen before."));
    areas.emplace_back(Area("You find the remains of a once great castle. There is not a single living thing here."));
    areas.emplace_back(Area("You see the entrance to a cave, but it's much too dark inside, you don't have a torch."));
    areas.emplace_back(Area("You feel like something is mystical about this place. Almost as if space is warped."));
    areas.emplace_back(Area("The sight of this pond is soothing. The water is crystal clear so you stop for a drink, but you must continue your journey."));
    areas.emplace_back(Area("A monster of colossus figure stands before you. There is no time to react, it grabs you by the leg and swallows you whole."));
    areas.emplace_back(Area("You find a portal, through which you can see your homeland."));
}

void Game::loadRooms() {
    rooms.emplace_back(Room(2, 3, areas[0], true, true, true, true));
    rooms.emplace_back(Room(1, 3, areas[0], false, true, false, false));
    rooms.emplace_back(Room(3, 3, areas[5], false, false, true, true));
    rooms.emplace_back(Room(3, 4, areas[0], true, true, false, false));
    rooms.emplace_back(Room(4, 4, areas[4], false, true, false, true));
    rooms.emplace_back(Room(2, 4, areas[1], true, false, true, true));
    rooms.emplace_back(Room(2, 5, areas[3], true, false, false, false));
    rooms.emplace_back(Room(1, 4, areas[4], false, true, true, true));
    rooms.emplace_back(Room(1, 5, areas[2], true, false, false, false));
    rooms.emplace_back(Room(2, 2, areas[3], true, true, true, true));
    rooms.emplace_back(Room(3, 2, areas[6], false, false, false, true));
    rooms.emplace_back(Room(1, 2, areas[2], false, true, false, true));
    rooms.emplace_back(Room(0, 2, areas[0], false, true, true, false));
    rooms.emplace_back(Room(0, 3, areas[3], true, false, false, false));
    rooms.emplace_back(Room(2, 1, areas[2], false, true, true, true));
    rooms.emplace_back(Room(3, 1, areas[1], false, true, false, true));
    rooms.emplace_back(Room(4, 1, areas[0], false, false, true, true));
    rooms.emplace_back(Room(4, 2, areas[0], true, false, false, false));
    rooms.emplace_back(Room(1, 1, areas[5], true, true, false, false));
    rooms.emplace_back(Room(1, 0, areas[1], false, true, true, false));
    rooms.emplace_back(Room(2, 0, areas[7], false, false, false, true));

    rooms[4].setEasternRoom(rooms[7]);
    rooms[7].setWesternRoom(rooms[4]);

    firstRoom = &rooms[0];
    lastRoom = &rooms[20];
    deathRoom = &rooms[10];
}

void Game::placeInitialItems() {
    srand(time(0));
    for (Room& room : rooms) {
        int rndNameIdx = rand() % itemNames.size();
        int rndWeightIdx = rand() % itemWeights.size();
        room.placeItem(Item(itemNames[rndNameIdx], itemWeights[rndWeightIdx]));
    }
}

void Game::printWinMessage() {
    cout << "\n\n"
            "  .oooooo.                                                           .               oooo                .    o8o                                 .o.\n"
            " d8P'  `Y8b                                                        .o8               `888              .o8    `\"'                                 888\n"
            "888           .ooooo.  ooo. .oo.    .oooooooo oooo d8b  .oooo.   .o888oo oooo  oooo   888   .oooo.   .o888oo oooo   .ooooo.  ooo. .oo.    .oooo.o 888\n"
            "888          d88' `88b `888P\"Y88b  888' `88b  `888\"\"8P `P  )88b    888   `888  `888   888  `P  )88b    888   `888  d88' `88b `888P\"Y88b  d88(  \"8 Y8P\n"
            "888          888   888  888   888  888   888   888      .oP\"888    888    888   888   888   .oP\"888    888    888  888   888  888   888  `\"Y88b.  `8'\n"
            "`88b    ooo  888   888  888   888  `88bod8P'   888     d8(  888    888 .  888   888   888  d8(  888    888 .  888  888   888  888   888  o.  )88b .o.\n"
            " `Y8bood8P'  `Y8bod8P' o888o o888o `8oooooo.  d888b    `Y888\"\"8o   \"888\"  `V88V\"V8P' o888o `Y888\"\"8o   \"888\" o888o `Y8bod8P' o888o o888o 8\"\"888P' Y8P\n"
            "                                   d\"     YD\n"
            "                                   \"Y88888P'\n"
            "\n"
            "oooooo   oooo                          oooo                                                                                                             .o8  .o.\n"
            " `888.   .8'                           `888                                                                                                            \"888  888\n"
            "  `888. .8'    .ooooo.  oooo  oooo      888 .oo.    .oooo.   oooo    ooo  .ooooo.      .ooooo.   .oooo.o  .ooooo.   .oooo.   oo.ooooo.   .ooooo.   .oooo888  888\n"
            "   `888.8'    d88' `88b `888  `888      888P\"Y88b  `P  )88b   `88.  .8'  d88' `88b    d88' `88b d88(  \"8 d88' `\"Y8 `P  )88b   888' `88b d88' `88b d88' `888  Y8P\n"
            "    `888'     888   888  888   888      888   888   .oP\"888    `88..8'   888ooo888    888ooo888 `\"Y88b.  888        .oP\"888   888   888 888ooo888 888   888  `8'\n"
            "     888      888   888  888   888      888   888  d8(  888     `888'    888    .o    888    .o o.  )88b 888   .o8 d8(  888   888   888 888    .o 888   888  .o.\n"
            "    o888o     `Y8bod8P'  `V88V\"V8P'    o888o o888o `Y888\"\"8o     `8'     `Y8bod8P'    `Y8bod8P' 8\"\"888P' `Y8bod8P' `Y888\"\"8o  888bod8P' `Y8bod8P' `Y8bod88P\" Y8P\n"
            "                                                                                                                              888\n"
            "                                                                                                                             o888o\n\n";
}

void Game::printLoseMessage() {
    cout << "\n\n"
            "oooooo   oooooo     oooo oooo                                                .o.\n"
            " `888.    `888.     .8'  `888                                                888\n"
            "  `888.   .8888.   .8'    888 .oo.    .ooooo.   .ooooo.  oo.ooooo.   .oooo.o 888\n"
            "   `888  .8'`888. .8'     888P\"Y88b  d88' `88b d88' `88b  888' `88b d88(  \"8 Y8P\n"
            "    `888.8'  `888.8'      888   888  888   888 888   888  888   888 `\"Y88b.  `8'\n"
            "     `888'    `888'       888   888  888   888 888   888  888   888 o.  )88b .o.\n"
            "      `8'      `8'       o888o o888o `Y8bod8P' `Y8bod8P'  888bod8P' 8\"\"888P' Y8P\n"
            "                                                          888\n"
            "                                                         o888o\n"
            "\n"
            "oooooo    oooo                                                                .o8                            .o8  .o.\n"
            " `888.    .8'                                                                \"888                           \"888  888\n"
            "   `888. .8'    .ooooo.  oooo  oooo      .oooo.   oooo d8b  .ooooo.      .oooo888   .ooooo.   .oooo.    .oooo888  888\n"
            "    `888.8'    d88' `88b `888  `888     `P  )88b  `888\"\"8P d88' `88b    d88' `888  d88' `88b `P  )88b  d88' `888  Y8P\n"
            "     `888'     888   888  888   888      .oP\"888   888     888ooo888    888   888  888ooo888  .oP\"888  888   888  `8'\n"
            "      888      888   888  888   888     d8(  888   888     888    .o    888   888  888    .o d8(  888  888   888  .o.\n"
            "     o888o     `Y8bod8P'  `V88V\"V8P'    `Y888\"\"8o d888b    `Y8bod8P'    `Y8bod88P\" `Y8bod8P' `Y888\"\"8o `Y8bod88P\" Y8P\n\n";
}

void Game::connectRooms() {
    int outerEnd = rooms.size() - 1;
    int innerEnd = rooms.size();
    for (int i = 0; i < outerEnd; ++i) {
        for (int j = i + 1; j < innerEnd; ++j) {
            if (rooms[i].getX() == rooms[j].getX()) {
                if (rooms[i].getY() == rooms[j].getY() - 1) {
                    // J is to the south of I
                    rooms[i].setSouthernRoom(rooms[j]);
                    rooms[j].setNorthernRoom(rooms[i]);
                    continue;
                } else if (rooms[i].getY() == rooms[j].getY() + 1) {
                    // J is to the north of I
                    rooms[i].setNorthernRoom(rooms[j]);
                    rooms[j].setSouthernRoom(rooms[i]);
                    continue;
                }
            }
            if (rooms[i].getY() == rooms[j].getY()) {
                if (rooms[i].getX() == rooms[j].getX() - 1) {
                    // J is to the east of I
                    rooms[i].setEasternRoom(rooms[j]);
                    rooms[j].setWesternRoom(rooms[i]);
                    continue;
                } else if (rooms[i].getX() == rooms[j].getX() + 1) {
                    // J is to the west of I
                    rooms[i].setWesternRoom(rooms[j]);
                    rooms[j].setEasternRoom(rooms[i]);
                    continue;
                }
            }

        }
    }
}

void Game::removeObseleteConnections() {
    for (Room& room : rooms) {
        room.removeObseleteConnections();
    }
}
