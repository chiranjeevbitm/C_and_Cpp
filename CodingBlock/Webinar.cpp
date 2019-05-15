#include<iostream>
#include<algorithms>
#include<vector>
using namespace std;

void BirthdayParadox()
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
}
void bigmult(int *a,int &n,int no)
{
  int carry =0;
  for(int i=0;i<n;i++)
  {
    int product = a[i]*no +carry;
     a[i] = product%10;
    carry = product/10;
    }
    //left out carry
    while(carry)
    {
      a[n] = carry%10;
      carry = carry/10;
      n++;
    }
}
void bigFact(int number)
{
  int *a = new int[1000]{0};
 a[0] = 1;
  int n = 1;
  for(int i=2;i<=number;i++)
  {
    bigmult(a,n,i);
  }
  //print the digits in the reverse order
  for(int i = n-1;i>=0;i--)
  cout << a[i];
}

/*

remove_if
reverse_copy
lower_bound
merge
next_permutation

*/

int main()
{
  //BirthdayParadox();
//  bigFact(10);
  
  return 0;
}
