#include <bits/stdc++.h>

using namespace std;
#define MAX  1000

class pstack{
	public:
		int arr[MAX];
		int top;
		pstack(){
			top = 0;
		}
		void push(int value){
			if(top>=MAX-1){
				throw out_of_range("push not possible; index out of range > MAX\n");
				return;
			}
			else{
				arr[top] = value;
				top++;
			}
		}

		int pop(){
			if(top==0)
				throw out_of_range("push not possible; index out of range < 0\n");
			else{
				top--;
				return arr[top];
			}
		}
		
		bool isempty(){
			return top==0;
		}

		void print(){
			if(!top){
				cout<<"empty!";
				return;
			}
			int index = 0;
			while(index<=top){
				cout<<arr[index]<<"  ";
			}	
		}
};
class Tour{
	public:
		pstack disks;
		Tour();
		void movedisks(Tour dest){
			if(disks.isempty())
				return;
			dest.disks.push(disks.pop());
			movedisks(dest);
		}
		void push(int value){
			disks.push(value);
		}

		int pop(){
			return disks.pop();
		}

		void print(){
			disks.print();
		}
};


int main(){
	
	/*Tour t1,t2;
	t1.push(0);
	t1.push(1);
	t1.push(2);
	t1.push(3);
	cout<<"t1 initializing"<<endl;
	t1.print();
	t1.movedisks(t2);
	cout<<"t1 move to t2"<<endl;
	t2.print();
	t1.print();
	t2.movedisks(t1);
	cout<<"t2 move to t1"<<endl;
	t2.print();
	t1.print();*/
	

	return 0;
}








