#include<iostream>

using namespace std;

void selectionsort(int n, double tab[1000]){
	/* Selection Sort Method */
	int min_index,tmp;
	for(int i=0;i<n;i++){
		min_index = i;
		for(int j=i+1;j<n;j++){
			if(tab[min_index]>tab[j]){
				min_index = j;
			}
		}
		tmp = tab[i];
		tab[i] = tab[min_index];
		tab[min_index] = tmp;
	}
}

int main(){

	double tab [] = {10, 4, 78, 65, 52, 32,-1};
	int n = sizeof(tab)/sizeof(tab[0]);
	selectionsort(n,tab);
	for(int i=0;i<n;i++){
			cout<<tab[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
