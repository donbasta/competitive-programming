#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> se;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        se.emplace(0, i);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        --x;
        se.erase(make_pair(-ve[x], x));
        ve[x]++;
        se.emplace(-ve[x], x);
        cout << (se.begin()->second) + 1 << '\n';
    }
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