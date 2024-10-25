#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> ve(d);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ve[i % d].push_back(x);
    }
    for (int i = 0; i < d; i++) {
        sort(ve[i].begin(), ve[i].end());
    }
    vector<int> tmp, cur(d);
    for (int i = 0; i < n; i++) {
        tmp.push_back(ve[i % d][cur[i % d]++]);
    }
    vector<int> lmao = tmp;
    sort(lmao.begin(), lmao.end());
    cout << ((lmao == tmp) ? "YES" : "NO") << '\n';
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