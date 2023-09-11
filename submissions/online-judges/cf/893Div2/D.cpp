#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 0) {
        int cnt0 = 0, cnt1 = 0;
        int mx0 = 0, mx1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt0++;
                mx1 = max(mx1, cnt1);
                cnt1 = 0;
            } else {
                cnt1++;
                mx0 = max(mx0, cnt0);
                cnt0 = 0;
            }
        }
        mx0 = max(mx0, cnt0), mx1 = max(mx1, cnt1);
        for (int i = 1; i <= n; i++) {
            cout << (i * mx0 + mx1) << " \n"[i == n];
        }
        return;
    }

    vector<int> ri(n), ri1(n);
    int idx = 0;
    int cnt = s[0] == '1';
    for (int i = 0; i < n; i++) {
        while (idx < n - 1 && cnt <= k) {
            idx++;
            cnt += s[idx] == '1';
        }
        if (cnt > k)
            ri[i] = idx - 1;
        else
            ri[i] = idx;
        cnt -= s[i] == '1';
    }
    int idx1 = 0;
    int cnt1 = s[0] == '0';
    for (int i = 0; i < n; i++) {
        while (idx < n - 1 && cnt <= k) {
            idx++;
            cnt += s[idx] == '0';
        }
        if (cnt > k)
            ri1[i] = idx - 1;
        else
            ri1[i] = idx;
        cnt1 -= s[i] == '0';
    }
    // for (int i = 0; i < n; i++) {
    //     cout << i << ' ' << ri[i] << '\n';
    // }
    // find longest contiguous 1 on [0, i - 1] union [ri[i] + 1, n - 1]
    vector<int> pre(n), suf(n), pre0(n), suf0(n);
    cnt = 0;
    int cnt0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt++;
            if (i > 0) pre[i] = pre[i - 1];
            pre[i] = max(pre[i], cnt);

            cnt0 = 0;
            if (i > 0) pre0[i] = pre0[i - 1];
        } else {
            cnt = 0;
            if (i > 0) pre[i] = pre[i - 1];

            cnt0++;
            if (i > 0) pre0[i] = pre0[i - 1];
            pre0[i] = max(pre0[i], cnt0);
        }
    }
    cnt = 0;
    cnt0 = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            cnt++;
            if (i < n - 1) suf[i] = suf[i + 1];
            suf[i] = max(suf[i], cnt);

            cnt0 = 0;
            if (i < n - 1) suf0[i] = suf0[i + 1];
        } else {
            cnt = 0;
            if (i < n - 1) suf[i] = suf[i + 1];

            cnt0++;
            if (i < n - 1) suf0[i] = suf0[i + 1];
            suf0[i] = max(suf0[i], cnt0);
        }
    }

    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        int r = ri[i];
        int L0 = (r - i + 1);
        int L1 = 0;
        if (i > 0) L1 = max(L1, pre[i - 1]);
        if (r < n - 1) L1 = max(L1, suf[r + 1]);
        for (int j = 1; j <= n; j++) {
            ans[j] = max(ans[j], j * L0 + L1);
        }
    }
    for (int i = 0; i < n; i++) {
        int r = ri1[i];
        int L1 = (r - i + 1);
        int L0 = 0;
        if (i > 0) L0 = max(L0, pre0[i - 1]);
        if (r < n - 1) L0 = max(L0, suf0[r + 1]);
        for (int j = 1; j <= n; j++) {
            ans[j] = max(ans[j], j * L0 + L1);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}