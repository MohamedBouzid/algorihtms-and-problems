#include<bits/stdc++.h>

using namespace std;

int is_pal(string s){

	int l=s.size();
	int i=0;
	while(i<l-i-1){
		if(s[i]!=s[l-i-1])
			return 0;
		i++;
	}
	return l;
}
/* Naive exponential Recursive implementation of longest palindromic subsequence */
int lps(string s, string sub, int index){

	if(index<0)
		return is_pal(sub);

	return max(lps(s,sub,index-1),lps(s,s[index]+sub,index-1));
}
/* Optimized Recursive implementation of longest palindromic subsequence */
int lps1(string seq, int i, int j)
{

   if (i == j)
     return 1;
 
   if (seq[i] == seq[j] && i + 1 == j)
     return 2;
 
   if (seq[i] == seq[j])
      return lps1 (seq, i+1, j-1) + 2;
 
   return max( lps1(seq, i, j-1), lps1(seq, i+1, j) );
}

int main(){

	string s="GEEKSFORGEEKS";
	int l=s.size();
	string sub="";
	clock_t time0 = clock();
	cout<<"longest palindromic subsequence = "<<lps(s,sub,l-1)<<"\n";
	clock_t time1 = clock();	
	cout<<"longest palindromic subsequence = "<<lps1(s,0,l-1)<<"\n";
	clock_t time2 = clock();	
	cout<<"\n";
	cout<<"Naive execution time  = "<<time1-time0<<"\n";
	cout<<"Optimized execution time  = "<<time2-time1<<"\n";
	return 0;
}
