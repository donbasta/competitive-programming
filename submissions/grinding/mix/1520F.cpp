#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 2e9;

struct BIT {
    vector<int> tree;
    int n;
    BIT(int n) : n(n), tree(n + 1) {}
    void upd(int idx, int val) {
        while (idx <= n) tree[idx] += val, idx += idx & -idx;
    }
    int get(int idx) {
        int ret = 0;
        while (idx) ret += tree[idx], idx -= idx & -idx;
        return ret;
    }
};

int query(int l, int r) {
    cout << "? " << (l + 1) << ' ' << (r + 1) << endl;
    int ans;
    cin >> ans;
    return ans;
}

void answer(int x) {
    cout << "! " << (x + 1) << endl;
}

void el_psy_congroo() {
    int n, t;
    cin >> n >> t;
    BIT bit(n);
    set<pair<int, int>> se;
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        int l = 0, r = n - 1, alr = 0;

        if (!se.empty()) {
            auto ptr = se.lower_bound(make_pair(k, -1));
            if (ptr == se.end()) {
                r = n - 1;
            } else {
                r = ptr->second;
            }
            if (ptr == se.begin()) {
                l = 0;
            } else {
                --ptr;
                alr = ptr->first;
                l = ptr->second + 1;
            }
        }
        int need = k - alr;
        int pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int ans = query(l, r);
            if (ans >= need) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        assert(pos != -1);
        answer(pos);
        se.emplace(k - 1, pos);
    }
}

int main() {
    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}