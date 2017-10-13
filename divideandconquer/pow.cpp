#include <bits/stdc++.h>

using namespace std;

/* pow function with log(n) complexity */
long long int p(int x,int n){
	long long int y=1;
	if(n==0)
		return 1;
	if(n==1)
		return x;
	
	y*=p(x,n/2);
	return y*y;
	
}
int main(){
	
	cout<<"120^9 = "<<p(120,9);

	return 0;
}
