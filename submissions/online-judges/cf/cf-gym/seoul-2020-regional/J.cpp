#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

// int rank(vector<vector<int>> T) {
//     int n = T.size();
//     int rn = 0;
//     vector<bool> sel(n, false);
//     for (int i = 0; i < n; i++) {
//         int j;
//         for (int j = 0; j < n; j++) {
//             if (!sel[j] && T[j][i] > 0) {
//                 break;
//             }
//         }
//         if (j != n) {
//             rn++;
//             sel[j] = true;
//             for (int k = 0; k < n; k++) {
//                 if (k != j && T[k][i] > 0) {
//                     for (int p = i + 1; p < n; p++) {
//                         T[k][p] = (T[k][p] - T[j][p] * T[k][i]) % 2;
//                         if (T[k][p] < 0) T[k][p] += 2;
//                     }
//                 }
//             }
//         }
//     }
//     return rn;
// }

// vector<vector<int>> inverse(vector<vector<int>> T) {

// }

void solve() {
    cerr << ~0 << '\n';
    // int n;
    // cin >> n;
    // vector<vector<int>> M(n, vector<int>(n));
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cin >> M[j][i];
    //     }
    // }
    // int r = rank(M);
    // if (r < n) {
    //     cout << -1 << '\n';
    //     return;
    // }
    // vector<vector<int>> MI = inverse(M);
    // vector<vector<int>> ans;
    // for (int i = 0; i < n; i++) {
    //     vector<int> tmp;
    //     for (int j = 0; j < n; j++) {
    //         if (M[j][i] == 1) {
    //             tmp.emplace_back(j + 1);
    //         }
    //     }
    //     ans.emplace_back(tmp);
    // }
    // for (int i = 0; i < n; i++) {
    //     for (auto e : ans[i]) {
    //         cout << e << " ";
    //     }
    //     cout << '\n';
    // }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}