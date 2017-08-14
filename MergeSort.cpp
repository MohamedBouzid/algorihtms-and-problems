#include <iostream>

using namespace std;

void Merge(double tab[], int f1, int f2,int l1, int l2){

	int i=f1;
	int j=f2;
	int m = f1;
	for(int i=f1;i<l1;i++)
		tab1[i-f1]=tab[i];
	for(int i=f2;i<l2;i++)
		tab2[i-f2]=tab[i];
	while(i<l1 && j<l2){
	
		if(tab[i]>tab[j]){
			tab[m]=tab[j];
			j++;
			m++;
		}else if(tab[i]<tab[j]){
			tab[m]=tab[i];
			i++;
			m++;
		}else{
			tab[m]=tab[i];
			i++;
			m++;
			tab[m]=tab[j];
			j++;
			m++;
		}
	}

	for(int k=j;k<l2;k++)
		tab[m]=tab[k];
		m++;


	for(int k=i;k<l1;k++)
		tab[m]=tab[k];
		m++;
	
}

void MergeSort(int b, int e, double tab[]){

	if(e>b){
		int m = (b+e)/2;
		MergeSort(b,m,tab);
		MergeSort(m+1,e,tab);	
		Merge(tab,b,m+1,m,e);
	}
}

int main(){

	double tab[] = {54,98,32,58,14,36,0,-78,-45};
	int n = sizeof(tab)/sizeof(tab[0]);
	MergeSort(0,n,tab);
	for(int i=0;i<n;i++)
		cout<<tab[i]<<" ";
	cout<<"\n";
	return 0;

}
