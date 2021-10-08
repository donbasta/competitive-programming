#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void solve() {
    cin >> n;
    vector<ll> ar(n + 1), br(n + 1), in(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> br[i];
        if (br[i] != -1) {
            in[br[i]]++;
        } 
    }
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            Q.emplace(i);
        }
    }

    // cerr << "hehe\n";

    ll ans = 0;
    vector<int> now, pending;
    while (!Q.empty()) {
        auto fr = Q.front();
        // cerr << fr << '\n';
        Q.pop();
        ans += ar[fr];
        if (ar[fr] >= 0 && (br[fr] != -1)) {
            ar[br[fr]] += ar[fr];
            now.emplace_back(fr);
        } else {
            pending.emplace_back(fr);
        }
        if (br[fr] != -1) {
            in[br[fr]]--;
            if (in[br[fr]] == 0) {
                Q.emplace(br[fr]);
            }
        }
    }
    reverse(pending.begin(), pending.end());
    cout << ans << '\n';
    for (auto e : now) {
        cout << e << ' ';
    }
    for (auto e : pending) {
        cout << e << ' ';
    }
    cout << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}