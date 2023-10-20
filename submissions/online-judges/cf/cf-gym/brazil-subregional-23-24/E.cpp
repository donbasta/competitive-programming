#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const int M = 1e6;

int prv[M + 1], cnt[M + 1];

int sum_dig(int x) {
    int ret = 0;
    while (x) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= M; i++) {
        prv[i] = i - sum_dig(i);
    }
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        cnt[f]++;
    }
    int turn = 0;
    int cur = M;
    while (cur > 0) {
        while (cur > 0 && cnt[cur] == 0) cur--;
        if (cur == 0) break;
        if (turn + cnt[cur] >= k) {
            cout << cur - prv[cur] << '\n';
            return;
        }
        cnt[prv[cur]] += cnt[cur];
        turn += cnt[cur];
        cnt[cur] = 0;
    }
    cout << 0 << '\n';
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