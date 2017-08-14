#include <iostream>

using namespace std;
/* Iterative Insert Sort */
void InsertSort(int n, double tab[]){

	for(int i=1; i<n; i++){
		int j;
		int key = tab[i];
		for(j=i-1;j>=0 && key<tab[j];j--)
			tab[j+1]=tab[j];
		tab[j+1]=key;
	}

}
/*Recursive Insert Sort */
void RecInsertSort(int n, double tab[]){

	if(n<=0)
		return;
	RecInsertSort(n-1,tab);
	int key = tab[n];
	int j;
	for(j=n-1;j>=0 && key<tab[j];j--)
		tab[j+1]=tab[j];
	tab[j+1]=key;

}
int main(){
	
	double tab [] = {54,98,32,58,14,36,0,-78,-45};
	int n = sizeof(tab)/sizeof(tab[0]);
	InsertSort(n,tab);
	for(int i=0;i<n;i++)
		cout<<tab[i]<<" ";
	cout<<"\n";
	int l=n;
	RecInsertSort(l-1,tab);
	for(int i=0;i<n;i++)
		cout<<tab[i]<<" ";
	cout<<"\n";

	return 0;
}

