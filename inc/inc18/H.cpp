#include <bits/stdc++.h>
using namespace std;

long long f(long long a) {
	long long poww = 1;
	long long ret = 0;
	for(int i = 0; i < a; i++) {
		ret += poww;
		poww *= 10;
	}
	return ret;
}

bool isOdd(long long a) {
	while(a % 10 == 0) {
		a /= 10;
	}
	return (a & 1);
}

long long get(long long b) {
	if(b == 0) {
		return 0;
	}
	vector<int> digit;
	bool cek = (b & 1);
	while(b) {
		int t = b % 10;
		digit.push_back(t);
		b /= 10;
	}
	reverse(digit.begin(), digit.end());
	int sz = (int)digit.size();
	long long res = 0;
	int last = 0;
	for(int i = 0; i < sz; i++) {
		res += 5LL * f(sz - i - 1) * digit[i];
		res += 1LL * (digit[i] / 2);
		if(i >= 1)
			res += 1LL * ((last & 1) && (digit[i - 1] != 0));
		if(digit[i] != 0)
			last = digit[i];
	}
	return res + 1LL * cek;
}

long long get(long long a, long long b) {
	return get(b) - get(a - 1);
}

long long a, b;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> a >> b;
	long long odd = get(a, b);
	long long even = b - a + 1 - odd;
	cout << odd << " " << even << "\n";
	return 0;

	// for(int i = 1; i <= 50; i++) {
	// 	cerr << i << " " << get(i) << "\n";
	// }
}
