#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll INF = 1e18 + 69;

ll minXOR(const vector<int>& ve, int bit, int l1, int r1, int l2, int r2) {
    if (l1 >= r1 || l2 >= r2)
        return INF;
    if (bit < 0)
        return 0LL;
    int m1 = l1, m2 = l2;
    while (m1 < r1 && !((ve[m1] >> bit) & 1)) m1++;
    while (m2 < r2 && !((ve[m2] >> bit) & 1)) m2++;
    if ((l1 < m1 && l2 < m2) || (m1 < r1 && m2 < r2))
        return min(minXOR(ve, bit - 1, l1, m1, l2, m2), minXOR(ve, bit - 1, m1, r1, m2, r2));
    else
        return min(minXOR(ve, bit - 1, l1, m1, m2, r2), minXOR(ve, bit - 1, m1, r1, l2, m2)) + (1LL << bit);
}

ll solve(const vector<int>& ve, int bit, int l, int r) {
    ll temp;
    if (bit < 0 || r - l <= 1)
        return 0LL;
    int cur = l;
    while (cur < r && !((ve[cur] >> bit) & 1))
        cur++;
    temp = solve(ve, bit - 1, l, cur) + solve(ve, bit - 1, cur, r);
    if (l < cur && cur < r)
        temp += (minXOR(ve, bit - 1, l, cur, cur, r) + (1LL << bit));
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar.begin(), ar.end());
    cout << solve(ar, 29, 0, n) << '\n';
    return 0;
}