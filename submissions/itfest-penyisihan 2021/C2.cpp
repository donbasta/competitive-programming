#include<bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> ar;
    int x;
    while (cin >> x) { ar.push_back(x); }
    int n = (int) ar.size();
    // set<tuple<int, int, int>> se;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (ar[i] + ar[j] == ar[k]) {
                    vector<int> ve = {i, j, k};
                    sort(ve.begin(), ve.end());
                    cout << ar[ve[0]] << ' ' << ar[ve[1]] << ' ' << ar[ve[2]] << '\n';
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
  
    return 0;
}