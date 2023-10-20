#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        --x;
        pos[x] = i;
    }
    int sz = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] < pos[i - 1]) sz++;
    }
    int ans = 0;
    while (sz > 1) {
        sz = (sz + 1) / 2;
        ans++;
    }
    cout << ans << '\n';
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