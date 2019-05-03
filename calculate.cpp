#include <string>
#include"calculate.hpp"

using namespace std;
using namespace bullpgia;

string bullpgia::calculateBullAndPgia(const string& choice,const string& guess){
  string tempguess=guess;
    string tempchoice=choice;
   // cout<<tempchoice<<"vs"<<tempguess<<endl;
    int bull=0;
    int pgia=0;
    for(size_t i = 0; i < choice.length(); i++)
    {
      if (choice[i]==guess[i]) {
        int index = i-bull;
        tempguess.erase(index,1);
        tempchoice.erase(index,1);
                bull++;

       
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
                  }
                }   
          }
    }
          
    

  string cc = to_string(bull)+","+to_string(pgia);
 
  return cc;
}