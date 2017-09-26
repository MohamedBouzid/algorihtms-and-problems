#include<bits/stdc++.h>

using namespace std;

int paths(int n, int m){

	if(n==1 || m==1) 
		return 1;

	return  paths(n-1,m)+paths(n,m-1);
}

int rec_paths(int n, int m){
	int dp[n][m];
	for(int i=0;i<n;i++){
		dp[i][0] = 1;
	}
	for(int j=0;j<n;j++){
		dp[0][j] = 1;
	}
	dp[0][0] = 0;
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][j];
		}
	}
	return dp[n-1][m-1];
}

int main(){

	cout<<"number of paths : "<<paths(5,4)<<"\n";
	cout<<"number of paths : "<<rec_paths(5,4)<<"\n";

	return 0;
}
