using namespace std;
int main()
 {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
	    int leader[n];
	    leader[n-1]=1;
	    int max = n-1;
	    for(int i=n-2;i>=0;i--){

	        if(arr[i]>=arr[max]){
	            max = i;
	            leader[i]=1;//cout<<i<<" ";
	        }
	        else leader[i]=0;
	    }
	    for(int i=0;i<n;i++){
	        if(leader[i]==1)cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
