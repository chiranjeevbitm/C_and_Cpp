#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

void Swap(int *a,int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
// 1

void SelectionSort(int a[],int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    int min_idx = i;
    for(j=i+1;j<n;j++)
    {
      if(a[j]<a[min_idx])
      min_idx = j;
    }
    Swap(&a[i],&a[min_idx]);
  }
}

// 2

void IterBubbleSort(int a[],int n)
{
  for(int i=0;i<n;i++)
  {
    int swapped = 0;
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      Swap(&a[j],&a[j+1]);
      swapped = 1;
    }
    if(swapped==0)    // Stops to make extra useless call
    break;
  }
}

// 3

void RecBubbleSort(int a[],int n)
{
  if(n==0)
  return;

  for(int i=0;i<n-1;i++)
  {
    if(a[i]>a[i+1])
    Swap(&a[i],&a[i+1]);
  }
  RecBubbleSort(a,n-1);
}

//4

void ItrInsertionSort(int a[],int n)
{
  int j,key;
  for(int i =1;i<n;i++)
  {
     key = a[i];
     j = i-1;

  while(j>=0 && a[j]>key)
  {
    a[j+1] =  a[j];
    j= j-1;
  }
    a[j+1] = key;
  }
}
// 5


void RecInsertionSort(int a[],int n)
{
  if(n<=1)  return;
  RecInsertionSort(a,n-1);
  int last = a[n-1];
  int j = n -2;
  while(j>=0 && a[j]>last)
  {
    a[j+1] =  a[j];
    j--;;
  }
    a[j+1] = last;

}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];
  i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
// 6


void RecmergeSort(int arr[], int l, int r)
{
	if (l < r)
	{

		int m = l+(r-l)/2;

		RecmergeSort(arr, l, m);
		RecmergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

int min(int a,int b)
{
  return (a<b) ? a:b;
}

// 7


void ItrmergeSort(int a[],int n)
{
  int cur;
  int l;
  for(cur=1;cur<=n-1;cur=2*cur)
  {
    for(l = 0;l<n-1;l+=2*cur)
    {
      int m = l +cur-1;
      int r = min(l+2*cur-1,n-1);
      merge(a,l,m,r);
    }
  }
}

int Partition(int a[],int l,int r)
{
  int p = a[r];
  int i = l-1;
  for(int j = l;j<=r-1;j++)
  {
    if(a[j]<=p)
    {
      i++;
      Swap(&a[i],&a[j]);
    }
  }
  Swap(&a[i+1],&a[r]);
  return i+1;
}

// 8
void RecQuickSort(int a[],int l,int r)
{
  if(l<r)
  {
    int pi = Partition(a,l,r);
    RecQuickSort(a,l,pi-1);
    RecQuickSort(a,pi,r);
  }
}
// 9
void ItrQuickSort(int a[],int l,int r)
{
  int stack[r-l+1];
  int top = -1;
  stack[++top] = l;
  stack[++top] = r;
  while(top>=0)
  {
    r = stack[top--];
    l = stack[top--];
    int pi = Partition(a,l,r);
    if(pi-1>l)
    {
      stack[++top] = l;
      stack[++top] = pi-1;
    }
    if(pi<r)
    {
      stack[++top] = pi+1;
      stack[++top] = r;
    }
  }
}
// 10

void Partition3WayQS(int a[],int l,int h,int &i,int &j)
{
  // Handling for two elements
  if(h-l<=1)
  {
    if(a[h]-a[l]<=1)
      Swap(&a[h],&a[l]);
      i=l;
      j=h;
    return;
  }
  int mid = l;
  int pivot = a[h];
  while(mid<=h)
  {
    // part 1 a[l...i]  ie  swap(a[l++],a[mid++])
    if(a[mid]<pivot)
      Swap(&a[l++],&a[mid++]);
    // part 2 a[i+1...j-1]
    else if(a[mid]==pivot)
      mid++;
    // part 3 a[j...h]
    else if(a[mid]>pivot)
      Swap(&a[mid],&a[h--]);

  }
  i=l-1;
  j= mid;
}

void threeWayQS(int a[],int l,int h)
{
  if(l>=h)
    return;
  int i,j;
  Partition3WayQS(a,l,h,i,j);
  threeWayQS(a,l,i);
  threeWayQS(a,j,h);
}

// 11
int RandomisedQSPartition(int a[],int l,int r)
{
  int i = l+rand()%(r-l+1);
  Swap(&a[r],&a[i]);
  return Partition(a,l,r);
}

void RandomisedQS(int a[],int l,int r)
{
  int pi;
  if(l<r)
  {
   pi = RandomisedQSPartition(a,l,r);
    RandomisedQS(a,l,pi-1);
    RandomisedQS(a,pi,r);
  }

}

void printArray(int A[], int size)
{
	int i;
	for (i=0; i < size; i++)
	std::cout << A[i]<<' ';
	std::cout  << '\n';
}
// 12
void Heapify(int a[],int n,int i)
{
  int largest = i;
  int l = 2*i +1;
  int r = 2*i +2;
  if(l<n && a[l]>a[largest])
    largest =l;
  if(r<n && a[r]>a[largest])
    largest =r;
  if(largest!=i)
  {
   Swap(&a[i],&a[largest]);
   Heapify(a,n,largest);
  }
}
void Heapsort(int a[],int n)
{
  for(int i = n/2 -1;i>=0;i--)
    Heapify(a,n,i);
  for(int i = n-1;i>=0;i--)
    {
      Swap(&a[0],&a[i]);
      Heapify(a,i,0);
    }
}

// 13
void BucketSort(float a[],int n)
{   // 1
    vector<float> b[n];
    // 2
    for(int i =0;i<n;i++)
    {
      int bi = n*a[i];
      b[bi].push_back(a[i]);
    }
    // 3
    for(int i=0;i<n;i++)
    {
    sort(b[i].begin(),b[i].end());
    }
    // 4
    int index = 0;
    for(int i=0;i<n;i++)
      for(int j=0;j<b[i].size();j++)
        a[index++] = b[i][j];
}
void printfloatArray(float A[], int size)
{
	int i;
	for (i=0; i < size; i++)
	std::cout << A[i]<<' ';
	std::cout  << '\n';
}
int getMax(int a[],int n)
{
  int mx = a[0];
  for(int i =0;i<n;i++)
  {
    if(a[i]>mx)
     mx = a[i];
  }
  return mx;
}
// 14
// sort according to digits
void CountSort(int a[],int n,int exp)
{
  int output[n];
  int i,count[10] ={0};
  for(int i=0;i<n;i++)
    count[(a[i]/exp)%10]++;
  for(int i =1;i<10;i++)
    count[i] +=count[i-1];
    
}
int main()
{
  int a[] = {5,40,3,2,1,9,6,8,7};
  //float ab[] = {0.35,0.12,0.43,0.15,0.04,0.50,0.132};
  //int a[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
  int n = sizeof(ab)/sizeof(ab[0]);
  //SelectionSort(a,n);
  //IterBubbleSort(a,n);
  //RecBubbleSort(a,n);
  //ItrInsertionSort(a,n);
  //RecInsertionSort(a,n);
  //RecmergeSort(a,0,n-1);
  //ItrmergeSort(a,n);
  //RecQuickSort(a,0,n-1);
  //ItrQuickSort(a,0,n-1);
  //printArray(a,n);
  //threeWayQS(a,0,n-1);
  //RandomisedQS(a,0,n);
  //Heapsort(a,n);
  //BucketSort(ab,n);
  //printfloatArray(ab,n);
  printArray(a,n);

}
