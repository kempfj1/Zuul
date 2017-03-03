#ifndef ROOM_H
#define ROOM_H

#include <string> //string is not included in the built in core language
#include <map> //map is not built in to the core language
#include <iostream>//input/output stream
#include <vector>
#include "Candy.h"
using namespace std;
//Zuul Conversion to C++
//@author Julia Kempf
//@version 2016.10.05

class Room{
private://shows all private methods and local variables
  vector<Candy*> candy;

  string description;

  map<string, Room*> exits;

public:
  Room(string description);//the rooms description

  void setExit(string direction, Room* neighbor);//define an exit

  string getShortDescription();//return short description of the room

  string getLongDescription();//return long description of the room

  string getExitString();//return a string defining the rooms exits
  string getCandyString();
//  string getCandyDescription();

  Room* getExit(string direction);//return the room that is reached if you go "direction"

  void setCandy(Candy* candy);

  void remove(string name);

};
#endif
