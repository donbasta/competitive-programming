#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    int cur = 0, pw = 1;
    bool ok = true;
    while (cur < n) {
        vector<int> tmp;
        for (int i = cur; i < min(n, pw); i++) {
            tmp.push_back(ar[i]);
        }
        vector<int> cp = tmp;
        sort(cp.begin(), cp.end());
        ok &= (cp == tmp);
        cur = min(n, pw);
        pw *= 2;
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}