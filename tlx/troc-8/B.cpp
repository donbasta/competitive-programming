#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int b=0, o=0, n=0;
    for(auto i : s){
        if(i=='b') b++;
        if(i=='o') o++;
        if(i=='n') n++;
    }
    int mini = min(min(b,o),n);
    if(mini<=1) {
        cout << 0 << "\n";
    } else {
        cout << mini-1 << "\n";
    }
}