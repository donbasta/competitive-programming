#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int N = 1e5;

vector<int> pr[N + 5];
int ar[N + 5];

int n, q;

vector<int> getPrimeFactors(int x) {
    vector<int> ret;
    for (int i = 2; i * i <= n; i++) {
        if (x % i == 0) {
            ret.emplace_back(i);
            while (x % i == 0) x /= i;
        }
        if (x == 1) break;
    }
    if (x > 1) ret.emplace_back(x);
    return ret;
}

struct Node {
    vector<int> l, r;
    int count;
    Node () {}
    Node (int x, int idx) : count(1) {
        l = r = pr[idx];
    }
    Node (int cnt, const vector<int>& a, const vector<int> b) {
        count = cnt, l = a, r = b;
    }
} t[4 * N + 5];

bool isect(const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0;
    while (i < (int) a.size() && j < (int) b.size()) {
        if (a[i] < b[j]) i++;
        else if (a[i] > b[j]) j++;
        else return true;
    }
    return false;
}

Node merge (Node a, Node b) {
    int tot = a.count + b.count;
    if (!isect(a.r, b.l)) {
        return Node(tot - 1, a.l, b.r);
    }
    return Node(tot, a.l, b.r);
}

void build (int v, int s, int e) {
    if (s == e) {
        t[v] = Node(ar[s], s);
    } else {
        int mid = (s + e) >> 1;
        build (v << 1, s, mid);
        build (v << 1 | 1, mid + 1, e);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

Node get (int v, int s, int e, int l, int r) {
    if (l == s && r == e) return t[v];
    int mid = (s + e) >> 1;
    if (r <= mid) return get(v << 1, s, mid, l, r);
    else if (l >= mid + 1) return get(v << 1 | 1, mid + 1, e, l, r);
    else {
        return merge(
                get (v << 1, s, mid, l, mid),
                get (v << 1 | 1, mid + 1, e, mid + 1, r));
    }
} 

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pr[i] = getPrimeFactors(ar[i]);

    }
    build (1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << get (1, 1, n, l, r).count << '\n';
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