#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;


void JumpNo(vector<int> &arr, ll i, ll n) {
    ll temp = arr[i]%10;
    // handle case for last digit is 0
    if (temp - 1 >=0 && arr[i]*10 + temp - 1 <= n) {
        arr.push_back(arr[i]*10 + temp - 1);
    }
    // handle case for last digit is 9
    if (temp + 1 <=9 && arr[i]*10 + temp + 1 <= n)
        arr.push_back(arr[i]*10 + temp + 1);
    if(i+1 >= arr.size())
        return;

    JumpNo(arr, i + 1, n);
}

int main()
 {
	vector<int> arr;
	int i, j;
	ll n;
	cin>>j;
	while (j--) {
	    cin>>n;
	    arr.clear();
	    for (i = 0; i <= 9; ++i) {
	        if (i<=n) {
	        arr.push_back(i);
	        }
	    }
	    if (i == 10)
	        JumpNo(arr, 1, n);
      //  for (auto &i : arr)
      for(i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
        cout<<endl;
	}
	return 0;
}
