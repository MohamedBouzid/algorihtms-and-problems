#include<bits/stdc++.h>

using namespace std;

int dropeggs(int floor, int eggs){


	if(floor == 1 || floor == 0)
		return floor;
	if(eggs==1)
		return floor;
	int mini = 100000;
	for(int i=1;i<=floor;i++){
		mini = min(max(dropeggs(floor-i,eggs),dropeggs(i-1,eggs-1)),mini);
	}
	return mini+1;
}

int main(){

	cout<<dropeggs(100,2);
	return 0;
}
