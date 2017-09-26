#include <bits/stdc++.h>

using namespace std;

int dfs(list<int> adj[], int n, int v, int * s, bool visited[]){

	visited[v] = true;
	list<int>::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++){
		
		if(!visited[*it]){
			(*s)++;
			visited[*it]=true;
			dfs(adj,n,*it,s,visited);
		}
	}
	return *s;
}

int main(){

	int n,m,x,y;
	cin>>n>>m;
	list<int> adj[n];
	for(int i=0;i<m;i++){
		cin>>x>>y;
		adj[x].push_back(y);
	}
	bool visited[n];
	cout<<"All mother vertex :"<<"\n";
	for(int i=0;i<n;i++){
		int s=0;	
		for(int j=0;j<n;j++){
			visited[j] = false;
		}
		if(dfs(adj,n,i,&s,visited)==n-1)
			cout<<i<<"\n";
	}

	return 0;
}
