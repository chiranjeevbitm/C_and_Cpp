#include<iostream>
#include<cstring>

int main(){
  char str[] = "My name is chiranjeev";
  char ch = 'n';
  char *val = strrchr(str,ch);
  std::cout << "No of characters after "<<ch<<" are : " << val- str+1 << '\n';
  std::cout << "string after last "<< ch << " is :" << val <<'\n';
  return 0;
}
