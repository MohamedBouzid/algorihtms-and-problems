#include<bits/stdc++.h>

using namespace std;

typedef struct node{

	int data;
	node * next;
}	node;

node * newNode(int data){
	node * n = (node *)malloc(sizeof(node));
	n->data = data;	
	n->next = NULL;
	return n;
}

void sublist(node * first, node * second){
	node * tmp = first;
	while(second->next != NULL && tmp->next != NULL){
		cout<<second->data<<" = "<<tmp->data<<"\n";		
		if(second->data == tmp->data){
			tmp = tmp->next;
			second = second->next;
			cout<<"next = "<<second->next;
		}else{
			tmp = first;
		}
	}

	if(tmp == NULL)
		cout<<"FOUND \n";
	else
		cout<<"NOT FOUND \n";

}

int main(){

	node *a = newNode(1);
	a->next = newNode(2);
	a->next->next = newNode(3);
	a->next->next->next = newNode(4);

	node *b = newNode(1);
	b->next = newNode(2);
	b->next->next = newNode(1);
	b->next->next->next = newNode(2);
	b->next->next->next->next = newNode(4);
	b->next->next->next->next->next = newNode(4);
	sublist(a,b);
	return 0;
}
