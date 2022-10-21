#include <bits/stdc++.h>
using namespace std;


/* Maximum Length Biotonic subsequence : a pivot is given then biotonic subsequence is first increasing upto 
pivot value index then decreasing */

/* find lis array and store it in first array and then find lis from last to calculate longest decreasing subsequence (LDS)
and store it in arr-2 then find index of pivot and return (lis[ind] + lds[ind] -1)*/


int LIS(vector<int> &arr,int n,int index){
	vector<int> lis(n);
	lis[0]=1;
	for (int i = 1; i < n; ++i)
	{
		lis[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if (arr[j]<arr[i])
			{
				lis[i]=max(lis[i],lis[j]+1);
			}
		}
	}

	return lis[index];
}

// Using Binary Search O(nlogn) 

int ceilInx(vector<int> tail,int l,int r,int x){
	int m;
	while(r>l){
		m=l+((r-l)/2);
		if (tail[m]>=x)
		{
			r=m;
		}
		else{
			l=m+1;
		}
	}
	return r;
}

int lds(vector<int> &arr,int n,int index){
	vector<int> lis(n,0);
	lis[n-1]=1;
	for (int i = n-2; i >=0 ; --i)
	{
		lis[i]=1;
		for (int j = n-1; j >i ; --j)
		{
			if (arr[j]<arr[i])
			{
				lis[i]=max(lis[i],lis[j]+1);
			}
		}
	}

	return lis[index];
}

// lbs= longest biotonic subsequence
int lbs(vector<int> arr,int n,int pivot){

	int index=ceilInx(arr,0,n-1,pivot);
	return (lds(arr,n,index)+LIS(arr,n,index)-1);
}

int main(){
	int n,x;
	cin>>n;
	vector<int> v;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>x;
		arr[i]=x;
	}
	cout<<lbs(arr,n,10)<<endl;

	return 0;
}