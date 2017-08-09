#include<bits/stdc++.h>

using namespace std;
#define N 1000

/* Iterative bfs implementation */

void bfs(list<int> adj[N], int visited[]){

	for(int i=0;i<N;i++)
		visited[i]=-1;
	queue<int> q;
	q.push(2);
	visited[2]=0;
	int p;
	while(!q.empty()){
		p=q.front();
		cout<<p<<" ";
		q.pop();
		list<int>::iterator it;	
		for(it=adj[p].begin();it!=adj[p].end();it++){
			if(visited[*it]==-1){
				visited[*it]=0;
				q.push(*it);
				
			}
		}
	}
}

int main(){

	int l,j,n;
	int visited[N];
	list<int>  adj[N];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>j;
		adj[l].push_back(j);
		adj[j].push_back(l);
	}
	cout<<"----BFS-----";
	bfs(adj,visited);


	return 0;
}

