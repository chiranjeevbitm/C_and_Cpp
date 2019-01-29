#include<iostream>

int main()
{
int i,n,t,x;
std::cin >> t;
while(t--)
{
    std::cin >> n;
    int sum = (n*(n+1))/2;
    for(i=0;i<n-1;i++)
    {
      std::cin >> x;
      sum -= x;
    }
    std::cout << sum << '\n';

}
}
