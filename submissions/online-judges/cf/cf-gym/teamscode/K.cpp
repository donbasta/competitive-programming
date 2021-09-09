#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n, m;

void solve() {
    cin >> n >> m;
    set<pair<int, int>> se;
    se.emplace(1, n);
    while (m--) {
        char c;
        int i;
        cin >> c >> i;
        auto pseg = se.lower_bound(make_pair(i + 1, 0));
        --pseg;
        auto seg = *pseg;
        if (c == 'R') {
            se.erase(se.find(seg));
            pair<int, int> left = make_pair(seg.first, i);
            pair<int, int> right = make_pair(i + 1, seg.second);
            se.insert(left), se.insert(right);
        } else if (c == 'Q') {
            int ret = seg.second - seg.first + 1;
            cout << ret << '\n';
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