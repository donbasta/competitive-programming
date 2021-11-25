#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

ifstream fin;
ofstream fout;

void solve() {
    int tc, k;
    fin >> tc >> k;
    // cin >> tc >> k;
    while (tc--) {
        int n, m;
        fin >> n >> m;
        // cin >> n >> m;
        char win;
        if (n < k || m < k) {
            if ((n + m) & 1) {
                win = '+';
            } else {
                win = '-';
            }
        } else {
            int u = min((m - 1) / (k + 1), (n - 1) / (k + 1));
            u = u % 2;
            int v = min(m - 1, n - 1) % (k + 1);
            if (v == k) {
                win = '+';
            } else {
                int cek = ((m + n) & 1);
                if (k > 1) {
                    if ((u + cek) % 2 == 0) {
                        win = '-';
                    } else {
                        win = '+';
                    }                    
                } else {
                    if (cek % 2 == 0) {
                        win = '-';
                    } else {
                        win = '+';
                    }
                }
            }
        }
        fout << win << '\n';
        // cout << win << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fin.open("input.txt");
    fout.open("output.txt");

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }

    fin.close();
    fout.close();
  
    return 0;
}