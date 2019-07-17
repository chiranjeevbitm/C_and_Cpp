#include<iostream>

using namespace std;

int main()
{
  string str = "aaabbbcccdeee";
  auto result = unique(str.begin(),str.end());
  cout<<string(str.begin(),result)<<'\n';
}
