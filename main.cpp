#include <iostream>
#include "headers/Game.h"

using namespace std;

void printEndMessage() {
    cout << "\n\n"
            "  .oooooo.                                                           .               oooo                .    o8o                                 .o.    oooooo   oooo\n"
            " d8P'  `Y8b                                                        .o8               `888              .o8    `\"'                                 888     `888.   .8'\n"
            "888           .ooooo.  ooo. .oo.    .oooooooo oooo d8b  .oooo.   .o888oo oooo  oooo   888   .oooo.   .o888oo oooo   .ooooo.  ooo. .oo.    .oooo.o 888      `888. .8'    .ooooo.  oooo  oooo\n"
            "888          d88' `88b `888P\"Y88b  888' `88b  `888\"\"8P `P  )88b    888   `888  `888   888  `P  )88b    888   `888  d88' `88b `888P\"Y88b  d88(  \"8 Y8P       `888.8'    d88' `88b `888  `888\n"
            "888          888   888  888   888  888   888   888      .oP\"888    888    888   888   888   .oP\"888    888    888  888   888  888   888  `\"Y88b.  `8'        `888'     888   888  888   888\n"
            "`88b    ooo  888   888  888   888  `88bod8P'   888     d8(  888    888 .  888   888   888  d8(  888    888 .  888  888   888  888   888  o.  )88b .o.         888      888   888  888   888\n"
            " `Y8bood8P'  `Y8bod8P' o888o o888o `8oooooo.  d888b    `Y888\"\"8o   \"888\"  `V88V\"V8P' o888o `Y888\"\"8o   \"888\" o888o `Y8bod8P' o888o o888o 8\"\"888P' Y8P        o888o     `Y8bod8P'  `V88V\"V8P'\n"
            "                                   d\"     YD\n"
            "                                   Y88888P'\n"
            "\n"
            "                                                          .                 .o88o.        .   oooo\n"
            "                                                        .o8                 888 `\"      .o8   `888\n"
            " .oooo.   oooo d8b  .ooooo.      .ooooo.  oooo  oooo  .o888oo     .ooooo.  o888oo     .o888oo  888 .oo.    .ooooo.\n"
            "`P  )88b  `888\"\"8P d88' `88b    d88' `88b `888  `888    888      d88' `88b  888         888    888P\"Y88b  d88' `88b\n"
            " .oP\"888   888     888ooo888    888   888  888   888    888      888   888  888         888    888   888  888ooo888\n"
            "d8(  888   888     888    .o    888   888  888   888    888 .    888   888  888         888 .  888   888  888    .o\n"
            "`Y888\"\"8o d888b    `Y8bod8P'    `Y8bod8P'  `V88V\"V8P'   \"888\"    `Y8bod8P' o888o        \"888\" o888o o888o `Y8bod8P'\n"
            "\n"
            "\n"
            "\n"
            "oooo             .o8        o8o            o8o                 .    oooo        .o.\n"
            "`888            \"888        `\"'            `\"'                .o8   `888        888\n"
            " 888   .oooo.    888oooo.  oooo  oooo d8b oooo  ooo. .oo.   .o888oo  888 .oo.   888\n"
            " 888  `P  )88b   d88' `88b `888  `888\"\"8P `888  `888P\"Y88b    888    888P\"Y88b  Y8P\n"
            " 888   .oP\"888   888   888  888   888      888   888   888    888    888   888  `8'\n"
            " 888  d8(  888   888   888  888   888      888   888   888    888 .  888   888  .o.\n"
            "o888o `Y888\"\"8o  `Y8bod8P' o888o d888b    o888o o888o o888o   \"888\" o888o o888o Y8P\n\n\n";
}

int main() {
    cout << "Starting Mighty Text Adventure!" << endl;

    Game game;
    game.init();
    game.run();
    printEndMessage();

    cout << "Exiting from Mighty Text Adventure!" << endl;
    return 0;
}
