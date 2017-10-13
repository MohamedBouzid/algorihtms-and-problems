#include<bits/stdc++.h>

using namespace std;

int max_sum(int tab[], int n, int i){

if(n<0 || i<0)
	return 0;
if(tab[n]>tab[i])
	return max(max_sum(tab, n-1,i-1)+tab[n],max_sum(tab,n-1,i-1));
if(n>=0 && i<0)
	return max_sum(tab,n-1,n-2);
else
	return max_sum(tab,n,i-1);

}

int main(){
	
	int tab[] = {1, 101, 2, 3, 100, 4, 5};
	cout<<"max sum of increasing numbers : "<<max_sum(tab,6,5);
	return 0;
}
