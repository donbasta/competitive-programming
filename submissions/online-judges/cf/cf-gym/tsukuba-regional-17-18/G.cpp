#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string edge[2], face[2];
int d[2], l[2];

const ld PI = acos(-1);

string move(string ed, int angle, int length) {
    int dir;
    if (ed == "BC") {
        dir = 120 - angle;
    } else if (ed == "CD") {
        dir = 240 - angle;
    } else if (ed == "DB") {
        dir = 360 - angle;
    }
    ld dir2 = (ld) PI * dir / 180;
    ld dx = cos(dir2) * length;
    ld dy = sin(dir2) * length;
    ld cx = dx - dy / sqrtl(3);
    ld cy = 2 * dy / sqrtl(3);
    int tx = floor(cx);
    int ty = floor(cy);
    cx -= tx, cy -= ty;
    tx = abs(tx), ty = abs(ty);
    
    if (tx % 2 == 0 && ty % 2 == 0) {
        if (cx + cy < 1) return "CDA";
        else return "BCD";
    } else if (tx % 2 == 0 && ty % 2 == 1) {
        if (cx + cy < 1) return "ABC";
        else return "DAB";  
    } else if (tx % 2 == 1 && ty % 2 == 0) {
        if (cx + cy < 1) return "DAB";
        else return "ABC";
    } else if (tx % 2 == 1 && ty % 2 == 1) {
        if (cx + cy < 1) return "BCD";
        else return "CDA";
    }
    return "";
}

void solve() {
    for (int i = 0; i < 2; i++) {
        cin >> edge[i] >> d[i] >> l[i]; 
    }
    for (int i = 0; i < 2; i++) {
        face[i] = move(edge[i], d[i], l[i]);
    }
    if (face[0] == face[1]) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}