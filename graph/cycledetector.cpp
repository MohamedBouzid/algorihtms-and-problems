#include<bits/stdc++.h>

using namespace std;
/* Check for Cycles in connected undirected graph */
bool dfs(list<int>* adj, int n, int p, bool visited[1000]){

	visited[n] = true;
	cout<<"noeud : "<<n<<"\n";
	for(list<int>::iterator it=adj[n].begin();it!=adj[n].end();++it){
		cout<<p<<" => "<<*it<<" => "<<visited[*it]<<"\n";
		if(!visited[*it])
			return dfs(adj,*it,n,visited);
		else if(*it!=p){
			return true;
		}

	}
	return false;
}

int main(){

	int n,m,x,y;
	cin>>n;
	cin>>m;
	list<int> * adj;
	adj = new list<int>[n+1];
	for(int i=0;i<m;i++){
		cin>>x;
		cin>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bool visited[n];
	for(int i=0;i<n;i++)
		visited[i]=false;
	if(!dfs(adj,0,0,visited))
		cout<<"No Cycle";
	else
		cout<<"damn cycle";	

	/* check cyclicity for non connected undirected graphs */
	int i;	
	for(i=0;i<n;i++)
		visited[i]=false;
	for(int i=0;i<n;i++)
		if(!visited[i])		
			if(dfs(adj,i,-1,visited)){
				cout<<"Cycle Cycle!";
				return 0;
		}
	
	cout<<"No Cycle";		
	return 0;
}
