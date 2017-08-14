#include<iostream>

using namespace std;

void swap(int a, int b){
	b+=a;
	a=b-a;
	b-=a;
}

/* Iterative Bubble Sort Method */
void BubbleSort(int n, double tab[]){
	bool changed = false;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(tab[j]>tab[j+1]){
				swap(tab[j],tab[j+1]);
				changed = true;
			}
		}
		if(!changed)
			break;
	}
}
/* Recursive Bubble Sort Method */
void RecBubbleSort(int n, double tab[]){
	if(n==1)
		return;
	for(int i=0;i<n-1;i++){
		if(tab[i]>tab[i+1])
			swap(tab[i],tab[i+1]);
	}
		RecBubbleSort(n-1,tab);
}

int main(){

	double tab [] = {54,87,-45, 12, 0, 32, 1};	
	int n = sizeof(tab)/sizeof(tab[0]);
	BubbleSort(n,tab);
	for(int i=0; i<n; i++)
		cout<<tab[i]<<" ";
	cout<<"\n";
	double tab1 [] = {54,87,-45, 12, 0, 32, 1};	
	RecBubbleSort(n,tab1);
	for(int i=0; i<n; i++)
		cout<<tab1[i]<<" ";
	cout<<"\n";
	return 0;

}
