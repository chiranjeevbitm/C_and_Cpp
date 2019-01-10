#include<iostream>
#include<cstring>
#include<cctype>
//#include<string.h>
//using namespace std;

void space(std::string str){
  int count = 0;
  int len = str.length();
  for(int i=0;i<len;i++){
    int c = str[i];
    if(isspace(c))
    count++;
  }
  std::cout << count << '\n';
}
int main(){
  std::string str = "my name is chiranjeev";
  space(str);
  return 0;

}
