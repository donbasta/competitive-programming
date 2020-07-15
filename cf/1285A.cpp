#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n; 
	cin >> n;
	string s;
	cin >> s;
	int kiri=0, kanan=0;
	for(auto i:s){
		if(i=='L') kiri++;
		else kanan++;
	}
	cout << kiri+kanan+1;

}