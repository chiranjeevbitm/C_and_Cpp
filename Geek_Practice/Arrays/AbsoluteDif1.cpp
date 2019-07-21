#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;
int absdiff(int n){
    string str = to_string(n);
    int len=str.length();
    int i =0;int check=0;
    while (i<len-1){
            if(abs(str[i]-str[i+1])!=1){
              check=1;
              break;
            }
            i++;
    }
    if(check==0){
        cout<<n<<" ";
    }
    else if(check==1){
        return 0;
    }
}
int main()
 {
	int t;
	cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        long int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count=0,count2=0;
        for(int j=0;j<n;j++){
            if(arr[j]<k && arr[j]>10){
                count2++;
                if(absdiff(arr[j])==0){
                    count++;
                }
            }
        }
        if(count==count2){
            cout<<"-1 ";
        }
        cout<<"\n";
    }
    return 0;
}
