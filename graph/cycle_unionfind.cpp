#include <bits/stdc++.h>

using namespace std;
int  arr[100];
int find(int n){
	if(arr[n]==-1)
		return n;
	return find(arr[n]);
}

bool union_set(int a, int b){

	if(find(a)!=find(b)){
		arr[b] = a;
		return true;
	}
	return false;
}


int main(){


	int n,m,x,y;
	cin>>n>>m;
	memset(arr,-1,sizeof(arr));
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"  ";
	for(int i=0;i<m;i++){
		cin>>x>>y;
		if(!union_set(x,y))
			cout<<"cycle detected !";
	}
	return 0;
}
