#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll M = 1e14;
const int B = 14;
ll pw10[B + 1];

void init() {
    pw10[0] = 1;
    for (int i = 1; i <= B; i++) {
        pw10[i] = pw10[i - 1] * 10;
    }
}

ll f(const string& S) {
    int len = S.length();
    vector<ll> pref(len);
    for (int i = 0; i < len; i++) {
        pref[i] = stoll(S.substr(0, i + 1));
    }
    ll ret = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            ll tmp = 0;
            if (j < len - 1) {
                tmp += 45ll * pw10[j - 1] * max(0ll, pref[len - j - 2] - 1);
                tmp += 36ll * pw10[j - 1];
            }
            int cur_j = S[len - 1 - j] - '0';
            int cur_i = S[len - 1 - i] - '0';
            if (cur_j >= 1) {
                if (j < len - 1) {
                    tmp += pw10[j - 1] * (cur_j * 9 - (cur_j - 1) * (cur_j) / 2);
                } else {
                    tmp += pw10[j - 1] * ((cur_j - 1) * 9 - (cur_j - 1) * (cur_j) / 2);
                }
            }
            if (i <= j - 2) {
                ll mid = stoll(S.substr(len - j, j - i - 1));
                tmp += mid * (9 - cur_j) * pw10[i];
            }
            tmp += 1ll * max(0, cur_i - 1 - cur_j) * pw10[i];
            if (cur_i > cur_j) {
                if (i == 0)
                    tmp++;
                else
                    tmp += stoll(S.substr(len - i, i)) + 1;
            }
            ret += tmp;
        }
    }
    return ret;
};

void el_psy_congroo() {
    ll x, y;
    cin >> x >> y;
    if (x == M && y == M) {
        cout << 0 << '\n';
        return;
    }
    if (y == M) y--;
    string sx = to_string(x - 1), sy = to_string(y);
    ll Y = f(sy), X = f(sx);
    cout << (Y - X) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        cout << "Case " << i << ": ";
        el_psy_congroo();
    }

    return 0;
}