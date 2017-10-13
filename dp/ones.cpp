#include<bits/stdc++.h>
using namespace std;
#define bool int
#define R 6
#define C 5



int ones(int n, int m, int mat[R][C]){
	int s[R][C];
	
	for(int i=0;i<n;i++){
		s[i][0]=mat[i][0];
	}	
	for(int i=0;i<m;i++){
		s[0][i]=mat[0][i];
	}	
	int ma=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(mat[i][j]==1)			
				s[i][j]=min(s[i-1][j],min(s[i][j-1],s[i-1][j-1]))+1;
			else 
				s[i][j]=0;
			if(ma<s[i][j])
				ma=s[i][j];
		}

	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
						
			cout<<s[i][j]<<" ";
		}
		cout<<"\n";

	}	
	return m;

}


int main(){
  bool mat[R][C] = {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
	cout<<"max is : "<<ones(R,C,mat);

	return  0;
}
