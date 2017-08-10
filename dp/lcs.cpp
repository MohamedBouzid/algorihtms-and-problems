#include<bits/stdc++.h>

using namespace std;

/* Recursive Longest Common Sequence */
int lcs(string s1, string s2, int n, int m){
	if(n==0 || m==0)
		return 0;
	if(s1[n-1]==s2[m-1])
		return lcs(s1,s2,n-1,m-1)+1;
	else
		return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));

}


/* Iterative Longest Common Sequence */
int lcs_it(string s1, string s2, int n, int m){

	int mat[n+1][m+1];
	string s;
	for (int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
				if(i==0|| j==0)
					mat[i][j]=0;
			  else if(s1[i]!=s2[j])
					mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
				else{
					s=s+s1[i];
					mat[i][j]=mat[i-1][j-1]+1;
				}
		}
	}
	for (int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<s;
	return mat[n][m];
}



int main(){

	string s1="AGGTAB";
	string s2="GXTXAYB";
	cout<<lcs(s1,s2,6,7)<<"\n";
	cout<<lcs_it(s1,s2,6,7)<<"\n";
	cout<<lcs(s1,s2,6,7)<<"\n";
	return  0;
}
