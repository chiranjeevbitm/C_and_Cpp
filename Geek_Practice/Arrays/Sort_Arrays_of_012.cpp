#include<iostream>

int main()
{
int t;
std::cin >> t;
while(t--)
{
  int n,arr[999999];
  std::cin >> n;
  for(int i = 0;i<n;i++)
  std::cin >> arr[i];

  int z=0,o=0,t=0;
  for(int i = 0;i<n;i++)
  {
    if(arr[i]== 0) z++;
    if(arr[i]==1) o++;
    if(arr[i]==2) t++;

  }
  for(int i = 0;i<z;i++)  std::cout << 0 << ' ';
  for(int i = 0;i<o;i++)  std::cout << 1 << ' ';
  for(int i = 0;i<t;i++)  std::cout << 2 << ' ';
  std::cout  << '\n';
}


}
