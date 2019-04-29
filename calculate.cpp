#include <string>
#include"calculate.hpp"

using namespace std;
using namespace bullpgia;

string bullpgia::calculateBullAndPgia(const string& choice,const string& guess){
  string tempguess=guess;
    string tempchoice=choice;
    int bull=0;
    int pgia=0;
    for(size_t i = 0; i < choice.length(); i++)
    {
      if (choice[i]==guess[i]) {
        bull++;
        tempguess.erase(i,1);
        tempchoice.erase(i,1);
       
      }
    }
    if(tempchoice.length()>0)
    {
        for(size_t i = 0; i < tempchoice.length(); i++)
          {
          bool check = true; 
            for(size_t j = 0; j < tempchoice.length(); j++)
                {
                  if(check && tempchoice[i]==tempguess[j])
                  {
                    pgia++;
                    check=false;
                //            cout << tempguess << "pgia" <<  tempchoice << endl;

                  }
                }   
          }
    }
          
    

  string cc = to_string(bull)+","+to_string(pgia);
 
  return cc;
}