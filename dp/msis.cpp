#include<bits/stdc++.h>

using namespace std;

int find_index(int arr[], int index){
	
	for(int i=index-1;i>=0;i--){
		if(arr[i]<arr[index])
			return i;
	}
	return -1;
}
/* Maximum Sum Increasing Subsequence problem bottom up solution */
int msis(int arr[], int n){
	
	int msis[n];
	
	int max_sum = 0;
	for(int i=0;i<n;i++){
		if(arr[i-1]<arr[i])
			msis[i] = arr[i] + msis[i-1];
		else{
			int index = find_index(arr,i);
			if(index!=-1){
				msis[i] = msis[index] + arr[i];
			}else
				msis[i] = arr[i];
		}
		if(max_sum<msis[i])
			max_sum = msis[i];
			
	}
	return max_sum;
	
}

int main(){

	int arr[] = {1, 101, 2, 3, 100, 4, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  int s = msis(arr,n);
	cout<<"max sum : "<<s<<"\n";
	return 0;

}

