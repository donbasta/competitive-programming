#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int q;
    cin >> q;
    deque<pair<int, int>> de;
    while (q--) {
        int tp, x, c;
        cin >> tp;
        if (tp == 1) {
            cin >> x >> c;
            de.push_back(make_pair(x, c));
        } else if (tp == 2) {
            cin >> c;
            int tot = 0;
            long long sum = 0;
            while (tot < c) {
                pair<int, int> cur = de.front();
                // cerr << cur.first << ' ' << cur.second << '\n';
                de.pop_front();
                if (tot + cur.second > c) {
                    de.push_front(make_pair(cur.first, cur.second - (c - tot)));
                    sum += 1LL * (c - tot) * cur.first;
                    tot = c;
                } else {
                    sum += 1LL * (cur.second) * (cur.first);
                    tot += cur.second;
                }
            }
            cout << sum << '\n';
        }
    }
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