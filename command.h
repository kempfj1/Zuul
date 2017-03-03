//World of Zuul conversion to C++
//@author Julia Kempf
//@version 2016.10.03


#ifndef COMMAND_H
#define COMMAND_H//include guards, prevent double declarations

#include <string>
using namespace std;//done to avoid std:: prefix

class Command
{
  private:
    string commandWord;
    string secondWord;
//local variables

  public:
    Command();
    //blank constructor in case of undefined string variables

    Command(string firstWord, string secondWord);//string is now lowercase

    string getCommandWord();

    string getSecondWord();

    bool isUnknown();//boolean is bool in C++

    bool hasSecondWord();

};
#endif //include guard end
