s#include<bits/stdc++.h>

using namespace std;

/* Recursive Binomial Coefficient */
int c(int n, int k){

	if(k==0 or n==k)
		return 1;
	else
		return c(n-1,k-1)+c(n-1,k);

}

/* Iterative Binomial Coefficient with */
int c_it(int n, int k){
	int tab[n][c];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0 || i==j)
				tab[i][j]=1;
			else if(i>0 && j>0)
				tab[i][j]=tab[i-1][j-1]+tab[i-1][j];

		}
	}
	return tab[n][k];
}
int main(){

	/* recursive */
	cout<<c(5,2)<<"\n";
	/* vs */
	/* iterative */
	cout<<c_it(5,2)<<"\n";

	return  0;
}
