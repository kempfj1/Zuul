#ifndef CANDY_H
#define CANDY_H
//Zuul Conversion to C++
//@author Julia Kempf
//@version 2016.10.05

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Candy{
private:
  string candyType;

public:
  Candy(string candyType);
  string getCandyType();
};
#endif
