#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int fact(int n)
{
  if (n == 0)
    return 1;


  return n * fact(n - 1);
}
int main()
{
  vector<int>v(5);
  for(int i=0;i<5;++i)
  {
   cin >> v[i];
  }
   fact()
  next_permutation(v.begin(),v.end());
  for(int i=0;i<5;++i)
  {
    cout << v[i] << " ";
  }
}
