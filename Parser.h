/** World of Zuul C++ conversion
*@author Julia Kempf
*@version 2016.10.03
**/
#ifndef PARSER_H
#define PARSER_H
//prevents the header file from being included multiple times


#include "command.h"
#include "CommandWords.h"
#include <string> //string not part of built in core language
//includes .h files of command and CommandWords
//to allow Parser to use their methods.

class Parser{
  private:
    CommandWords *commands; //pointer assigned


  public:
    Parser();

    Command* getCommand();
    //returns new Command, requires a pointer
    void showCommands();



};
#endif //end of include guards
