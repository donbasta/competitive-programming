#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    ll a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;
    vector<pair<int, int>> dir = {
        {a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
    set<pair<int, int>> se;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int pk, qk, pq, qq;
            pk = xk + dir[i].first;
            qk = yk + dir[i].second;
            pq = xq + dir[j].first;
            qq = yq + dir[j].second;
            if (pk == pq && qk == qq) {
                se.emplace(pk, qk);
            }
        }
    }
    cout << se.size() << '\n';
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