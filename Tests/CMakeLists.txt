


#add necessary includes
include_directories(../cmake_modules)
set(MAIN_MENU_TEST_INCLUDES
        catch.h
        main_menu_test.cpp
        ../Main_Menu/Main_menu.h)

add_executable(main_menu_test ${MAIN_MENU_TEST_INCLUDES})