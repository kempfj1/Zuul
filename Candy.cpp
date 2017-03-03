#include "Candy.h"

//Zuul Conversion to C++
//@author Julia Kempf
//@version 2016.10.05

Candy::Candy(string candyType){
  this->candyType = candyType;
}

string Candy::getCandyType(){
  return candyType;
}
