#include <string>
#include "SmartGuesser.hpp"

using namespace std;
 
void bullpgia::SmartGuesser:: learn(string solutions) 
{
     bullSol = atoi(&solutions[0]);
     pgiaSol = atoi(&solutions[1]);
   if(count1<10 && iterator<4)
   {
       
        for(size_t i = 0; i < bullSol; i++)
        {
            arrGuess[iterator]=count1; 
            iterator++; 
        } 
           count1++;
  
   }
   else 
   {      count1=10;
       if(bullSol == 1)
       { 
           SmartGuess = SmartGuess + to_string(arrGuess[iterator1]);
           succes++;
           iterator1 = 0;
                   cout<<"asdasd"<<succes<<"gal"<<endl;

       }
       else
       {
                              cout<<"iterator1:"<<iterator1<<"gal"<<endl;

        if(four == true)
            {
        iterator1++;
            }
            four=true;
       }
       

   }
}

void bullpgia::SmartGuesser:: startNewGame(uint length)
{
    iterator=0;
    count1=1;
    iterator1=0;
    succes=1;
     four=false;
}

string bullpgia::SmartGuesser:: guess()
{   
    switch (count1)
    {
        case 1:
            return "1111";
            break;
        case 2:
            return "2222";
            break;
        case 3:
            return "3333";
            break;
        case 4:
            return "4444";
            break;
        case 5:
            return "5555";
            break;
        case 6:
            return "6666";
            break;
        case 7:
            return "7777";
            break;
        case 8:
            return "8888";
            break;
        case 9:
            return "9999";
        case 10:
    
        int ch='g';
                                  cout<<"iterator1:"<<iterator1<<"oria"<<endl;

        cout<<"last sucess"<<succes<<"roi"<<endl;
            if(iterator1<4){
             ch = arrGuess[iterator1];

            }
            
            switch(succes)
            { 
                case  1:
                    return to_string(ch)+"***";
                    break;
                case 2:
                    return "*"+to_string(ch)+"**";
                    break;
                case 3:
                    return "**"+to_string(ch)+"*";
                    break;
                case 4:
                    return "***"+to_string(ch);
                    break;
                case 5:
                cout<<"win"<<endl;
                    return SmartGuess;
                    break;
            }
        
    }
    
    return "1234";
}
