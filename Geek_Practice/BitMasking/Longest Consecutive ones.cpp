#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	  int n;
	  cin>> n;
	  vector <int> v;
	  while(n!=0)
	  {
	      v.push_back(n%2);
	      n = n/2;
	  }
	  int c =0;
	  int m =0;

	  for(int i=0;i<v.size();i++)
	  {
	      if(v[i]==0)
	        c =0;
	      else
	      {
	        c++;
	        m = max(c,m);
	      }

	  }
	  cout<<m<<'\n';
	}

	return 0;
}
