#include<iostream>
#include<string.h>
using namespace std;


void printSS(string que,string ans)
{
  if(que.length()==0)
  {
    std::cout << ans << '\n';
    return;
  }

  char ch = que[0];
  string ros = que.substr(1);

  printSS(ros,ans);  // No wala call
  printSS(ros,ans+ch);  //yes wala call
}

void printSSAsci(string que,string ans)
{
  if(que.length()==0)
  {
    std::cout << ans << '\n';
    return;
  }

  char ch = que[0];
  string ros = que.substr(1);

  printSSAsci(ros,ans);  // No wala call
  printSSAsci(ros,ans+ch);  //yes wala call
  std::string s = std::to_string((int)ch);
  printSSAsci(ros,ans+s); //yes but with ascii
}


void printPerm(string que,string ans)
{
  if(que.length()==0)
  {
    std::cout << ans << '\n';
    return;
  }
for(int i=0;i<que.length();i++)
{
  char ch = que[i];
  string ros = que.substr(0,i)+que.substr(i+1);

  //printPerm(ros,ans);  // No wala call
  printPerm(ros,ans+ch);  //yes wala call
}
}
int main()
{
  //printSS("abc","");
  printPerm("abc","");

  return 0;
}
