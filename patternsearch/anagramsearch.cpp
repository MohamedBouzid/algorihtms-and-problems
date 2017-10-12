#include <bits/stdc++.h>
#define ALPHA 256
using namespace std;

/* Function to compare two arrays */
bool compare(int pat[], int win[]){
	for(int i=0;i<ALPHA;i++)
		if(pat[i] != win[i])
			return false;
	return true;
}

/* Function to find all anagrams in txt */
void anagram(string pattern, string txt){
	int pat[ALPHA] = {0};
	int win[ALPHA] = {0};
	int len_pat = pattern.size();
	int len_txt = txt.size();

	for(int i=0;i<len_pat;i++){
		pat[pattern[i]] ++;
		win[txt[i]] ++;
	}
	for(int i=len_pat;i<len_txt;i++){
		if(compare(win,pat))
			cout<<"anagram found at index "<<i-len_pat<<"\n";
		win[txt[i-len_pat]] --;
		win[txt[i]] ++;
	}
	if(compare(win,pat))
		cout<<"anagram found at index "<<len_txt-len_pat<<"\n";
}

int main(){

	string txt = "GEEKS FOR GEEKS";
	string pattern = "GEEKS";
	anagram(pattern, txt);

	return 0;
}
