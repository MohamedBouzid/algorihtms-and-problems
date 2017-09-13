#include<bits/stdc++.h>

using namespace std;

/* Longest Common Substring problem bottom up solution */
int lcs(string s1, string s2){

	int l1 = s1.size();
	int l2 = s2.size(); 
	int dp[l1+1][l2+1];

	for(int i=0;i<=l1;i++){
		dp[i][0] = 0;
	}
	for(int j=0;j<=l2;j++){
		dp[0][j] = 0;
	}
	int max_length = 0;

	for(int i=1;i<=l1;i++){
		for(int j=1;j<=l2;j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}else
				dp[i][j] = 0;
			max_length = max(max_length,dp[i][j]);
		}
	}
	return max_length;
}


int main(){

  string X = "lkdfjghflskghkfg";
  string Y = "fkqskbgvjfsbklnfb";
 	cout<<"lcs = "<<lcs(X,Y)<<"\n";

	return 0;
}
