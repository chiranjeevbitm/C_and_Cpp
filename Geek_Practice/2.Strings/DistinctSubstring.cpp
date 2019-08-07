#include<iostream>
#include<set>
#include <iterator>
using namespace std;

void generate(set<string> &st,string s)
{
  if(s.size()==0) return;
  if(st.find(s)==st.end())
  {
    st.insert(s);

  for(int i=0;i<s.size();i++)
  {
    string t = s;
    t.erase(i,1);
    generate(st,t);
  }
}
  return;
}
int main()
{
    string s;
    cin>>s;
    set<string> st;
    set<string>::iterator it;
    generate(st,s);
    for(auto it=st.begin();it!=st.end();it++)
      cout<< *it<<" ";
}
