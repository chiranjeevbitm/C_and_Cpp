#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
  priority_queue <int> pq;
  int a[10] = {1,4,11,14,15,2,5};
  for(int i=0;i<7;i++)
  pq.push(a[i]);

  while(!pq.empty())
  {
    cout<<pq.top()<< " ";
    pq.pop();
  }
}
