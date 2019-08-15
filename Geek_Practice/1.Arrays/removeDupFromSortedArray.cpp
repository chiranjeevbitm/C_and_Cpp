#include<iostream>
using namespace std;

int remove_duplicate(int A[],int N)
{
    int j=0;
    for(int i=0;i<N-1;i++)
    {
        if(A[i]!=A[i+1])
          A[j++]=A[i];
    }
    A[j++] = A[N-1];

    return j;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    int n = remove_duplicate(a,sizeof(a)/sizeof(a[0]));
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
