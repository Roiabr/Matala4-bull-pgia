#include<iostream>
#include <vector>
#include "Guesser.hpp"

using namespace std;
// using namespace bullpgia;

namespace bullpgia{
  class SmartGuesser: public bullpgia::Guesser{

    private :
    string Guess;

    public :
    uint length;
    int count1;
    string SmartGuess;
    int iterator;
    int iterator1;
    int bullSol;
    int pgiaSol;
    int succes;
    int arrGuess[10];
    bool four=false;

    
    
  /////////counstractors/////////////
    SmartGuesser(){}
    SmartGuesser(const string& str)
    {
       Guess = str;
       count1=1;
       iterator=0;
       iterator1=0;
       bullSol=0;
       pgiaSol=0;
       
       succes = 0;
       SmartGuess = "";
       
    
    }

    ///////////methods//////////////////
    void learn(string solutions) override;
    string guess() override;
    void startNewGame(uint length) override;
  };
}