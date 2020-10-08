#include <bits/stdc++.h>
using namespace std;

long long primes(long long a){
	long long res = 0;
	for(long long i = 2; i*i <= a; i++){
		while(a%i == 0){
			a /= i;
			res++;
		}
	}
	if(a > 1){
		res++;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		
		long long ans = 0;
		for(int i=1; i<=N; i++){
			long long x;
			cin >> x;
			ans ^= primes(x);
		}

		cout << ((ans) ? "TIDAK" : "YA") << "\n"; 
		
	}
}
