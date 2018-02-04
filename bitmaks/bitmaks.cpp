#include <bits/stdc++.h>

using namespace std;

int main(){


	int tab [5] = {1,2,3,5,6};
	int i;
	for(i=0;i<5;i++){
		if((tab[i]&1)==(tab[i+1]&1))
			break;
	}
	cout<<tab[i]+1;
	return 0;
}
