#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> ar(n), br(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> br[i];
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        int ma = *min_element(ar.begin() + i, ar.end());
        int mb = *min_element(br.begin() + i, br.end());
        vector<bool> isMin(n);
        bool cool = false;
        for (int j = i; j < n; j++) {
            if (ar[j] == ma) {
                isMin[j] = true;
            }
        }
        for (int j = i; j < n; j++) {
            if (br[j] == mb && isMin[j]) {
                if (j != i) {
                    ans.emplace_back(i, j);
                    swap(ar[i], ar[j]);
                    swap(br[i], br[j]);
                }
                cool = true;
                break;
            }
        }
        if (!cool) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.first + 1 << ' ' << e.second + 1 << '\n';
    }
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
