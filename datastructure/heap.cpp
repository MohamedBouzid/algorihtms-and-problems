#include <bits/stdc++.h>

using namespace std;

class MinHeap{
	
	public:
		int * arr;
		int capacity;
		int heap_size;

		MinHeap(int capacity){
			this->capacity = capacity;
			heap_size = 0;
			arr = new int[capacity];
		}

		int parent(int index){
			return (index-1)/2;
		}
	
		int left(int index){
			return 2*index + 1;
		}

		int right(int index){
			return 2*index + 2;
		}

		void insertKey(int key){
			if(heap_size==capacity){
				cout<<"Maximum Capacity!"<<endl;
				return;
			}
			heap_size++;
			arr[heap_size-1] = key;
			int i = heap_size-1;
			while(i!=0 && arr[i] < arr[parent(i)]){
				swap(&arr[i], &arr[parent(i)]);
				i = parent(i);
			}
		}

		void deleteKey(int index){
			if(heap_size == 0){
				cout<<"Impossible to remove key; heap is empty!"<<endl;
				return;
			}
			if(heap_size == 1){
				heap_size--;
				return;
			}
			decreaseKey(index, INT_MIN);
			extractMin();			
		}
		void decreaseKey(int index, int newKey){
			arr[index] = newKey;
			while(index!=0 && arr[index]<arr[parent(index)]){
				swap(&arr[index], &arr[parent(index)]);
				index = parent(index); 
			}
		}

		int extractMin(){

			if(heap_size == 0)
				return arr[0];
			if(heap_size == 1){
				heap_size --;
				return arr[0];
			}		

			int mi = arr[0];
			arr[0] = arr[heap_size-1];
			heap_size--;
			heapify(0);

			return mi;
		}

		int getMin(){
			return arr[0];
		}

		void heapify(int index){
			int l = left(index);
			int r = right(index);
			int small = index;
			if(l<heap_size && arr[small]>arr[l]){
				small = l;
			}
			if(r<heap_size && arr[r]< arr[small]){
				small = r;
			}
			if(small != index){
				swap(&arr[index], &arr[small]);
				heapify(small);
			}
		}
		void swap(int * a, int * b){
			int tmp = *a;
			*a = *b;
			*b = tmp;
		}
};


int main(){

	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();

	return 0;
}






