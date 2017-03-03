#include "Room.h"//includes .h file
/**
 * Class Room - a room in an adventure game.
 *
 * This class is part of the "World of Zuul" application.
 * "World of Zuul" is a very simple, text based adventure game.
 *
 * A "Room" represents one location in the scenery of the game.  It is
 * connected to other rooms via exits.  For each existing exit, the room
 * stores a reference to the neighboring room.
 *
 * @author  Julia Kempf
 * @version 2016.10.05
 */



    /**
     * Create a room described "description". Initially, it has
     * no exits. "description" is something like "a kitchen" or
     * "an open court yard".
     * @param description The room's description.
     */
    Room::Room(string description)
    {
        this->description = description;
    }

    /**
     * Define an exit from this room.
     * @param direction The direction of the exit.
     * @param neighbor  The room to which the exit leads.
     */
    void Room::setExit(string direction, Room* neighbor)
    {
        exits[direction]=neighbor;
    }

    /**
     * @return The short description of the room
     * (the one that was defined in the constructor).
     */
    string Room::getShortDescription()
    {
        return description;
    }

    /**
     * Return a description of the room in the form:
     *     You are in the kitchen.
     *     Exits: north west
     * @return A long description of this room
     */
    string Room::getLongDescription()
    {
        return (description +"\n" +this->getExitString() + "\n" + this->getCandyString());
        //return description +"\n" +this->getCandyString();
    }

    /**
     * Return a string describing the room's exits, for example
     * "Exits: north west".
     * @return Details of the room's exits.
     */
    string Room::getExitString()
    {
        string returnExits = "Neighboring Houses:";
        for (map<string, Room*>::iterator it = exits.begin(); it != exits.end(); it++)
        {
          returnExits+= " "+ it->first;
        }
        return returnExits;

    }

    string Room::getCandyString()//gets list of candy types and returns for the room
    {
        string candyString = "Candy in the bowl:";
        for (vector<Candy*>::iterator it = candy.begin(); it != candy.end(); it++)
        {
          Candy* candyName= *it;
          candyString += candyName ->getCandyType();
        }
        return candyString;

    }
    /*string Room::getCandyDescription()
    {
      return description +"\n" +this->getCandyString();
    }
    */

    /**
     * Return the room that is reached if we go from this room in direction
     * "direction". If there is no room in that direction, return null.
     * @param direction The exit's direction.
     * @return The room in the given direction.
     */
    Room* Room::getExit(string direction)
    {
      return exits[direction];
    }

    void Room::setCandy(Candy* newCandy)//puts the candy in the room
    {
      candy.push_back(newCandy);
    }

    void Room::remove(string name)//removes the candy from the room
    {
      for (vector<Candy*>::iterator it = candy.begin(); it != candy.end(); it++)
      {
        Candy* tempCandy= *it;
        string tempString= tempCandy->getCandyType();
        if(name==(tempString))
        {

          candy.erase(it);
        }
      }

    }
