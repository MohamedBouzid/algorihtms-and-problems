#include<bits/stdc++.h>

using namespace std;
#define M 1000
#define N 1000


/* Recursive Min Cost Path */

int mincost(int n, int m, int cost[M][N]){

	if(n==0 && m==0)
		return cost[n][m];
	else if( n==0 && m!=0)
		return cost[n][m]+mincost(n,m-1,cost);
	else if( n!=0 && m==0)
		return cost[n][m]+mincost(n-1,m,cost);
	else	
		return cost[n][m]+min(min(mincost(n-1,m,cost),mincost(n,m-1,cost)),mincost(n-1,m-1,cost));


}

/* Iterative Min Cost Path */
int iterative_mincost( int n, int m, int cost[M][N]){

	int costsum[n+1][m+1];
	costsum[0][0]=cost[0][0];
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			if(i==0 && j!=0)			
				costsum[i][j]=cost[i][j]+costsum[i][j-1];
			if(i!=0 && j==0)			
				costsum[i][j]=cost[i][j]+costsum[i-1][j];			
			else 
				costsum[i][j]=min(costsum[i-1][j],min(costsum[i][j-1],costsum[i-1][j-1]))+cost[i][j];
				
		}
	}
	return costsum[n][m];
}

int main(){

	int cost[M][N] = {  {1, 2, 3, 4},
                      {4, 8, 2, 7},
                      {1, 5, 3, 5},
											{2, 7, 6, 3} };
   cout<<" recursive min cost is : "<< mincost( 3, 3,cost);
   cout<<" iterative min cost is : "<< iterative_mincost( 3, 3,cost);
   return 0;
}
