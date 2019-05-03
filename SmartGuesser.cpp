#include <string>
#include "SmartGuesser.hpp"
#include<vector>


using namespace std;
 
void bullpgia::SmartGuesser:: learn(string solutions) {
     bull=atoi(&solutions[0]);
     pgia=atoi(&solutions[1]);
     vec.push_back(2);
    cout<<vec[0]<<"asdsad"<<endl;
   if(turns<10){
        for(int i = 0; i < bull-1; i++)
        {
            cout<<turns<<"shira"<<endl;
         //  vec.push_back(turns);
           //cout<<vec[iterator]<<"hasdhsad"<<endl;

       // arr2[iterator]=turns;  
       cout<<bull-1<<endl;
        iterator++; 
        
        }   
   }else {
       if(bull==1){
         //  smartg= smartg +to_string(vec[iterator1]);
          // smartg= smartg +to_string(arr2[iterator1]);
           indexsucces++;
           iterator1=0;

       }
       else{
           iterator1++;
       }


   }
   turns++;
   
   
}

void bullpgia::SmartGuesser:: startNewGame(uint length) {
    cout << "test start new game" << endl;
    vec = {};
    turns=1;
       iterator=0;
       bull=0;
       pgia=0;
      indexsucces=0;
      iterator1=0;
   

    
}

string bullpgia::SmartGuesser:: guess(){
    switch (turns)
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
        default:
            
         //  int ch=arr2[iterator1];
         int ch =vec[iterator1];
            switch (indexsucces)
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
        default:
             return smartg;
             break;
    }

    }
    
    return "roi bana";
}
