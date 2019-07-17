#include<iostream>
using namespace std;

void findUnique2(int *a,int n)
{
  // XOR all elements
  int res =0;
  for(int i=0;i<n;i++)
  {
    res = res ^ a[i];
  }
  // find rightmost set Bit
  int i =0;
  int temp = res;
  while(temp>0)
  {
    if(temp&1)
    {
    break;
    }
    i++;
    temp = temp>>1;
  }
  int mask = (1<<i);
  int FirstNo = 0;
  for(int i=0;i<n;i++)
  {
    if((mask & a[i])!=0)
    FirstNo = FirstNo^a[i];
  }
  int SecNo = FirstNo^res;
  std::cout << FirstNo << ' ';
  std::cout << SecNo << '\n';
}


int main() {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        findUnique2(a,n);

	return 0;
}
