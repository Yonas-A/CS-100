#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <vector>
#include <string>

class Menu {
    private:
        int history_index; // Indexes which command was last executed, accounting for undo and redo functions
        std::vector<Command*> history; // Holds all the commands that have been executed until now

    public:
        Menu() {
            // Constructor which initializes the internal members
        }

        std::string execute() {
            // Returns the string converted evaluation of the current command
        }

        std::string stringify() {
            // Returns the stringified version of the current command
        }

        bool initialized() {
            // Returns if the history has an InitialCommand, which is necessary to start the calculation
        }

        void add_command(Command* cmd) {
            // Adds a command to the history (does not execute it), this may require removal of some other commands depending on where history_index is
        }

        Command* get_command() {
            // Returns the command that the history_index is currently referring to
        }

        void undo() {
            // Move back one command (does not execute it) if there is a command to undo
        }

        void redo() {
            // Moves forward one command (does not execute it) if there is a command to redo
        }
};

#endif
