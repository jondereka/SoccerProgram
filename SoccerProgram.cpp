#include "SoccerProgram.h"

using namespace std;

void SoccerProgram::run()
{
    player_list_.read_file(cs_file_name, seasonYear_);

    bool done = false;
    while (!done) {
        display_entry_and_menu();
        cout << "choice: ";
        char command;
        cin >> command;
        cin.get(); // new line char
        execute(command, done);
        cout << endl;
    }
}

void SoccerProgram::display_entry_and_menu() const {
    string long_separator(50, '-');
    string short_separator(8, '-');

    system(clear_command);

    if (main_view_) {
        cout << long_separator << endl
             << "  begin   search  quit\n"
             << "  add     list    display stats\n"
             << short_separator << endl;
    }
    else {
        cout << *curr_player_;
        cout << long_separator << endl
             << "  next    previous  return\n"
             << "  search  edit      print(l)\n"
             << short_separator << endl;
    }
}


void SoccerProgram::execute(char command, bool& done)
{
    switch (command) {
        case 'b': {
            char confirm;
            cout << "Enter the season year: ";
            cin >> seasonYear_;
            cout << "Are you sure you want to delete existing players? (y)";
            cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                //player_list_.clear();
            }
            break;
        }
        case 'n': {
            curr_player_++;
            if (curr_player_ == search_results_.end()) curr_player_ = search_results_.begin();
            break;
        }
        case 'p': {
            if (curr_player_ == search_results_.begin()) curr_player_ = search_results_.end();
            curr_player_--;
            break;
        }
        case 'e': {
            if (player_list_.empty())
                return;
            PlayerEntry new_player;
            cout << "(leave blank if no change needed)\n";
            cout << "new first name: ";
            getline(cin, new_player.firstName);
            cout << "new last name: ";
            getline(cin, new_player.lastName);
            cout << "year of birth: ";
            cin >> new_player.yearOfBirth;
            cout << "registration status (true or false): ";
            cin >> new_player.paid;
            //player_list_.update_current_entry(new_player);
            break;
        }
        case 's': {
            if (main_view_) {
                cout << "You are entering the search view. Press any button to continue.";
                cin.get();
                system(clear_command);
                main_view_ = false;
                //display_entry_and_menu();
            }
            cout << "Search by last name: ";
            curr_player_ = search_results_.begin();
            string lastName;
            getline(cin, lastName);
            player_list_.find(lastName, search_results_);
            if (search_results_.empty()) {
                main_view_ = false;
                cout << "No match.";
                cout << "Click to exit.";
                cin.get();
                curr_player_ = search_results_.begin();
                system(clear_command);
                command = 's';
                display_entry_and_menu();
            }
            else {
                curr_player_ = search_results_.begin();
                //display_player(search_results_, curr_player_);
            }
            break;
        }
        case 'l': {
            cout << "Enter file name to print to: " << endl;
            string file_name;
            cin >> file_name;
            for (int i = 0; i < search_results_.size(); ++i) {
                cout << search_results_[i];
            }
            break;
        }
        case 'a': {
            PlayerEntry new_player;
            new_player.get_data(seasonYear_);
            player_list_.add(new_player);
            break;
        }
        case 'd': {
            // Not yet implemented
            break;
        }
        case 'q': {
            player_list_.write_file(cs_file_name);
            done = true;
            break;
        }
        case 'r': {
            system(clear_command);
            main_view_ = true;
            display_entry_and_menu();
        }
    }
}