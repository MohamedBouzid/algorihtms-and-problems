#include<bits/stdc++.h>

using namespace std;
#define N 1000

/* Recursive dfs implementation */
void dfs(list<int> adj[N], int visited[N], int n){

		visited[n]=0;
		cout<<n<<" ";
		for(list<int>::iterator it=adj[n].begin();it!=adj[n].end();it++){
			if(visited[*it]!=0)
				dfs(adj,visited,*it);
		}
}


int main(){

	int l,j,n;
	int visited[N];
	list<int> adj[N];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>j;
		adj[l].push_back(j);
		adj[j].push_back(l);
	}
	cout<<"----DFS-----";
	for(int i=0;i<N;i++)
		visited[i]=-1;
	dfs(adj,visited,2);
	return 0;
}

