#include <bits/stdc++.h>
using namespace std;

int main(){
    bool ok = true;
    int sum = 0;
    for(int i=0; i<3; i++){
        int x;
        cin >> x;
        ok &= (x>=50);
        sum += x;
    }
    if(sum>=200 && ok){
        cout << "Lolos\n";
    } else {
        cout << "Tidak Lolos\n";
    }
}