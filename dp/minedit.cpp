#include<bits/stdc++.h>

using namespace std;

/* Recursive Min Edit Distance */
int minedit(int n, int m, string s1, string s2){

	if(n==0)
		return m;
	else if(m==0)
		return n;
	else if(s1[n-1]==s2[m-1])
		return minedit(n-1,m-1,s1,s2);
	else{
		cout<<"in";
		return min(minedit(n,m-1,s1,s2),min(minedit(n-1,m,s1,s2),minedit(n-1,m-1,s1,s2)))+1;
	}

}
/* Iterative Min Edit Distance */
int iterative_minedit(int n, int m, string s1, string s2){



}
int main(){

	string s1="sunday";
	string s2="saturday";
	cout<<"minimum edit steps = "<<minedit(6,8,s1,s2);
	return 0;
}
