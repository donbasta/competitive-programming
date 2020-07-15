#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

int main(){

	LL x;
	cin >> x;
	for(LL i=2; i*i<=x; i++){
		if(x%i==0) {
			LL t = 1;
			while(x%i==0){
				x/=i;
				t*=i;
			}
			
		}
	}


}