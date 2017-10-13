#include<bits/stdc++.h>

using namespace std;
// O(n(n+26))
int noreps(string s, int m, int i, int j, int n, int visited[]){


	if(visited[s[i-1]]==-1 && visited[s[j+1]]==-1 && j!=m-1 && i!=0){
		visited[s[i-1]]=1;
		visited[s[j+1]]=1;
		return noreps(s,m,i-1,j+1,n,visited)+2;
	}
	else if(visited[s[i-1]]==-1 && i!=0){
		visited[s[i-1]]=1;
		return noreps(s,m,i-1,j,n,visited)+1;
	}
	else if(visited[s[j+1]]==-1 && j!=m-1){
		visited[s[j+1]]=1;
		return noreps(s,m,i,j+1,n,visited)+1;
	}
	else
		return 0;
}

int main(){
	
	string s = "GEEKSFORGEEKS";
	int len = s.size();
	int visited[200];
	
	int max_noreps = 0;
	for(int i=0;i<len;i++){
		for(int j =0; j<len; j++)
			visited[s[j]]=-1;
		cout<<max_noreps;
		max_noreps = max(max_noreps,noreps(s,len,i,i,i,visited));
	}
	cout<<"max = "<<max_noreps;
	return 0;
}







