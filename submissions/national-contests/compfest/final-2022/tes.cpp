#include <bits/stdc++.h>

using namespace std;

bool dp[1 << 22];
int ans[1 << 22];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int arr[n + 1];

    int x;
    int maks = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ans[x] = x;
        arr[i] = x;
        maks = max(maks, x);
        dp[x] = true;
    }

    int sz = 0, temp = 1;
    while (temp <= maks) {
        sz++;
        temp <<= 1;
    }
    int lol = (1 << sz) - 1;

    for (int i = 0; i <= lol; i++) {
        for (int j = 0; j < sz; j++) {
            if (i & (1 << j)) {
                dp[i] |= dp[i ^ (1 << j)];
                if (ans[i] == 0 && ans[i ^ (1 << j)] != 0) ans[i] = ans[i ^ (1 << j)];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dp[lol ^ arr[i]] ? ans[lol ^ arr[i]] : -1) << " ";
    }
}
