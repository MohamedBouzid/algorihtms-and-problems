#include <bits/stdc++.h>

using namespace std;

void permut(string s, int p, int si){

	if(p==si+1)
		return;
	cout<<s<<endl;

	for(int i=0;i<=p;i++){
		string tmp(s);
		char c = s[i];							/*abc   */ 
		tmp[i] = s[p];
		tmp[p] = c;
		permut(tmp,p+1,si);
	}
																/*abc   1 : r1(bac) r1(abc) r2(cab) r2(bca) | r2(cba) r2(acb) */  
}																

int main(){
	string s = "abcd";
	cout<<s.size()<<endl;
	permut(s,1,s.size());

	return 0;
}
