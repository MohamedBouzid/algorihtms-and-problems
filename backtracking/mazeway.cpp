#include<bits/stdc++.h>

using namespace std;
#define N 4

/* Look for a way out of the maze */
void init_mat(int n, int mat[4][4]){

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			mat[i][j]=0;
}

void print_mat(int n, int mat[4][4]){

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<mat[i][j]<<" ";
		cout<<"\n";
	}
}

bool is_valid(int x, int y, int mat[4][4]){
	return (x>=0 && y>=0 && x<4 && y<4 && mat[x][y]==1);
}
bool maze(int mat[4][4], int sol[4][4], int x, int y){


	sol[x][y] = 1;
	if(x==N-1 && y==N-1){
		sol[x][y] = 1;
		return true;
	}
	if(is_valid(x,y,mat)){
		
		if(maze(mat,sol,x,y+1) == true)
			return true;
		else if(maze(mat,sol,x+1,y) == true)
			return true;
	}
	sol[x][y] = 0;
	return false;
}

void solve(){
	
	int mat[4][4] = { {1, 1, 0, 0},
										{1, 0, 0, 1},
										{1, 1, 0, 0},
										{1, 1, 1, 1}
									};
	int sol[4][4];
	init_mat(4,sol);
	sol[0][0] = 1;
	if(maze(mat, sol, 0, 0))
		print_mat(4,sol);
	else
		cout<<"NO WAY YOU STUCK";
}

int main(){

	solve();
	return 0;
}
