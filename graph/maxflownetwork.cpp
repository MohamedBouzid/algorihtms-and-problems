#include <bits/stdc++.h>

using namespace std;
#define N 6
bool bfs(int src, int dst, int rgraph[][N], int parents[]){

	queue<int> q;
	bool visited[N];
	for(int i=0;i<N;i++)
		visited[i] = false;
	visited[src] = true;
	q.push(src);
	parents[src] = -1;
	int u;
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int i=0;i<N;i++){
			if(!visited[i] && rgraph[u][i]>0){
				q.push(i);
				visited[i] = true;
				parents[i] = u;
			}
		}
	}
	return visited[dst] == true;
}

int max_flow(int src, int dst, int graph[][N]){
	int rgraph[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			rgraph[i][j] = graph[i][j];
	
	int flow = INT_MAX, maxflow = 0;
	int parents[N];
	while(bfs(src,dst,rgraph,parents)){
		for(int i=dst;parents[i]!=src;i=parents[i]){
			flow = min(flow, rgraph[parents[i]][i]);
		}
		for(int i=dst;parents[i]!=src;i=parents[i]){
			rgraph[i][parents[i]] += flow;
			rgraph[parents[i]][i] -= flow;
		}
		maxflow+=flow;

	}
	return maxflow;
}

int main()
{
    // Let us create a graph shown in the above example
    int graph[N][N] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };
 		
    cout << "The maximum possible flow is " << max_flow(0, 5, graph);
 
    return 0;
}
