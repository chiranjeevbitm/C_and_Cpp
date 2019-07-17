#include<iostream>
using namespace std;

void Swap(int a,int b)
{
  std::cout << a << "  "<< b << '\n';
  a= a^b;
  b= b^a;
  a= a^b;
  std::cout << a << "  "<< b << '\n';
}
int get_ith_bit(int n,int i)
{
  return (n&(i<<1))!=0? 1:0;
}
void set_ith_bit(int n,int i)
{
  int mask = i<<i;
   n = (n | mask);
   std::cout << n << '\n';
}
void ClearIthBit(int n,int i)
{
  int mask = ~(1<<i);
  n = n & mask;
  std::cout << n << '\n';
}

// Generate all subsets using Bitmasking
void Filterchar(char *a,int no)
{
  int i = 0;
  while(no>0)
  {
    (no&1)? cout<<a[i]:cout<<"";
    i++;
    no = no>>1;
  }
  cout<<"\n";
}
void generateSubset(char *a)
{
  int n = strlen(a);
  int range = (1<<n) -1;
  for(int i=0;i<=range;i++)
    Filterchar(a,i);
}


int main()
{
  //Swap(5,6);
  //cout<<get_ith_bit(13,1)<<'\n';
  //set_ith_bit(13,1);
    //ClearIthBit(13,2);
    char a[100];

    cin>>a;
    generateSubset(a);

  return 0;
}
