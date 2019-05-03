#include<iostream>
#include "Guesser.hpp"
#include<vector>

using namespace std;
// using namespace bullpgia;

namespace bullpgia{
      

  class SmartGuesser: public bullpgia::Guesser{

    private :
    string Guess;

    public :
    uint length;
    int turns;
 //   int *arr2 = new int [10];
    vector<int> vec;
    int iterator;
    int bull;
    int pgia;
    int indexsucces ;
    int iterator1;
    string smartg;


    SmartGuesser(){
          

    }
    SmartGuesser(const string& str){
       Guess = str;
       turns=0;
       iterator=0;
       bull=0;
       pgia=0;
      indexsucces=0;
      iterator1=0;
      



    }
    void learn(string solutions) override ;
    string guess() override;
    void startNewGame(uint length) override;
    string algo();
  };
}