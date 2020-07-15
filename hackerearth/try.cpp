#include <bits/stdc++.h>

using namespace std;

int add(int a, int b){
	return a+b;
}

int main(){
	int x, y;
	cin >> x >> y;
	cout << add(x/2, y+3);
}