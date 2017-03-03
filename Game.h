#ifndef GAME_H
#define GAME_H
//Zuul Conversion to C++
//@author Julia Kempf
//@version 2016.10.05


#include "command.h"
#include "CommandWords.h"
#include "Parser.h"
#include "Room.h"
#include "Candy.h"
#include <iostream>
#include <string>

using namespace std;

class Game{
private:
  Parser parser;

  Room *currentRoom;

  void createRooms();

  void createCandy();

  void printWelcome();

  bool processCommand(Command command);

  void printHelp();

  void goRoom(Command command);

  void printCandy(Command command);

  bool quit(Command command);

public:
  Game();

  void play();

};
#endif
