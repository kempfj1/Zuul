#include <string>
#include "CommandWords.h"
using namespace std;


/**
 * This class is part of the "World of Zuul" application.
 * "World of Zuul" is a very simple, text based adventure game.
 *
 * This class holds an enumeration of all command words known to the game.
 * It is used to recognise commands as they are typed in.
 *
 //Zuul Conversion to C++
 //@author Julia Kempf
 //@version 2016.10.05
    
     * Constructor - initialise the command words.
     */
    CommandWords::CommandWords()
    {

          validCommands.push_back("go"); //valid command word
          validCommands.push_back("help"); // valid command word
          validCommands.push_back("quit");//valid command word
          validCommands.push_back("take");

    }

    /**
     * Check whether a given string is a valid command word.
     * @return true if it is, false if it isn't.
     */
    bool CommandWords::isCommand(string aString)
    {
        for(int i = 0; i < validCommands.size(); i++) {
            if(!validCommands[i].compare(aString))
                return true;
        }
        //if we get here, the string was not found in the commands
        return false;
    }

    /**
     * Print all valid commands to cout.
     */
    void CommandWords::showAll()
    {

        for(vector<string>::iterator command = validCommands.begin();
        command != validCommands.end(); command++) //showAll() iterator
        {
          cout << *command<< " " << endl; //returns valid command pointer
        }

    }
