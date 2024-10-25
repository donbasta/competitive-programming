#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;

struct vertex {
    vertex *l, *r;
    int s, e;
    int sum;

    vertex(int val, int s, int e) : l(nullptr), r(nullptr), sum(val) {}
    vertex(vertex *l, vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

vertex *init_zero(int s, int e) {
    if (s == e) return new vertex(0, s, e);
    int mid = (s + e) >> 1;
    return new vertex(init_zero(s, mid), init_zero(mid + 1, e));
}

int get(vertex *v, int s, int e, int l, int r) {
    if (s == l && e == r) return v->sum;
    int mid = (s + e) >> 1;
    if (r <= mid)
        return get(v->l, s, mid, l, r);
    else if (l >= mid + 1)
        return get(v->r, mid + 1, e, l, r);
    return get(v->l, s, mid, l, mid) + get(v->r, mid + 1, e, mid + 1, r);
}

vertex *upd(vertex *v, int s, int e, int pos, int val) {
    if (s == e) return new vertex(val, s, e);
    int mid = (s + e) >> 1;
    if (pos <= mid)
        return new vertex(upd(v->l, s, mid, pos, val), v->r);
    else
        return new vertex(v->l, upd(v->r, mid + 1, e, pos, val));
}

void el_psy_congroo() {
    int n;
    cin >> n;
    string tmp;
    getline(cin, tmp);
    vector<vector<pair<int, int>>> u(n);

    vector<vertex *> states(n + 1);
    vertex *cur = init_zero(0, n - 1);
    states[0] = cur;
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        getline(cin, tmp);
        string buf;
        for (int j = 0; j < tmp.length(); j++) {
            if (tmp[j] == ' ') {
                int c = (buf[0] == '+' ? 1 : -1);
                int num = stoi(buf.substr(1, buf.length() - 1));
                u[i].emplace_back(num, c);
                buf.clear();
            } else {
                buf += tmp[j];
            }
        }
        if (buf.length() > 0) {
            int c = (buf[0] == '+' ? 1 : -1);
            int num = stoi(buf.substr(1, buf.length() - 1));
            u[i].emplace_back(num, c);
        }
        for (auto e : u[i]) {
            int val = e.first, op = e.second;
            cnt[val] += op;
            cur = upd(cur, 0, n - 1, val, cnt[val]);
        }
        states[i + 1] = cur;
    }
    // for (int i = 0; i < n; i++) {
    //     cerr << i << ' ' << get(states[i], 0, n - 1, 0, n - 1) << '\n';
    // }
    int X = 0;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        int que = get(states[d], 0, n - 1, X, n - 1);
        X = (X + que) % n;
    }
    cout << X << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}