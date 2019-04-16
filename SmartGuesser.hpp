#include<iostream>
#include "Guesser.hpp"

using namespace std;
// using namespace bullpgia;

namespace bullpgia{
  class SmartGuesser: public bullpgia::Guesser{

    private :
    string Guess;

    public :
    uint length;
    SmartGuesser(){

    }
    SmartGuesser(const string& str){
       Guess = str;
    }
    void learn(string solutions) override;
    string guess() override;
    void startNewGame(uint length) override;

  };
}