#include <bits/stdc++.h>

using namespace std;

/* Compute lps array for prefix suffix length */
int compute_lps(string pat, int m, int * lps){

	lps[0] = 0;
	int i = 1;
	int len = 0;
	
	while(i<m){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}else{
			if(len != 0){
				len = lps[len-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
}
/* pattern search method using the lps array */
void pattern_search(string txt, string pat, int * lps){
	int i=0;
	int j=0;
	int len_pat = pat.size();
	int len_txt = txt.size();
	while(i<len_txt){
		if(pat[j] == txt[i]){
			i++;
			j++;
		}
		if(j == len_pat){
			cout<<pat<<" => found at index "<<i-j<<"\n";
			j = lps[j-1];
		}
		else if(pat[j] != txt[i] && i<len_txt){
			if( j != 0)			
				j = lps[j-1];
			else
				i = i + 1;
		}
	}
}

int main(){

	string pat = "ABABCABAB";
	string txt = "ABABDABACDABABCABAB";
	int len_pat = pat.size();
	int lps[len_pat];
	compute_lps(pat, len_pat, lps);
	pattern_search(txt, pat, lps);

	return 0;
}
