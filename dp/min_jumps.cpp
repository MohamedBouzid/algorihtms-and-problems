#include<bits/stdc++.h>

using namespace std;


int min_jumps(int array[], int n, int i){
	int mi = INT_MAX;
  if(array[i]==0)
		return 0;
	if(i>=n)
		return 0;
	else{

		for(int j=i+1;j<=i+array[i] && i<=n;j++)
			mi = min(mi, min_jumps(array,n,j)+1);

	}
	return mi;

}


int main(){

	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"Minimum number of jumps to reach end is : "<<min_jumps(arr,n-1,0));

	return 0;
}
