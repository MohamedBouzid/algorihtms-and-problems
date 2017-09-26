#include <bits/stdc++.h>

using namespace std;

int score(int n){

	if(n<0)
		return 0;
	if(n==0)
		return 1;
	
	return score(n-3)+score(n-5)+score(n-10);
}

int main(){

	cout<<"number of ways is = "<<score(13)<<"\n";

	return 0;
}
