#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;

int n, q;
oset ose;

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ose.insert(make_pair(x, i));
    }

    int tmp = n;
    for (int i = 0; i < q; i++) {
        int type, d;
        cin >> type >> d;
        if (type == 1) {
            int a = ose.order_of_key(make_pair(d + 1, -1));
            ose.insert(make_pair(a + d, tmp++));
        } else if (type == 2) {
            int a = ose.order_of_key(make_pair(d + 1, -1));
            cout << a << '\n';
        } else if (type == 3) {
            if (d > tmp) {
                cout << "invalid\n";
                continue;
            }
            auto el = *(ose.find_by_order(d - 1));
            cout << el.first << '\n';
        } 
    }
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