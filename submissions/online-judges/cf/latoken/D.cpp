#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

int n;

void ask(int x) { cout << "? " << x << endl; }

vector<int> ans() {
    vector<int> ret(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ret[i];
    }
    return ret;
}

void solve() {
    cin >> n;
    set<int> se;
    for (int i = 1; i <= n; i++) {
        se.emplace(i);
    }
    vector<vector<bool>> ada(n + 1, vector<bool>(n + 1));
    vector<bool> hilang(n + 1);
    vector<pair<int, int>> edges;
    vector<vector<int>> jar(n + 1);
    while ((int)edges.size() < n - 1) {
        int cur = *se.begin();
        ask(cur);
        se.erase(se.begin());
        jar[cur] = ans();
        vector<int> satu, dua;
        for (int i = 1; i <= n; i++) {
            if (i == cur) continue;
            if (jar[cur][i] == 1) { satu.emplace_back(i); }
            if (jar[cur][i] == 2) { dua.emplace_back(i); }
        }
        if (satu.size() == 1) {
            int tet = satu[0];
            if (!ada[min(cur, tet)][max(cur, tet)]) {
                ada[min(cur, tet)][max(cur, tet)] = true;
                edges.emplace_back(min(cur, tet), max(cur, tet));
            }
            if (!hilang[tet]) {
                hilang[tet] = true;
                se.erase(tet);
            }
            for (auto& e : dua) {
                if (!ada[min(e, tet)][max(e, tet)]) {
                    ada[min(e, tet)][max(e, tet)] = true;
                    edges.emplace_back(min(e, tet), max(e, tet));
                }
                if (!hilang[e]) {
                    hilang[e] = true;
                    se.erase(e);
                }
            }
        } else if (satu.size() > 1) {
            for (auto& e : satu) {
                if (!ada[min(e, cur)][max(e, cur)]) {
                    ada[min(e, cur)][max(e, cur)] = true;
                    edges.emplace_back(min(e, cur), max(e, cur));
                }
                if (!hilang[e]) {
                    hilang[e] = true;
                    se.erase(e);
                }
            }   
        }
        // cout << "debug " << edges.size() << endl;
    }
    cout << "!\n";
    for (auto edge: edges) {
        cout << edge.first << ' ' << edge.second << endl;
    }
    // cout << endl;
}

int main() {
    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}