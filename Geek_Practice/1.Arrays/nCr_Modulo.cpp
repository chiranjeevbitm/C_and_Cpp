#define mod 1000000007
using namespace std;
int arr[1000][1000];


int ncr(int n,int r){
    if(r==1) return n;
    if(n<r) return 0;
    if(n==r) return 1;

    if(arr[n][r]!=-1) return arr[n][r]%mod;


    return arr[n][r]=(ncr(n-1,r-1)%mod + ncr(n-1,r)%mod)%mod;
}

int main()
 {
	//code
	memset(arr,-1,sizeof(arr));
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;
        cout<<ncr(n,r)<<endl;
    }
    return 0;
}
