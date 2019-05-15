#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
using namespace std;

bool comp(string a,string b)
{
  if (a.find(b) != std::string::npos)
    return (a.length()>b.length());


}
void StringSort(int t)
{
  //int t;

  string s[t];
  for(int i =0;i<t;i++)
  {
    cin>>s[i];
  }
  sort(s,s+t);
  sort(s,s+t,comp);
  for(int i =0;i<t;i++)
  {
    cout<<s[i]<<'\n';
  }

}

int main() {
  int k;
  cin>>k;
  StringSort(k);
	return 0;
}
