#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, q;

    cin >> n >> q;
    vector<int> ar(n), cnt(n);
    set<int> gaada;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] < n) cnt[ar[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) gaada.insert(i);
    }
    for (int i = 0; i < q; i++) {
        int ik, xk;
        cin >> ik >> xk;
        --ik;
        if (ar[ik] < n) {
            cnt[ar[ik]]--;
            if (cnt[ar[ik]] == 0) {
                gaada.insert(ar[ik]);
            }
        }
        ar[ik] = xk;
        if (ar[ik] < n) {
            cnt[ar[ik]]++;
            if (gaada.count(ar[ik])) {
                gaada.erase(ar[ik]);
            }
        }
        int ans;
        if (gaada.empty()) {
            ans = n;
        } else {
            ans = *gaada.begin();
        }
        cout << ans << ' ';
    }
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