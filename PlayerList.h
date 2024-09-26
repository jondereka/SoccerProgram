#ifndef SOCCERPROJECT_PLAYERLIST_H
#define SOCCERPROJECT_PLAYERLIST_H

#include <iostream>
#include <map>
#include <string>
#include "PlayerEntry.h"
#include <vector>
#include <vector>

class PlayerList
{
public:

    void add(const PlayerEntry& newPlayer);
    void edit_player(const PlayerEntry& new_data);
    bool empty() const { return players_.empty(); }
    void read_file(const std::string& file_name, int& seasonYear);
    void write_file(const std::string& file_name) const;
    void find(const std::string& last_name, std::vector<PlayerEntry>& search_results);
    void display() const;
private:
    std::map<std::string, PlayerEntry> players_;
};

inline void PlayerList::add(const PlayerEntry& newPlayer)
{
    players_.insert({ newPlayer.lastName, newPlayer });
}

inline void PlayerList::display() const
{
    int count = 0;
    for (auto pair: players_) {
        count++;
        pair.second.ageGroup;
    }
}





#endif //SOCCERPROJECT_PLAYERLIST_H