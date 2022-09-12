#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<bool> sp(26);
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        sp[c - 'a'] = true;
    }

    oset ose;
    set<int> se;
    for (int i = 0; i < n; i++) {
        ose.insert(i);
        if (sp[s[i] - 'a']) se.insert(i);
    }

    int move = 0;
    while (true) {
        vector<int> rem;
        for (auto c : se) {
            int ord = ose.order_of_key(c);
            if (ord == 0) continue;
            int de = *ose.find_by_order(ord - 1);
            rem.push_back(de);
        }
        if (rem.empty()) {
            break;
        }
        for (auto e : rem) {
            if (se.count(e)) {
                se.erase(e);
            }
            ose.erase(e);
        }
        move++;
    }
    cout << move << '\n';    
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