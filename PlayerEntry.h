#ifndef SOCCERPROJECT_PLAYERENTRY_H
#define SOCCERPROJECT_PLAYERENTRY_H

#include <iostream>
#include <fstream>
#include <string>

class PlayerEntry
{
public:
    PlayerEntry() : firstName("no name"), lastName("no name"), yearOfBirth(-1), paid(false) {}

    PlayerEntry(const std::string& lname, const std::string& fname, int yob, bool paid) :
            lastName(lname), firstName(fname), yearOfBirth(yob), paid(paid) {}

    void update(const PlayerEntry& new_data);
    std::string getAgeGroup(int seasonYear, int birthYear);
    void get_data(int seasonYear_);
    void is_match();

    std::string firstName;
    std::string lastName;
    int yearOfBirth;
    std::string ageGroup;
    bool paid;
};


inline void PlayerEntry::update(const PlayerEntry& new_data)
{
    if (!new_data.lastName.empty())
        lastName = new_data.lastName;
    if (!new_data.firstName.empty())
        firstName = new_data.firstName;
    /*if (!new_data.yearOfBirth.empty())
        yearOfBirth = new_data.yearOfBirth;
    if (!new_data.paid.empty())
        paid = new_data.paid;*/
}

inline std::istream& operator>>(std::istream& in, PlayerEntry& e)
{
    getline(in, e.firstName);
    getline(in, e.lastName);
    in >> e.ageGroup;
    in >> e.paid;
    return in;
}

inline std::ostream& operator<<(std::ostream& out,
                                const PlayerEntry& e)
{
    out << "First Name: " << e.firstName << std::endl
        <<"Last Name: " << e.lastName << std::endl
        <<"Category: " << e.ageGroup << std::endl;
    if (e.paid) {
        out << "Registration Status: Paid" << std::endl;
    }
    else {
        out << "Registration Status: Not Paid" << std::endl;
    }
    return out;
}



#endif //SOCCERPROJECT_PLAYERENTRY_H