#include<iostream>
#include<set>
using namespace std;

void demoSet()
{
  set<int> S;
  S.insert(1);
  S.insert(2);
  S.insert(-1);
  S.insert(-12);

   for(int x : S)
      std::cout << x << '\t';

// search an element
auto it = S.find(-1);
if(it == S.end())
{
  std::cout << "not present" << '\n';
}else
{
std::cout << "present" << '\n';
std::cout << *it << '\n';
}

auto it2 = upper_bound(-1);// will return 1
auto it3 = upper_bound(0);// will return 1
std::cout << *it2 <<" "<< *it3<< '\n';


}
int main()
{
  demoSet();
}
