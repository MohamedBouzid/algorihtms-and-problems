#include<bits/stdc++.h>

using namespace std;

int maxpricecut(int n, int price[]){
	int val = -1;
	if(n==0)
		return 0;
	else{
		for(int i=0;i<n;i++)
			val = max(val,maxpricecut(n-i-1,price)+price[i]);
	}
	return val;
}

int iterative_maxpricecut(int n, int price[]){
	int val = -1;
	int arr[n];
	for(int i=0;i<n;i++){
		val=-1;
		for(int j=0;j<i/2;j++){

			val=max(val,price[i-j]+arr[j]);
			cout<<price[i+j]<<"\n";	
		}
		arr[i]=val;
	}
	return price[n-1];
}

int main(){
	
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
	cout<<"max cut rod price is = "<<maxpricecut(8,price);
	cout<<"iterative max cut rod price is = "<<iterative_maxpricecut(8,price);

}
