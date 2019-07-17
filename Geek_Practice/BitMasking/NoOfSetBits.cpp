#include<iostream>
using namespace std;

int CountsetBits(int n)
{
  int count= 0;
  while(n>0)
  {
    count += (n&1);
    n = n >> 1;
  }
  return count;

}
int CountsetBitsFast(int n)
{
  int count= 0;
  while(n>0)
  {
    count ++;
    n = n&(n-1);
  }
  return count;

}
int TotalsetBitsFast(int n)
{
  int sum =0;
  for(int i=1;i<=n;i++)
  {
    sum = sum + CountsetBitsFast(i);
  }
  return (sum);
}
int main()
{
  int n;
  cin >> n;
  //cout<< CountsetBits(n)<<'\n';
  //cout<< CountsetBitsFast(n)<<'\n';
  std::cout << TotalsetBitsFast(n) << '\n';
  return 0;
}
