#include <iostream>
using namespace std;
int main()
{
  int t;
  cin>> t;
  while(t--)
  {
    int N;
    cin>> N;
    int primeFactor = 2;
    while(primeFactor*primeFactor <= N) {
      if(N % primeFactor == 0) {
        N /= primeFactor;
      }
      else {
        primeFactor++;
          }
      }
      cout<<N<<'\n';


  }
}
