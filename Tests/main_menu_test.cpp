//
// Created by Scott Anthony Guidotti  on 9/28/17.
//

#define CATCH_CONFIG_MAIN

#include "catch.h"
#include "../Main_Menu/Main_menu.h"



TEST_CASE("Main Menu Background is black", "[main menu]") {
    Main_menu x;
    REQUIRE(x.get_background_color() == "black");
}



