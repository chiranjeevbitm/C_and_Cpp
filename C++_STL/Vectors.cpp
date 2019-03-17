#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  //C++ stl
  vector<int> A = { 1,3,5,2,8 };
  std::cout << A[1] << '\n';

sort(A.begin(),A.end());    //O(NlogN)

bool present = binary_search(A.begin(),A.end(),3); //true
present = binary_search(A.begin(),A.end(),30);   //false

A.push_back(100);
A.push_back(100);
A.push_back(100);
A.push_back(100);
A.push_back(123);


// vector<int>:: iterator it = lower_bound(A.begin(),A.end(),100);   //   >=
// vector<int>:: iterator it2 = upper_bound(A.begin(),A.end(),100);   //   <

//or

auto it = lower_bound(A.begin(),A.end(),100);   //   >=
auto it2 = upper_bound(A.begin(),A.end(),100);   //   <


std::cout << it  << " " << it2 << '\n';
std::cout << it2 - it << '\n';  // O(1)

sort(A.begin(),A.end(),f);
vector<int>:: iterator it3;
// for(it3=A.begin(),it3!=A.end();it3++)
// {
//   std::cout << it3 << '\t';
//
// }
// or
for(inr x:A)
{
  std::cout << x << '\t';
}

}
