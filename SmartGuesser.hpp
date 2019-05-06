#include<iostream>
#include <vector>
#include "Guesser.hpp"
#include<vector>

using namespace std;
// using namespace bullpgia;

namespace bullpgia{
      

  class SmartGuesser: public bullpgia::Guesser{
    private :
    string Guess;

    public :
    uint length1;

    int count1;
    string SmartGuess;
    int iterator;
    int iterator1;
    int bullSol;
    int succes;
    int arrGuess[15];
    bool four;
 

    
  /////////counstractors/////////////
    SmartGuesser(){}
    SmartGuesser(const string& str)
    {
       Guess = str;
       count1=0;
       iterator=0;
       iterator1=0;
       bullSol=0;
       succes = 0;
       SmartGuess = "";
       four = false;
    }

    ///////////methods//////////////////
    void learn(string solutions) override;
    string guess() override;
    void startNewGame(uint length) override;
  };
}