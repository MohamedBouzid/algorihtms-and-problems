#include<bits/stdc++.h>

using namespace std;

class BinaryTree{

	public:

		BinaryTree * right, * left;
		int data;

		BinaryTree(int data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}

		void addRight(BinaryTree * right){
			this->right = right;
		}

		void addLeft(BinaryTree * left){
			this->left = left;
		}

		void removeSubTree(BinaryTree * subTree){
			if(subTree == NULL)
				return;
			this->removeSubTree(subTree->right);
			this->removeSubTree(subTree->left);

			delete subTree;
		}

		void printTree(){
			queue<BinaryTree *> treeQueue;
			treeQueue.push(this);
			BinaryTree * tmpBinTree;
			while(!treeQueue.empty()){
				tmpBinTree = treeQueue.front();
				treeQueue.pop();
				cout<<tmpBinTree->data<<"  ";
				if(tmpBinTree->right != NULL)
					treeQueue.push(tmpBinTree->right);
				if(tmpBinTree->left != NULL)
					treeQueue.push(tmpBinTree->left);
			}
		}
};

int main(){
	
	BinaryTree * root = new BinaryTree(0);
	BinaryTree * child1 = new BinaryTree(1);
	BinaryTree * child2 = new BinaryTree(2);
	root->addRight(child1);
	root->addLeft(child2);
	BinaryTree * child3 = new BinaryTree(3);
	BinaryTree * child4 = new BinaryTree(4);
	child1->addRight(child3);
	child2->addRight(child4);

	root->printTree();
	root->removeSubTree(root->right);
	//root->printTree();
	cout<<root->data;
	cout<<root->right->data;
	cout<<root->right->right->data;
	root->printTree();
	return 0;

}
