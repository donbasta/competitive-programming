#include <bits/stdc++.h>
using namespace std;

int n, k;
int sum;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		sum ^= x;
	}
	if(sum & 1) {
		printf("John\n");
	} else {
		printf("Preston\n");
	}
	return 0;
}