//World of Zuul conversion to C++
//@author Julia Kempf
//@version 2016.10.03


#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H // include guards, prevent double declarations

#include <string> //this header required to use string class
#include <iostream>//included to write standard input/output streams
#include <vector>//vectors are a standard library facility, and must be included
                //like this as they are not a part of the core language
using namespace std; //done to avoid std:: prefix

class CommandWords{

private:
  vector<string> validCommands; //vector is like a Java array, stores string.

public:
  CommandWords();
  
  bool isCommand(string aString);

  void showAll();

};
#endif //end of include guards
