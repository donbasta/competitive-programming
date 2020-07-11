#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    string S;
    cin >> S;
    int x = 0, y = 0;
    for(auto i : S){
        if(i=='U') y++;
        if(i=='D') y--;
        if(i=='L') x--;
        if(i=='R') x++;
    }
    cout << x << ' ' << y << '\n';
}