#include <bits/stdc++.h>

using namespace std;

/**
Baby Step - Giant Step Algorithm
cp algorithm
**/

int discrete_log(int a, int b, int m){

	int n = (int) sqrt(m+.0) + 1;
	int an = 1;
	for(int i=1; i<=n; i++){
		an *= a;
		an %= m;
	}

	map<int,int> val;
	for(int i=1, p=an; i<=m/n+1; i++, p=p*an%m){
		val[p] = i;
	}

	for(int i=0, q=b; i<=n; i++, q=q*a%m){
		if(val.count(q)){
			return n*val[q]-i;
		}
	}

	return -1;

}

int main(){
	int a,b,m;
	cin >> a >> b >> m;
	cout << discrete_log(a,b,m);
}

