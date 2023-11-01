#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

vector<vector<ll>> digits_sum_square(ll x, ll gr) {
    vector<vector<ll>> ret;
    for (int i = gr; i >= 1; i--) {
        if (i * i > x)
            continue;
        else if (i * i == x)
            ret.push_back(vector<ll>{i});
        else {
            vector<vector<ll>> tmp = digits_sum_square(x - i * i, i);
            for (auto e : tmp) {
                e.push_back(i);
                ret.push_back(e);
            }
        }
    }
    return ret;
}

void generate_good_numbers() {
}

void el_psy_congroo() {
    // ll a, b;
    // cin >> a >> b;
    // ll ans = get(b) - get(a - 1);
    // cout << ans << '\n';
    vector<vector<ll>> x = digits_sum_square(10, 9);
    for (auto e : x) {
        for (auto ee : e) {
            cerr << ee << ' ';
        }
        cerr << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    generate_good_numbers();

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}