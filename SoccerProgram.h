#ifndef SOCCERPROJECT_SOCCERPROGRAM_H
#define SOCCERPROJECT_SOCCERPROGRAM_H


#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "PlayerList.h"
#include "PlayerEntry.h"


//const char clear_command[] = "cls"; // for Windows
const char clear_command[] = "clear"; // for Linux and possibly Mac's

const char cs_file_name[] = "Players.txt";

class SoccerProgram
{
public:
    void run();

private:
    void display_entry_and_menu() const;
    void execute(char command, bool& done);

    PlayerList player_list_;
    std::vector<PlayerEntry> search_results_;
    std::vector<PlayerEntry>::iterator curr_player_;
    int seasonYear_;
    bool main_view_ = true;
};


#endif //SOCCERPROJECT_SOCCERPROGRAM_H