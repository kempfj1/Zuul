#include <string> //must be included as string is not part of built in language
#include "command.h" //include .h file
using namespace std; //used to avoid std:: repetition


/**
 * This class is part of the "World of Zuul" application.
 * "World of Zuul" is a very simple, text based adventure game.
 *
 * This class holds information about a command that was issued by the user.
 * A command currently consists of two strings: a command word and a second
 * word (for example, if the command was "take map", then the two strings
 * obviously are "take" and "map").
 *
 * The way this is used is: Commands are already checked for being valid
 * command words. If the user entered an invalid command (a word that is not
 * known) then the command word is "".
 *
 * If the command had only one word, then the second word is "".
 * CONVERSION TO C++
 * @author  Julia Kempf
 * @version 2016.10.03
 */

    /**
     * Create a command object. First and second word must be supplied, but
     * either one (or both) can be null.
     * @param firstWord The first word of the command. Null if the command
     *                  was not recognised.
     * @param secondWord The second word of the command.
     */
     Command::Command()//Gary told us to put this here.
     {
       commandWord="";//no inputs
       secondWord="";//no inputs
     }


    Command::Command(string firstWord, string secondWord) //string is lowercase
    //includes scope resolution operator to implement methods
    {
        commandWord = firstWord;
        this->secondWord = secondWord;
        //"This" pointer used to retrieve "secondWord" that is
        //a private local variable, equivalent to Java's "this."
        //function
    }

    /**
     * Return the command word (the first word) of this command. If the
     * command was not understood, the result is "".
     * @return The command word.
     */
    string Command::getCommandWord()//string is now lowercase in C++
    {
        return commandWord; //returns first word
    }

    /**
     * @return The second word of this command. Returns "" if there was no
     * second word.
     */
    string Command::getSecondWord()
    {
        return secondWord;
    }

    /**
     * @return true if this command was not understood.
     */
    bool Command::isUnknown()//boolean is bool in C++
    {
        return (commandWord == ""); 
    }

    /**
     * @return true if the command has a second word.
     */
    bool Command::hasSecondWord()
    {
        return (secondWord != "");
    }
