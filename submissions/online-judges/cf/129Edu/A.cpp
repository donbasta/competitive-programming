#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    string s1, s2;
    if (a.back() > b.back()) {
        s1 = s2 = "Alice";
    } else if (a.back() < b.back()) {
        s1 = s2 = "Bob";
    } else if (a.back() == b.back()) {
        s1 = "Alice";
        s2 = "Bob";
    }
    cout << s1 << '\n' << s2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}