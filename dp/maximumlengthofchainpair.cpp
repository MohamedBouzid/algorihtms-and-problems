#include<bits/stdc++.h>

using namespace std;

bool compare(pair<int,int>  a, pair<int,int>  b){
	return a.first < b.first;
}
/* Recursive Max chain length */
int chain(pair<int,int> arr[], int n){
	int x=0,y=0;
	if(n==0)
		return 1;
	if(arr[n].first > arr[n-1].second)
		x = chain(arr, n-1)+1;
	else
		y=chain(arr, n-1);
	return max(x,y);
}

int iterativechain(pair<int,int> arr[], int n){
	

}
int main(){

  pair<int,int> arr[] = { make_pair(5, 24), make_pair(15, 25), make_pair(50, 60) ,
                        make_pair(27, 90), make_pair(70, 80) };
  int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr, arr+n, compare);
	cout<<chain(arr, n-1);
	return 0;
}
