#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    int tmp1 = ar[n - 1] > ar[0];
    int id1 = -1;
    for (int i = 0; i < n - 1; i++) {
        tmp1 += (ar[i] > ar[i + 1]);
        if (ar[i] > ar[i + 1]) id1 = i;
    }
    int tmp2 = ar[n - 1] < ar[0];
    int id2 = -1;
    for (int i = 0; i < n - 1; i++) {
        tmp2 += (ar[i] < ar[i + 1]);
        if (ar[i] < ar[i + 1]) id2 = i;
    }
    bool ok = ((tmp1 <= 1) | (tmp2 <= 1));
    if (!ok) {
        cout << -1 << '\n';
        return;
    }
    if (tmp1 == 0 || tmp2 == 0) {
        cout << 0 << '\n';
        return;
    }
    int ans = n;
    if (tmp1 == 1) {
        int tmp;
        if (ar[n - 1] > ar[0])
            tmp = 0;
        else
            tmp = min(n - 1 - id1, 3 + id1);
        ans = min(ans, tmp);
    }
    if (tmp2 == 1) {
        int tmp;
        if (ar[n - 1] < ar[0])
            tmp = 1;
        else
            tmp = min(n - id2, 2 + id2);
        ans = min(ans, tmp);
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