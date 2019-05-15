#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  vector<char>v(10);
  for(int i=0;i<10;++i)
  {
    std::cin >> v[i];
  }
  vector<char>v2(10);
  reverse_copy(v.begin(),v.end(),v2.begin());
  for(int i=0;i<v2.size();++i)
  {
    std::cout << v2[i] << " ";
  }
}
