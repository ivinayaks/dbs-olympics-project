#include <bits/stdc++.h>

using namespace std;

long long int merge(int arr[],int temp[],int left,int mid, int right){
	int i,j,k;
	long long int count = 0;
	i=left; j=mid; k=left;
	while((i<=mid-1) && (j<=right)){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			count+=mid-i;	
		}
	}
	while(i<=mid-1){
		temp[k++] = arr[i++];
	}
	while(j<=right){
		temp[k++] = arr[j++];
	}
	for(i=left;i<=right;i++){
		arr[i] = temp[i];
	}
	return count;
}

long long int mergeSort( int arr[],int temp[],int left,int right){
	int mid;
	long long int count = 0;
	if(right>left){
		mid = (left+right)/2;
		count+=mergeSort(arr,temp,left,mid);
		count+=mergeSort(arr,temp,mid+1,right);
		count+=merge(arr,temp,left,mid+1,right);
	}
	
	return count;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[] = {5,3,2,4,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int temp[n];
	long long int count = mergeSort(arr,temp,0,n-1);
	cout<<count;
	return 0;
}

