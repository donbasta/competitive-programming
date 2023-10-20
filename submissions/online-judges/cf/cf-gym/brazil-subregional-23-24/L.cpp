#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.length();
    vector<string> ss(k);
    for (int i = 0; i < n; i++) {
        ss[i % k].push_back(s[i]);
    }
    for (int i = 0; i < k; i++) {
        sort(ss[i].begin(), ss[i].end());
    }
    string ret(n, 'a');
    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            ret[j] = ss[i][j / k];
        }
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}