#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve () {
    int n, x, m;
    string s, prog;
    cin >> n >> x >> s >> m >> prog;
    --x;
    string ret;
    ret.push_back(s[x]);
    for (int i = 0; i < m; i++) {
        if (prog[i] == 'L') x--;
        else x++;
        ret.push_back(s[x]);
    }
    cout << ret << '\n';
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}