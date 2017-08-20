#include<bits/stdc++.h>

using namespace std;

/* Count number of ways to reach destination in a Maze */

int mazeways(int maze[][4]){

	if(maze[0][0]==-1)
		return 0;
	int mat[4][4];
  mat[0][0] = 0;
	mat[1][0] = maze[1][0]+1;
	mat[0][1] = maze[0][1]+1;
	for(int i=2;i<4;i++){
		if(maze[i][0]==-1)
			mat[i][0]=0;
		else 
			mat[i][0] = mat[i-1][0];
	
  	if(maze[0][i]==-1)
			mat[0][i]=0;
		else 
			mat[0][i] = mat[0][i-1];
	}
	for(int i=1;i<4;i++){
		for(int j=1;j<4;j++){
			if(maze[i][j]==-1)
					mat[i][j]=0;
			else if(i==0 || j==0 && i!=j)
				mat[i][j]=1;
			else{
				mat[i][j] = mat[i-1][j]+mat[i][j-1];			
			}
		}
	}
	return mat[3][3];
}

int main(){

	int maze[4][4] =     {{0, -1, 0, 0},
                       {0, -1, 0, 0},
                       {-1,-1, 0, -1},
                       {0,  0, 0, 0}};
  cout << mazeways(maze)<<"\n";
	return 0;
}
