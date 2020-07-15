#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		int maks = 0, mini = 0;
		while(N--){
			int a,b,c;
			cin >> a >> b >> c;
			maks += max(max(a,b),c);
			mini += min(min(a,b),c);
		}
		cout << mini << " " << maks << "\n";
	}

}