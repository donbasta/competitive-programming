#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using matrix = vector<vector<ll>>;

matrix identity;

matrix mul(matrix a, matrix b){
	int sz = (int) a.size();
	matrix d(sz, vector<ll>(sz));
	for(int i = 0; i < sz; i++) {
		for(int j = 0; j < sz; j++) {
			for(int k = 0; k < sz; k++) {
				d[i][j] = (d[i][j] + a[i][k] * b[k][j]);
			}
		}
	}
	return d;
}
 
// matrix fpow(matrix a, ll b) {
// 	int sz = (int) a.size();
// 	if(b == 0) return identity; //define identity first
// 	if(b == 1) return a;
// 	if(b % 2 == 1) return mul(a, fpow(a, b - 1), sz);
// 	matrix c = fpow(a, b/2);
// 	return mul(c, c, sz);
// }

matrix fpow(matrix a, ll b) {
	matrix ret = identity;
	while (b) {
		if (b & 1) ret = mul(ret, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ret;
}

void printMatrix(matrix a) {
	for(auto baris : a) {
		for(auto kotak : baris) {
			cout << kotak << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int sz = 3;
	for(int i = 0; i < sz; i++) {
		vector<ll> temp;
		for(int j = 0; j < sz; j++) {
			temp.push_back((i == j) ? 1 : 0);
		}
		identity.push_back(temp);
	}

	printMatrix(identity);
}
