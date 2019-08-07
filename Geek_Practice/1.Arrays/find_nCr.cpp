#include <iostream>
#include<cmath>
//#define M 1000000007
using namespace std;


unsigned long long factorial(int n)
{
    const unsigned int M = 1000000007;


    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f = (f*i) % M;  // Now f never can
                        // exceed 10^9+7
    return f;
}
int main()
{
  int t;
  cin>> t;
  while(t--)
  {
    //std::cout << factorial(10) << '\n';
    int n,r;
    cin>>n>>r;
    if(n>=r)
    {
     long long result = (factorial(n))/((factorial(n-r))*(factorial(r)));

    cout<<result <<'\n';
    }
    else
    {
    cout<< 0<<'\n';
  }
  }


}
