#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    map<int, int> cnt;
    int M = 0;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        cnt[ar[i]]++;
        M = max(M, ar[i]);
    }
    int M2 = (int)pow(ld(M), ld(2) / ld(3)) + 1;

    ll ans = 0;
    for (auto e : cnt) {
        int x = e.second;
        ans += 1ll * x * (x - 1) * (x - 2);
    }

    for (auto e : cnt) {
        int aj = e.first;
        if (aj >= M2) {
            for (int b = 2; b * b * b <= M; b++) {
                if (aj % b != 0) continue;
                if (aj >= (M + b) / b) break;
                int ak = aj * b, ai = aj / b;
                if (!cnt.count(ak) || !cnt.count(ai)) continue;
                ans += 1ll * cnt[aj] * cnt[ak] * cnt[ai];
            }
        } else {
            for (int b = 1; b * b <= aj; b++) {
                if (aj % b != 0) continue;
                vector<int> cand = {b};
                if (b != aj / b) cand.emplace_back(aj / b);
                for (auto cc : cand) {
                    if (cc == aj) continue;
                    if (cnt.count(cc)) {
                        if (1ll * aj * aj / cc > 1ll * M) continue;
                        int ai = cc, ak = (aj / ai) * aj;
                        if (!cnt.count(ai) || !cnt.count(ak)) continue;
                        ans += 1ll * cnt[aj] * cnt[ai] * cnt[ak];
                    }
                }
            }
        }
        // cerr << aj << ' ' << ans << '\n';
    }

    cout << ans << '\n';
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