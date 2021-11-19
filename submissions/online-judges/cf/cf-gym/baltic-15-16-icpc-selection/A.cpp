#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve () {
    string a, b;
    cin >> a >> b;
    int na = a.length();
    int nb = b.length();
    assert(na == nb);
    string ret;
    for (int i = 0; i < na; i++) {
        int aa = a[i] - '0';
        int bb = b[i] - '0';
        int dig = abs(aa - bb);
        ret.push_back((char) (dig + '0'));
    }
    cout << stoi(ret) << '\n';
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