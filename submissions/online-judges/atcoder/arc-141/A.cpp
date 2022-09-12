#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    string n;
    cin >> n;
    ll zn = stoll(n);
    ll ans = -1;
    int l = n.length();
    for (int i = 2; i <= l; i++) {
        // cerr << i << '\n';
        if (l % i != 0) continue;
        string pre = n.substr(0, l / i);
        bool isPowerTen = (pre[0] == '1');
        for (int j = 1; j < (int) pre.length(); j++) {
            if (pre[j] != '0') {
                isPowerTen = false;
            }
        }
        ll a = stoll(pre);
        bool ok = false;
        ll tmp = -1;
        int same = 0;
        for (int j = 1; j < i; j++) {
            string nx = n.substr(j * (l / i), l / i);
            ll b = stoll(nx);
            if (b < a) {
                break;
            } else if (b > a) {
                string ss = pre;
                for (int k = 1; k < i; k++) {
                    ss += pre;
                }
                tmp = stoll(ss);
                ok = true;
                break;
            } else {
                same++;
            }
        }
        if (same == (i - 1)) {
            tmp = zn;
        } else if (!ok) {
            ll kk = stoll(pre);
            --kk;
            string lol = to_string(kk);
            string ss = lol;
            for (int k = 1; k < i; k++) {
                ss += lol;
                if (isPowerTen && lol != "0") ss.push_back('9');
            }
            tmp = stoll(ss);
        }
        // cerr << i << ' ' << tmp << '\n';
        ans = max(ans, tmp);
    }
    if (ans <= 10) {
        string sss;
        for (int i = 0; i < l - 1; i++) {
            sss.push_back('9');
        }
        cout << sss << '\n';
        return;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}