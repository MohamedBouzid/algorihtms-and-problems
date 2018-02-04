#include <bits/stdc++.h>

using namespace std;


void dfs(list<int> adj[], int v, bool visited[], stack<int> *st){

	visited[v] = true;


	list<int>::iterator it;
	for(it=adj[v].begin();it!=adj[v].end();it++){
		if(!visited[*it]){
			//visited[*it] = true;
			dfs(adj,*it,visited,st);
		}
	}
	st->push(v);
}

void topo_sort(list<int> adj[], int  n) {
	
	bool * visited = new bool[n];
	stack<int> * st = new stack<int>();
	for(int i=0;i<n;i++)
		visited[i] = false;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(adj,i,visited, st);
		}
	}

	while(!st->empty()) {
		cout<<st->top()<<"   ";
		st->pop();
	}

}

int main(){
	int n,m,x,y;
	cin>>n>>m;
	list<int> adj[n];
	for(int i=0;i<n;i++) {
		cin>>x>>y;
		adj[x].push_back(y);
	}

	topo_sort(adj,n);

	return 0;
}
