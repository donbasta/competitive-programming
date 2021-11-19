/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 2e5;
ll mobius[N + 5];
bool composite[N + 5];

void sieveMobius() {
    vector<int> pr;
    mobius[1] = 1;
    for(int i = 2; i < N; i++) {
        if (!composite[i]) {
            mobius[i] = -1;
            pr.push_back(i);
        }
        for(int j = 0; j < (int)pr.size(); j++) {
            if (i * pr[j] > N) break;
            composite[i * pr[j]] = true;
            if (i % pr[j] != 0) {
                mobius[i * pr[j]] = mobius[i] * (-1);
            } else {
                mobius[i * pr[j]] = 0;
                break;
            }
        }
    }
}

void solve () {
    int n;
    cin >> n;
    vector<ll> ar(n + 1), br(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> br[i];
        br[i] -= ar[i];
    }
    vector<ll> A, B;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int ti = i;
        vector<int> pr;
        for (int j = 2; j * j <= ti; j++) {
            if (ti % j == 0) {
                pr.push_back(j);
                while (ti % j == 0) {
                    ti /= j;
                }
            }
        }
        if (ti > 1) {
            pr.emplace_back(ti);
        }
        ll ret = 0;
        if (mobius[i] == 0) {
            for (int j = 0; j < (1 << pr.size()); j++) {
                int tmp = 1;
                for (int k = 0; k < pr.size(); k++) {
                    if (j & (1 << k)) {
                        tmp *= pr[k];
                    }
                }
                ret += mobius[tmp] * br[i / tmp];        
            }
            ans += abs(ret);
        } else {
            for (int j = 0; j < (1 << pr.size()); j++) {
                int tmp = 1;
                for (int k = 0; k < pr.size(); k++) {
                    if (j & (1 << k)) {
                        tmp *= pr[k];
                    }
                }
                if (tmp == i) {
                    if (mobius[tmp] == -1) {
                        A.emplace_back(ret);
                    } else {
                        B.emplace_back(ret);
                    }
                    break;
                }
                ret += mobius[tmp] * br[i / tmp];
            }
        }
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    vector<ll> pa(A.size() + 1), pb(B.size() + 1);
    if (A.size() > 0) {
        pa[0] = A[0];
        for (int i = 1; i < A.size(); i++) {
            pa[i] = pa[i - 1] + A[i];
        }
    }
    if (B.size() > 0) {
        pb[0] = B[0];
        for (int i = 1; i < B.size(); i++) {
            pb[i] = pb[i - 1] + B[i];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        x -= ar[1];
        ll ret = ans;
        if (A.size() > 0) {
            int aa = lower_bound(A.begin(), A.end(), x) - A.begin();
            if (aa > 0) {
                ret += (1LL * aa * x - pa[aa - 1]);
            }
            ret += (pa[A.size() - 1] - (aa > 0 ? pa[aa - 1] : 0) - 1LL * (A.size() - aa) * x);
        }
        x = -x;
        if (B.size() > 0) {
            int bb = lower_bound(B.begin(), B.end(), x) - B.begin();
            if (bb > 0) {
                ret += (1LL * bb * x - pb[bb - 1]);
            }
            ret += (pb[B.size() - 1] - (bb > 0 ? pb[bb - 1] : 0) - 1LL * (B.size() - bb) * x);
        }
        cout << ret << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    sieveMobius();

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        solve ();
    }

    return 0;
}