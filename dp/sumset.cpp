#include<bits/stdc++.h>

using namespace std;
#define N 100
/* Recursive subset sum */

bool sumset(int s, int n, int arr[N]){
	cout<<s<<"  :  "<<n<<"\n";
	if(s==0)
		return true;	
	else if(s<0 || n<0)
		return false;
	else{
		return (sumset(s-arr[n],n-1,arr) || sumset(s,n-1,arr));
	}
}

int main(){
	int arr[N] = {3, 34, 4, 12, 5, 2};
	if (sumset(1000,5,arr))
		cout<<"true";
	else
		cout<<"false";
	return 0;
}

