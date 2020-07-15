#include <bits/stdc++.h>


using namespace std;

int main(){

	string s;
	cin >> s;

	int zero=0;
	int one=0;
	int ss = (int)s.length();

	for(auto i : s){
		if(i=='0') zero++;
		if(i=='1') one++;
	}

	if(zero>one){
		for(int i = 0; i<ss; i++){
			cout << '1';
		}
	} else if(zero<one){
		for(int i = 0; i<ss; i++){
			cout << '0';
		}
	} else {
		if(s[ss-1]=='1'){
			for(int i = 0; i<ss-1; i++){
				cout << '1';
			}
			cout << '0';
		} else {
			for(int i = 0; i<ss-1; i++){
				cout << '0';
			}
			cout << '1';
		}
	}

	cout << "\n";

}