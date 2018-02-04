#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
	int data;	
	Node * next;
} Node;

Node * sum(Node * n1, Node * n2){

	int carry = 0, sum = 0;
	Node * res, *prev = NULL, *beg = NULL;

	while(n1 || n2){
		if(n1)
			sum = n1->data;
		if(n2)
			sum += n2->data;
		sum += carry;
		carry = sum/10;
		res = (Node*) malloc(sizeof(Node));
		res->data = sum%10;
		if(prev)
			prev->next = res;
		else
			beg = res;
		prev = res;
		sum = 0;
		if(n1) n1 = n1->next;
		if(n2) n2 = n2->next;
	}
	if(carry)
		res = (Node*) malloc(sizeof(Node));
	res->data = carry;
	res->next = NULL;
	prev->next = res;
	return beg;
}
void print(Node * n){
	while(n){
		cout<<n->data<<" -> ";
		n = n->next;	
	}
	cout<<endl;
}

Node * is_looped(Node * n){
	unordered_set<Node*> s;
	unordered_set<Node*> :: const_iterator it;
	while(n){
		it = s.find(n);
		if(it!=s.end())
			return n;
		else{
			s.insert(n);
			n = n->next;
		}
	}
	return n;
}

int main(){

	Node * n1 = (Node *)malloc(sizeof(Node));
	n1->data = 4;
	Node * n2 = (Node *)malloc(sizeof(Node));
	Node * m1 = (Node *)malloc(sizeof(Node));
	Node * m2 = (Node *)malloc(sizeof(Node));
	m2->data = 8;
	m1->data = 7;
	n2->data = 5;

	/*n1->next = n2;
	n2->next = NULL;
	m1->next = NULL;
	//m2->next = NULL;
	Node * s = sum(n1,m1);*/
	n1->next = n2;
	n2->next = m1;
	m1->next = m2;
	m2->next = n2;
	Node * res = is_looped(n1);
	cout<<res->data<<endl;
	

	return 0;
}



