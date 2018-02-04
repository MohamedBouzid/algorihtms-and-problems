#include <bits/stdc++.h>

using namespace std;
#define N 8

void print_mat(int mat[N][N]){

	for( int i=0;i<N;i++ ){
		for(int j=0;j<N;j++ ){
			if(mat[i][j]/10 !=0)
				cout<<mat[i][j]<<" ";
			else
				cout<<mat[i][j]<<"  ";
		}
		cout<<"\n";
	}
}

bool is_valid(int board[N][N], int row, int col)
{
    int i, j;
 
    /* Check this row on left side */
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
 
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 
/*bool is_valid(int mat[N][N], int x, int y){
	int z,w;
	if(y>x){
		z=0;
		w=y-x;
	}else{
		z=0;
		w=x-y;
	}
	int r=0;
	int c=0;
	int rd=0;
	int ld=0;
	for(int i=0;i<N;i++){
		c+=mat[x][i];
		r+=mat[i][y];
		if(z+i<N && w+i<N){
		rd+=mat[z+i][w+i];
		ld+=mat[z-i][w-i];}
		if(c>1 || r>1 || rd>1 || ld>4)
			return false;
	}	
	return  true;
}*/
bool solve(int mat[N][N], int n){
	if(n>=N+1)
		return true;
	for(int i=0;i<N;i++){

		if(is_valid(mat,i,n)){
			mat[i][n] = 1;
			if(solve(mat,n+1)==true)
				return true;
			else
				mat[i][n] = 0;
		}
		
	}
	return false;

}
void init_mat(int mat[N][N]){

	for( int i=0;i<N;i++ ){
		for(int j=0;j<N;j++ ){
			mat[i][j] = 0;
		}
	}
}

int main(){

	int mat[N][N] ;
	init_mat(mat);

	if(is_valid(mat,0,0))
		cout<<"YESSSS";

	if(solve(mat,0))
		print_mat(mat);
	else
		cout<<"NO WAY";
	return 0; 

}
