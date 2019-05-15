#include<iostream>
using namespace std;

int main()
{
  float Nr = 365;
  float Dr = 365;

  float p =1;
  int n =0 ;
  while(p>0.5)
  {
    p = p*(Nr)/Dr;
    Nr--;
    n++;
    cout << "probability is "<< p <<" No of peoples are "<<n <<"\n";
  }
  return 0;

}
