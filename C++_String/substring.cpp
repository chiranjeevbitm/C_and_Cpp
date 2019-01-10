#include<iostream>
#include<string.h>
using namespace std;
int main(){
  string str = "cat:dog";
  int pos = str.find(':');
  string sub = str.substr(pos+1);
  std::cout << "string is :" <<sub<< '\n';
}
