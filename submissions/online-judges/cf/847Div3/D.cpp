#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n;
    cin >> n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
    sort(ve.begin(), ve.end());
    multiset<int> lasts;
    for (int i = 0; i < n; i++) {
        if (lasts.empty()) {
            lasts.insert(ve[i]);
        } else {
            if (lasts.count(ve[i] - 1)) {
                lasts.erase(lasts.find(ve[i] - 1));
            }
            lasts.insert(ve[i]);
        }
    }
    cout << lasts.size() << '\n';
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