
#pragma once
#include <string>
#include "calculate.hpp"

using namespace std;

namespace bullpgia{

  class Guesser{
  private:
    string Guess;
  public:
    Guesser(){
      Guess = "";
    }
    Guesser(const string& str){
      Guess = str;
    }
    // variabales
    uint length;
    // functions
    virtual void startNewGame(uint length){}
    virtual string guess() = 0;
    virtual void learn(string solutions){}

  };
}