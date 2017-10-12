#include <iostream>
#include "headers/Game.h"

using namespace std;

void printWinMessage() {
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

void printLoseMessage() {
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

int main() {
    cout << "Starting Mighty Text Adventure!" << endl;

    Game game;
    game.init();
    game.run();
    printWinMessage();
    printLoseMessage();

    cout << "Exiting from Mighty Text Adventure!" << endl;
    return 0;
}
