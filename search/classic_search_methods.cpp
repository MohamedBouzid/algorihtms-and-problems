#include<bits/stdc++.h>

using namespace std;

void linear(int arr[], int n, int nb){

	for(int i=0; i<n;i++){
		if(arr[i]==nb){
			cout<<"Found at "<<i<<" th position !";			
			break;
		}
	}
	cout<<"Not found !";
}

int binary(int arr[], int m, int n, int nb){

	if(m>n)
		return -1;
	if(arr[m+(n-m)/2]>nb)
		return binary(arr,m,m+(n-m)/2-1,nb);
	else if(arr[m+(n-m)/2]<nb)
		return binary(arr,m+(n-m)/2+1,n,nb);
	else
		return m+(n-m)/2;

}

int jump(int arr[], int m, int n, int nb){
	int i;
	for(i=0;i<n/m;i++){
		if(nb<arr[i*m])
			break;
	}
	if(i==n/m){
		if(arr[n-1]>=nb)
			for(int j=(n/m)*m;j<n;j++)
				if(arr[j]==nb)
					return j;
		else return -1;
	}
	else if(i==0){
		return -1;
	}
	else{
		for(int j=(i-1)*m;j<=(i)*m;j++)
			if(arr[j]==nb)
				return j;
	}

}

int interpolation(int arr[], int lo, int hi, int nb){
	int pos = lo + ((nb-arr[lo])*(hi-lo) / (arr[hi]-arr[lo])) ;
	if(lo>hi)
		return -1;
	if(arr[lo+pos]>nb)
		return binary(arr,lo,lo+pos-1,nb);
	else if(arr[lo+pos]<nb)
		return binary(arr,lo+pos+1,hi,nb);
	else
		return lo+pos;

}

int exponential(int arr[], int n, int nb){
	int exp = 1;
	if(arr[0]==nb)
		return 0;
	while(arr[exp-1]<=nb && exp<n){
		exp*=2;
	}
	return binary(arr,exp/2,min(exp,n),nb);
}

int main(){
	
	int arr[]={1, 2, 5, 6, 8, 10, 15, 20, 78};
	cout<<"binary :";
	cout<<binary(arr,0,9,78)<<"\n";
	cout<<"jump :";
	cout<<jump(arr,2,9,78)<<"\n";
	cout<<"interpolation : ";
	cout<<interpolation(arr,2,9,78)<<"\n";
	cout<<"exponential : ";
	cout<<exponential(arr,9,78)<<"\n";
	return 0;
}
