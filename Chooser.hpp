#pragma once
#include <string>

using namespace std;

namespace bullpgia{

  class Chooser{
  private:
    string Choose;
  public :
    Chooser(){
      Choose = "";
    }
    Chooser(const string& str){
      Choose = str;
    }
    virtual ~Chooser(){}
    virtual string choose(uint length) = 0;
    uint length();
    
  };
}