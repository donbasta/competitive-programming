#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, k, f;
    cin >> n >> k >> f;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    int le = 1, ri = f;
    int ret = -1;

    auto ok = [&](int d) -> bool {
        int cur_left = 0;
        int x = 0;
        int cnt = 0;
        while (cur_left < f) {
            if (ve[x] > cur_left + d) {
                return false;
            }
            while (x < n && ve[x] <= cur_left + d) {
                x++;
            }
            x--;
            cnt++;
            cur_left = ve[x] + d;
            x++;
            if (x == n) {
                break;
            }
        }
        return (cnt <= k && cur_left >= f);
    };

    while (le <= ri) {
        int mid = (le + ri) >> 1;
        if (ok(mid)) {
            ret = mid;
            ri = mid - 1;
        } else {
            le = mid + 1;
        }
    }
    assert(ret != -1);
    cout << ret << '\n';
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