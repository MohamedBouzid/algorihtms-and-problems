#include<bits/stdc++.h>

using namespace std;

/* Iterative Longest Common Subsequence */
int lscs(int tab[], int n){
	int m=0;
	int mat[n][n];
	for (int i=0;i<n;i++){
		for( int j=i;j<n;j++){
			if(j==i)
				mat[i][j]=tab[i];
			else
				mat[i][j]=mat[i][j-1]+tab[j];
			if(m<mat[i][j])
				m=mat[i][j];
		}
	}
	return m;
}
int main(){
	int tab[]={5,-2,3,4,10};
	cout<<lscs(tab,5)<<"\n";
	return  0;
}
