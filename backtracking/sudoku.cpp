#include<bits/stdc++.h>

using namespace std;

void print_mat(int mat[9][9]){
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}	
}

bool zerofound(int mat[9][9]){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(mat[i][j]==0)		
				return true;
		}
	}
	return false;
}

bool is_valid(int mat[9][9], int x, int y, int nb){
	int z=(int)(x/3)*3;
	int w=(int)(y/3)*3;
	int cx,cy;
	for(int i=0;i<9;i++){
		cx=z+i/3;
		cy=w+i%3;

		if((mat[i][y] == nb && i!=x) || (mat[x][i] == nb && i!=y) ||(mat[cx][cy] == nb && cx!=x && cy!=y))
			return false;
	}
	return true;
}

bool solve(int mat[9][9], int x, int y){

	if(!zerofound(mat))
		return true;
	//cout<<"x = "<<x<<" y = "<<y<<"\n";
	if(mat[x][y] != 0)
		return solve(mat,x+(y+1)/9,(y+1)%9);
	for(int i=1;i<10;i++){
		if(is_valid(mat,x,y,i)){
			mat[x][y] = i;		
			if( solve(mat,x+(y+1)/9,(y+1)%9)==true)
				return true;
			mat[x][y] = 0;
		}
	}
	return false;
}

int main(){

	int mat[9][9] = 		{{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

	cout<<is_valid(mat,0,5,8)<<"\n";
	if(solve(mat,0,0))
		print_mat(mat);
	else
		cout<<"NO WAY";

	return 0;
}

