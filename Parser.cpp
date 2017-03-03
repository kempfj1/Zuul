#include "Parser.h" //includes the Parser.h file for compiling
#include <iostream> //input/output stream
using namespace std;// avoid std::

/**
 * This class is part of the "World of Zuul" application.
 * "World of Zuul" is a very simple, text based adventure game.
 *
 * This parser reads user input and tries to interpret it as an "Adventure"
 * command. Every time it is called it reads a line from the terminal and
 * tries to interpret the line as a two word command. It returns the command
 * as an object of class Command.
 *
 * The parser has a set of known command words. It checks user input against
 * the known commands, and if the input is not one of the known commands, it
 * returns a command object that is marked as an unknown command.
 *
 //Zuul Conversion to C++
 //@author Julia Kempf
 //@version 2016.10.05
 */
    /**
     * Create a parser to read from the terminal window.
     */
    Parser::Parser()
    {
        commands = new CommandWords();

    }

    /**
     * @return The next command from the user.
     */
    Command* Parser::getCommand() //returns a new Command, requires a pointer
    {
        string inputLine;   // will hold the full input line
        string word1 = ""; //set as null
        string word2 = ""; //set as null


        cout <<"> ";     // print prompt

        getline(cin, inputLine);

        int pos=0;//set pos to 0
        pos=inputLine.find_first_of(" ");//pos is now at the place where a space is found
        if(pos<1){//if no space is found
          word1=inputLine;//there is only one word, and that word is also the inputLine
        }
        else{//if a space is found
          word1=inputLine.substr(0, pos);//word1 is from 0 to the location of pos
          word2=inputLine.substr(pos+1, inputLine.length());//word2 is from pos location
                                                          //+1 to the length of inputLine.
        }


        // Now check whether this word is known. If so, create a command
        // with it. If not, create a "null" command (for unknown command).
        if(commands->isCommand(word1)) {//"->" dereference, equivalent to
                                        //java's ".isCommand" function
            return new Command(word1, word2);
        }
        else {
            return new Command("", word2);
        }
    }

    /**
     * Print out a list of valid command words.
     */
    void Parser::showCommands()
    {
        commands->showAll(); //could also be written as (*commands).showAll();
                             //dereferences a pointer
    }
