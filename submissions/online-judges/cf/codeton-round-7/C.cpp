#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

void el_psy_congroo() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> ar(n);
    vector<int> br(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i].first;
        ar[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> br[i];
    }
    sort(ar.begin(), ar.end(), greater<>());
    sort(br.begin(), br.end(), greater<>());
    vector<int> res(n);
    int cnt = 0;
    for (int i = 0; i < x; i++) {
        if (br[i + n - x] >= ar[i].first) {
            cout << "NO" << '\n';
            return;
        }
        res[ar[i].second] = br[i + n - x];
    }
    for (int i = x; i < n; i++) {
        if (br[i - x] < ar[i].first) {
            cout << "NO" << '\n';
            return;
        }
        res[ar[i].second] = br[i - x];
    }
    cout << "YES" << '\n';
    for (auto e : res) {
        cout << e << ' ';
    }
    cout << '\n';
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