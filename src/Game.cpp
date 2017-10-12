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
    firstRoom->printRoom();

}

void Game::run()
{
    while(step());
    isGameLost ? printLoseMessage() : printWinMessage();
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

void Game::loadAreas()
{
    areas.emplace_back(Area("You stumble inside a forest. the trees are dense, but you can make out a path."));
    areas.emplace_back(Area("This meadow is is vast and filled with creatures you've never seen before."));
    areas.emplace_back(Area("You find the remains of a once great castle. There is not a single living thing here."));
    areas.emplace_back(Area("You see the entrance to a cave, but it's much too dark inside, you don't have a torch."));
    areas.emplace_back(Area("You feel like something is mystical about this place. Almost as if space is warped."));
    areas.emplace_back(Area("The sight of this pond is soothing. The water is crystal clear so you stop for a drink, but you must continue your journey."));
    areas.emplace_back(Area("A monster of colossus figure stands before you. There is no time to react, it grabs you by the leg and swallows you whole."));
    areas.emplace_back(Area("You find a portal, through which you can see your homeland."));
}

void Game::loadRooms() {
    rooms.emplace_back(Room(0, 0, areas[0], false, false, false, false));

    rooms.emplace_back(Room(0, 0, areas[0], false, false, false, false));
    rooms[0].setWesternRoom(rooms[1]);
    rooms[1].setEasternRoom(rooms[0]);

    rooms.emplace_back(Room(0, 0, areas[5], false, false, false, false));
    rooms[0].setEasternRoom(rooms[2]);
    rooms[2].setWesternRoom(rooms[0]);

    rooms.emplace_back(Room(0, 0, areas[0], false, false, false, false));
    rooms[2].setSouthernRoom(rooms[3]);
    rooms[3].setNorthernRoom(rooms[2]);

    rooms.emplace_back(Room(0, 0, areas[4], false, false, false, false));
    rooms[3].setEasternRoom(rooms[4]);
    rooms[4].setWesternRoom(rooms[3]);

    rooms.emplace_back(Room(0, 0, areas[1], false, false, false, false));
    rooms[0].setSouthernRoom(rooms[5]);
    rooms[5].setNorthernRoom(rooms[0]);

    rooms.emplace_back(Room(0, 0, areas[3], false, false, false, false));
    rooms[5].setSouthernRoom(rooms[6]);
    rooms[6].setNorthernRoom(rooms[5]);

    rooms.emplace_back(Room(0, 0, areas[4], false, false, false, false));
    rooms[4].setEasternRoom(rooms[7]);
    rooms[7].setWesternRoom(rooms[4]);

    rooms.emplace_back(Room(0, 0, areas[2], false, false, false, false));
    rooms[7].setSouthernRoom(rooms[8]);
    rooms[8].setNorthernRoom(rooms[7]);

    rooms.emplace_back(Room(0, 0, areas[3], false, false, false, false));
    rooms[0].setNorthernRoom(rooms[9]);
    rooms[9].setSouthernRoom(rooms[0]);

    rooms.emplace_back(Room(0, 0, areas[6], false, false, false, false));
    rooms[9].setEasternRoom(rooms[10]);
    rooms[10].setWesternRoom(rooms[9]);

    rooms.emplace_back(Room(0, 0, areas[2], false, false, false, false));
    rooms[9].setWesternRoom(rooms[11]);
    rooms[11].setEasternRoom(rooms[9]);

    rooms.emplace_back(Room(0, 0, areas[0], false, false, false, false));
    rooms[11].setWesternRoom(rooms[12]);
    rooms[12].setEasternRoom(rooms[11]);

    rooms.emplace_back(Room(0, 0, areas[3], false, false, false, false));
    rooms[12].setSouthernRoom(rooms[13]);
    rooms[13].setNorthernRoom(rooms[12]);

    rooms.emplace_back(Room(0, 0, areas[2], false, false, false, false));
    rooms[9].setNorthernRoom(rooms[14]);
    rooms[14].setSouthernRoom(rooms[9]);

    rooms.emplace_back(Room(0, 0, areas[1], false, false, false, false));
    rooms[14].setEasternRoom(rooms[15]);
    rooms[15].setWesternRoom(rooms[14]);


    rooms.emplace_back(Room(0, 0, areas[0], false, false, false, false));
    rooms[15].setEasternRoom(rooms[16]);
    rooms[16].setWesternRoom(rooms[15]);

    rooms.emplace_back(Room(0, 0, areas[0], false, false, false, false));
    rooms[16].setSouthernRoom(rooms[17]);
    rooms[17].setNorthernRoom(rooms[16]);

    rooms.emplace_back(Room(0, 0, areas[5], false, false, false, false));
    rooms[14].setWesternRoom(rooms[18]);
    rooms[18].setEasternRoom(rooms[14]);

    rooms.emplace_back(Room(0, 0, areas[1], false, false, false, false));
    rooms[18].setNorthernRoom(rooms[19]);
    rooms[19].setSouthernRoom(rooms[18]);

    rooms.emplace_back(Room(0, 0, areas[7], false, false, false, false));
    rooms[19].setEasternRoom(rooms[20]);
    rooms[20].setWesternRoom(rooms[19]);

    firstRoom = &rooms[0];
    lastRoom = &rooms[20];
    deathRoom = &rooms[10];
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
