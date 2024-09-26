#include "PlayerEntry.h"

std::string PlayerEntry::getAgeGroup(int seasonYear, int birthYear) {
    std::string ageGroup;
    int ageYear = seasonYear - birthYear;
    if (ageYear < 4) { ageGroup = "Invalid Age: Too Young"; }
    else if (ageYear < 6) { ageGroup = "U6"; }
    else if (ageYear < 8) { ageGroup = "U8"; }
    else if (ageYear < 10) { ageGroup = "U10"; }
    else if (ageYear < 12) { ageGroup = "U12"; }
    else if (ageYear < 14) { ageGroup = "U14"; }
    else if (ageYear < 17) { ageGroup = "U17"; }
    else { ageGroup = "Invalid Age: Too Old"; }
    return ageGroup;
}

void PlayerEntry::get_data(int seasonYear_) {
    std::cout << "new first name: ";
    getline(std::cin, firstName);
    std::cout << "new last name: ";
    getline(std::cin, lastName);
    std::cout << "year of birth: ";
    std::cin >> yearOfBirth;
    ageGroup = getAgeGroup(seasonYear_, yearOfBirth);
    std::cout << "registration status (paid(1) or not paid(0)): ";
    std::cin >> paid;
}

void PlayerEntry::is_match() {
    bool found = false;

}