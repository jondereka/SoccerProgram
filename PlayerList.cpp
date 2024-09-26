#include "PlayerList.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <map>
#include <vector>
using std::pair;
using std::vector;
#include <string>
using std::string;

void PlayerList::edit_player(const PlayerEntry& new_data)
{

}

void PlayerList::read_file(const std::string& file_name, int& seasonYear)
{
    ifstream ifs(file_name);
    if (!ifs);//ask for season year
    else {
        ifs >> seasonYear;
        ifs.get();
        PlayerEntry new_entry;
        while (ifs >> new_entry) {
            players_.insert({ new_entry.lastName, new_entry });
            //cin.get();
        }
    }
}

void PlayerList::write_file(const std::string& file_name) const
{
    ofstream out(file_name);
    for (auto pair: players_) {
        out << pair.second;
    }
}

void PlayerList::find(const std::string& last_name, std::vector<PlayerEntry>& search_results_)
{
    search_results_.clear();
    auto itr = players_.find(last_name);
    if (itr != players_.end()) {
        search_results_.push_back(itr->second);
    }
}