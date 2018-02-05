#include<bits/stdc++.h>

using namespace std;

template<typename T>
class SegmentTree{
	public:
		T length;
		T elements[1000000];
		vector<T> s;

		SegmentTree(T length){
			this->length = length;
			s.resize(4*length);
		}

		/* Build SegmentTree */
		void build( T id , T l , T r ){
			if( (r - l) < 2) { s[id] = elements[l]; return;}
			T mid = ( l + r ) / 2;
			build(2 * id, l, mid);
			build(2 * id + 1,mid, r);
			s[id] = s[2*id] + s[2*id + 1];
		}

		/* Update elements[p] with value x */
		void update( T p, T x, T id , T l , T r ){
			s[id] += x - elements[p];
			if(l-r < 2) { elements[p] = x; return; }
			T mid = ( l + r ) / 2;
			if(p < mid)
				modify(2*id, p, x, l, mid);
			else
				modify(2*id + 1, p, x, mid, r);
		}

		/* Sum Query on range [x,y) */
		T sum( T x, T y, T id , T l , T r ){
			if( x >= r || y <= l ) return 0;
			if( x <= l && y >= r ) return s[id];

			T mid = ( l + r ) / 2;
			return sum( x, y, 2*id, l, mid) + sum( x, y, 2*id + 1, mid, r);
		}

};

int main(){

	int n;
	cin>>n;

	SegmentTree<int> seg(n);
	int i=0;
	while(i<n){
		cin>>seg.elements[i];i++;
	}

	seg.build(1,0,seg.length);
	cout<<"sum[0,3) = "<<seg.sum(0,3,1,0,5)<<endl;

	return 0;
}
