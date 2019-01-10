#include<iostream>
using namespace std;

void atDemo(string str)
{
    cout << str.at(5);

    // range exception as 16 > length()
    // cout << str.at(16);
  }
  void extractchar(string str){
    char ch;
    int len = str.length();

    for(int i=0;i<len;i++){
      ch = str.at(i);
      std::cout << ch << ' ';
    }
  }
  int main(){
    string str("my name is chiranjeev");
    extractchar(str);
    atDemo(str);
    return 0;
  }
