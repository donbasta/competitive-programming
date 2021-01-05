#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

//Storing the parents of each element
int par[N+5];

//Storing the size of each set
int size[N+5]

//Initialize the sets
void init(){
	for(int i=1; i<=N; i++){
		par[i] = i;
		size[i] = 1;
	}
}

//Finding the root of an element, that is the set containing it
//Path compression
int fpar(int a){
	return (a==par[a] ? a : par[a]=fpar(par[a]));
}

//Merging two sets
void merge(int a, int b){
	a = fpar(a);
	b = fpar(b);
	if (a!=b) {
		if(size[a] < size[b]) {
			swap(a,b);
		}
		par[b] = a;
		size[a] += size[b];
	}
}