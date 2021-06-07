#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

string A = "abcdefghijklmnopqrstuvwxyz";

string construct(int t) {
    if (t == 1) return "aa";
    string pp = construct(t - 1);
    pp.push_back(A[t - 1]);
    pp.push_back(A[t - 1]);
    for (int i = 1; i < t - 1; i++) {
        pp.push_back(A[i]);
        pp.push_back(A[t - 1]);
    }
    pp.push_back(A[0]);
    return pp;
}

int n, k;

void solve() {
    cin >> n >> k;
    string s = construct(k);
    int idx = 0;
    int t = (int) s.length();
    for (int i = 0; i < n; i++) {
        cout << s[idx];
        idx = (idx + 1) % t;
        if (idx == 0) idx++;
    }
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