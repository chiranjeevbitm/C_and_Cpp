#include<iostream>
#include<queue>
using namespace std;
void BFS(int x,int n)
{
  queue<int>q;
  q.push(n);
  while(!q.empty())
  {
    n = q.front();
    q.pop();

    if(n<=x)
    {
      std::cout << n << " ";
      int ld = n%10;
      if(ld == 0)
        q.push((n*10)+(ld+1));
      else if(ld == 9)
        q.push((n*10)+(ld-1));
      else
        {
          q.push((n*10)+(ld-1));
          q.push((n*10)+(ld+1));
        }
    }
  }
}
void printJumpingNumber(int x)
{
  std::cout << 0 << " ";
  for(int i=1;i<=9&& i<=x;i++)
  BFS(x,i);
  std::cout << '\n';
}
int main()
{
  int t,n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    printJumpingNumber(n);
  }
  return 0;
}
