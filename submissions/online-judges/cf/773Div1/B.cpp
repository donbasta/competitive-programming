#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n), tmn(n);
    map<int, vector<int>> cnt;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]].emplace_back(i);
    }
    for (auto e : cnt) {
        if (e.second.size() & 1) {
            cout << -1 << '\n';
            return;
        }
    }
    int id = 0;
    for (auto e : cnt) {
        for (int i = 0; i < e.second.size(); i += 2) {
            tmn[e.second[i]] = id;
            tmn[e.second[i + 1]] = id;
            id++;
        }
    }
    int id_last = n - 1;
    vector<pair<int, int>> ve;
    vector<int> segs;
    for (int i = 0; i < n; i++) {
        if (id_last < 0) break;
        int lst = tmn[id_last];
        int prv = id_last - 1;
        while (prv >= 0 && tmn[prv] != lst) {
            prv--;
        }
        assert(prv != -1);
        if (prv == id_last - 1) {
            segs.emplace_back(2);
            id_last = prv - 1;
            continue;
        }
        for (int j = prv; j < id_last; j++) {
            ve.emplace_back(j, ar[id_last + prv - j]);
        }
        reverse(ar.begin() + prv + 1, ar.begin() + id_last + 1);
        reverse(tmn.begin() + prv + 1, tmn.begin() + id_last + 1);
        segs.emplace_back(2 * (id_last - prv));
    }
    cout << ve.size() << '\n';
    for (auto e : ve) {
        cout << (e.first + 1) << ' ' << e.second << '\n';
    }
    reverse(segs.begin(), segs.end());
    cout << segs.size() << '\n';
    for (auto e : segs) {
        cout << e << ' ';
    }
    cout << '\n';
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