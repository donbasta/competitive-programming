#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int k, w;
    cin >> k >> w;
    vector<int> T(k);
    for (int i = 0; i < k; i++) {
        cin >> T[i];
    }
    vector<vector<pair<int, int>>> emb(w);
    vector<string> word(w);
    for (int i = 0; i < w; i++) {
        cin >> word[i];
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int p, v;
            cin >> p >> v;
            --p;
            emb[i].emplace_back(p, v);
        }
    }
    vector<bool> used(w);
    vector<bool> udah(k);
    int proc = k;
    // int sisa = w;
    vector<int> idx;
    while (proc > 0) {
        int now = -1;
        for (int i = 0; i < w; i++) {
            if (used[i]) continue;
            bool ok = true;
            int nw = 0;
            for (auto e : emb[i]) {
                if (udah[e.first]) continue;
                if (T[e.first] == e.second) {
                    nw++;
                } else {
                    ok = false;
                }
            }
            if (ok && (nw > 0)) {
                proc -= nw;
                now = i;
                used[i] = true;
                idx.push_back(i);
                for (auto e : emb[i]) {
                    udah[e.first] = true;
                }
                break;
            }
        }
        if (now == -1) break;
    }
    assert(proc == count(udah.begin(), udah.end(), false));
    if (proc > 0) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    reverse(idx.begin(), idx.end());
    vector<int> CT(k, INF);
    for (auto c : idx) {
        cout << word[c] << ' ';
        for (auto e : emb[c]) {
            CT[e.first] = e.second;
        }
    }
    assert(CT == T);
    cout << '\n';
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