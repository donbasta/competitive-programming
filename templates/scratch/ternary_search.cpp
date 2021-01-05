#include <bits/stdc++.h>
using namespace std;

// f is an increasing, max, decreasing 
// or f is a decreasing, min, increasig function on [l,r]

double ternary_search(double l, double r){
	double eps = 1e-9;
	while(r-l > eps){
		double m1 = l + (r-l)/3;
		double m2 = r - (r-l)/3;
		double f1 = f(m1);
		double f2 = f(m2);
		if(f1 < f2){
			l = m1;
		} else {
			r = m2;
		}
	}
	return f(l);
}

//ternary search on integer valued domain and functions
int ternary_search(int l, int r){
	while(r-l>=3){
		int m1 = l + (r-l)/3;
		int m2 = r - (r-l)/3;
		int f1 = f(m1);
		int f2 = f(m2);
		if(f1 < f2){
			l = m1+1;
		} else {
			r = m2;
		}
	}
	int maks = 0;
	for(;l<=r;l++){
		maks = max(maks,f(l));
	}
	return maks;
}