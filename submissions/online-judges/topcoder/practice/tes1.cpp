#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 2e9;

class Caketown {
   public:
    int howManyBites(vector<int> ve, int k) {
        sort(ve.begin(), ve.end(), greater<>());
        int n = ve.size();
        int ret = 0;
        for (int i = 0; i < n; i += (k + 1)) {
            ret += ve[i];
        }
        return ret;
    }
};

void el_psy_congroo() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    Caketown C;
    cout << C.howManyBites(ar, k) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    // cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}