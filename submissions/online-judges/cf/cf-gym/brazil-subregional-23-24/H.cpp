#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    ll s;
    cin >> n >> s;
    vector<pair<pair<int, int>, ll>> jobs;
    for (int i = 0; i < n; i++) {
        int l, r;
        ll c;
        cin >> l >> r >> c;
        jobs.emplace_back(make_pair(l, r), c);
    }
    sort(jobs.begin(), jobs.end());
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