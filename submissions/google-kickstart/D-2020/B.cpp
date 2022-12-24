#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void answer(int ans, int tc) {
    cout << "Case #" << tc << ": ";
    cout << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int k;
        cin >> k;
        vector<int> ar;
        int prev = -1;
        for (int i = 1; i <= k; i++) {
            int x;
            cin >> x;
            if (x == prev)
                continue;
            prev = x;
            ar.push_back(x);
        }
        int len = (int)ar.size();
        if (k == 1) {
            answer(0, tc);
            continue;
        }
        vector<int> dif;
        for (int i = 0; i < len - 1; i++) {
            if (ar[i + 1] > ar[i])
                dif.push_back(1);
            else
                dif.push_back(-1);
        }
        if (dif.empty()) {
            answer(0, tc);
            continue;
        }
        // for(auto i : ar) {
        //   cerr << i << ' ';
        // }
        // cerr << '\n';
        // for(auto i : dif) {
        //   cerr << i << ' ';
        // }
        // cerr << '\n';
        int cur = dif[0], cnt = 1, ans = 0;
        for (int i = 1; i < (int)dif.size(); i++) {
            if (dif[i] == cur)
                cnt++;
            else {
                cur = dif[i];
                ans += (cnt / 4);
                cnt = 1;
            }
        }
        ans += (cnt / 4);
        answer(ans, tc);
    }
    return 0;
}