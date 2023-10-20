#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void solve() {
    int n, k, e;
    cin >> n >> k >> e;
    int l = e, r = n - e - k;
    if (l > r) swap(l, r);
    int ans;
    if (r == 0) {
        ans = 0;
    } else if (l == 0) {
        if (r != k) {
            ans = 0;
        } else {
            if (k > 2) {
                ans = 0;
            } else if (k == 1) {
                ans = 1;
            } else if (k == 2) {
                ans = 1;
            }
        }
    } else if (l < r) {
        if (k > r) {
            ans = 0;
        } else if (k == r) {
            if (k == 2) {
                ans = 2;
            } else if (k == 3) {
                if (l == 1) {
                    ans = 1;
                } else if (l == 2) {
                    ans = 2;
                }
            } else if (k == 4) {
                if (l == 1 || l == 3)
                    ans = 1;
                else if (l == 2)
                    ans = 0;
            } else {
                ans = 0;
            }
        } else if (k < r && k > l) {
            ans = 0;
        } else if (k == l) {
            if (k <= 2) {
                ans = 1;
            } else {
                ans = 0;
            }
        } else if (k < l) {
            ans = 0;
        }
    } else if (l == r) {
        if (k > r) {
            if (l >= 5) {
                ans = 0;
            } else if (l == 4) {
                ans = 0;
            } else if (l == 3) {
                ans = 0;
            } else if (l == 2) {
                ans = 1;
            } else if (l == 1) {
                ans = 1;
            }
        } else if (k == r) {
            if (k >= 5) {
                ans = 0;
            } else if (k == 4) {
                ans = 2;
            } else if (k == 3) {
                ans = 3;
            } else if (k == 2) {
                ans = 3;
            } else if (k == 1) {
                ans = 2;
            }
        } else if (k < r) {
            if (k >= 4) {
                ans = 0;
            } else if (k == 3) {
                if (r == 4) {
                    ans = 1;
                } else {
                    ans = 0;
                }
            } else if (k == 2) {
                if (r == 3) {
                    ans = 2;
                } else {
                    ans = 0;
                }
            } else if (k == 1) {
                if (r == 2) {
                    ans = 2;
                } else if (r == 3) {
                    ans = 1;
                } else if (r == 4) {
                    ans = 1;
                } else {
                    ans = 0;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve();
    }

    return 0;
}