#include <bits/stdc++.h>

using namespace std;
#define N 8
void print_mat(int mat[8][8]){

	for( int i=0;i<8;i++ ){
		for(int j=0;j<8;j++ ){
			if(mat[i][j]/10 !=0)
				cout<<mat[i][j]<<" ";
			else
				cout<<mat[i][j]<<"  ";
		}
		cout<<"\n";
	}
}

void print_list(list< pair<int,int> > li){

	list< pair<int,int> >::iterator i;
	for(i=li.begin();i!=li.end();i++)
		cout<<" i.first = "<<i->first<<" i.second =  "<<i->second<<"\n";
}

void c_list(list< int > li){

	list< int >::iterator i;
	for(i=li.begin();i!=li.end();i++)
		cout<<" i = "<<*i<<"\n";
}

void init_mat(int mat[8][8]){

	for( int i=0;i<8;i++ ){
		for(int j=0;j<8;j++ ){
			mat[i][j] = -1;
		}
	}
}

bool valid(int x, int y, int mat[8][8]){
	return (x>=0 && x<8 && y>=0 && y<8 && mat[x][y]==-1);
}


int solve(int x, int y, int k, int mat[8][8],int xnext[N], int ynext[N]){
  int x_nex, y_nex, i;
	if(k==64)
		return true;

	for(i=0;i<8;i++){

		x_nex = x+xnext[i];
		y_nex = y+ynext[i];
		if(valid(x_nex,y_nex,mat)){

			mat[x_nex][y_nex] = k;
			if(solve(x_nex, y_nex, k+1, mat,xnext,ynext)==true){
				return true;
			}
			else
				mat[x_nex][y_nex] = -1;
		}
	}
	return false;	
}

void sol(int x, int y){
	int xnext[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
	int ynext[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

	int mat[8][8];
	init_mat(mat);
	mat[x][y] = 0;
	if(solve(x,y,1,mat,xnext,ynext))
		print_mat(mat);
	else
		cout<<"NO SOLUTION";
	
}


int main(){

	sol(7,7);

	return 0;
}
