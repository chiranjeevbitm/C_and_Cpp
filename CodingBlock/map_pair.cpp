#include <iostream>
//#include<bits/stdc++.h>
#include <iterator>
#include <utility>
#include <map>
using namespace std;
int main() {
    typedef pair<int,int> ii;
    map<ii,string>table;
    int n;
    cin>> n;
    for(int i=0;i<n;++i)
    {
        ii code;
        string name;
        cin>> code.first >> code.second;
        cin>>name;
        table[code] =name;
    }
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
  {
      ii code;
        cin>>code.first>>code.second;
        cout<<table[code]<< '\n';
  }
}


//input 
// 4
// 5 2 anamika
// 6 4 yamuna
// -2 0 teacher
// 6 4 chitra
// 2
// -2 0
// 6 4
