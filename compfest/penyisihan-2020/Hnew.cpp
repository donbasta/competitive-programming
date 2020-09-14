#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int M = 1e5 + 10;
const int MOD = 1e9 + 7;
const int base = 31;

int pw[M + 5];

void init_base() {
  pw[0] = 1;
  for(int i = 1; i <= M; i++) {
    pw[i] = (1LL * pw[i - 1] * base) % MOD;
  }
}

inline int get_hash(const string& S) {
  int ret = 0;
  for(int i = 0; i < (int)S.length(); i++) {
    int cur = S[i] - 'a';
    ret = (1LL * ret + 1LL * pw[i] * cur) % MOD;
  }
  return ret;
}

int m;
int n, q;
string st;
int len;
vector<string> katas;
int pre[M];

unordered_map<int, bool> ada;
bool cek(int a){
    if (ada.count(a)) return 1;
    return 0;
}

struct Node{
    int count = 0;
    int ckata = 0;
    int le, ri;
    vector<int> hash;
    Node() {}
    Node(char c, int pos){
        if (c == ' '){
            ckata = count = 0;
            le = ri = pos;
            return;
        }
        string temp = "";
        temp.pb(c);
        int hh = get_hash(temp);
        hash.pb(hh);
        if (cek(hh)) count++;
        ckata = 1;
        le = ri = pos;
    }
    void merge(const Node& a, const Node& b){
        if (st[a.ri] == ' ' || st[b.le] == ' '){
            count = a.count + b.count;
            ckata = a.ckata + b.ckata;
            le = a.le;
            ri = b.ri;
            hash.clear();
            if (a.hash.size()) hash.pb(a.hash[0]);
            if (b.hash.size()) hash.pb(b.hash.back());
            return;
        }
        count = a.count + b.count;
        ckata = a.ckata + b.ckata - 1;

        int nhh = (1LL * a.hash.back() + 1LL * b.hash[0] * pw[a.ri - a.le + 1] % MOD) % MOD;
        if (cek(a.hash.back())) count--;
        if (cek(b.hash[0])) count--;
        if (cek(nhh)) count++;

        le = a.le;
        ri = b.ri;
        hash.clear();
        hash.pb(a.hash[0]);
        hash.pb(b.hash.back());
    }
};

Node t[4 * M];
void build(int v, int tl, int tr){
    if (tl == tr){
        t[v] = Node(st[tl], tl);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v].merge(t[v * 2], t[v * 2 + 1]);
}
void update(int v, int tl, int tr, int pos, char nc){
    if (tr < pos || pos < tl) return;
    if (tl == tr){
        st[pos] = nc;
        t[v] = Node(nc, tl);
        return;
    } 
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, pos, nc);
    update(v * 2 + 1, tm + 1, tr, pos, nc);
    t[v].merge(t[v * 2], t[v * 2 + 1]);
}
Node ask(int v, int tl, int tr, int l, int r){
    if (l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    if (l >= tm + 1) return ask(v * 2 + 1, tm + 1, tr, l, r);
    else if (r <= tm) return ask(v * 2, tl, tm, l, r);
    Node ret;
    ret.merge(ask(v * 2, tl, tm, l, tm), ask(v * 2 + 1, tm + 1, tr, tm + 1, r));
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m;
    {
        cin.ignore();
        getline(cin, st);
        len = st.size();
        stringstream ss(st);
        string temp;
        while (ss >> temp){
            katas.pb(temp);
        }
        for (int i=1;i<=m;i++){
            pre[i] = pre[i - 1] + katas[i - 1].size();
            if (i != 1) pre[i]++;
        }
    }    
    cin >> n >> q;
    while (n--){
        string s;
        cin >> s;
        ada[get_hash(s)] = 1;
    }
    build(1, 0, len - 1);

    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 0){
            int i, j;
            char nc;
            cin >> i >> j >> nc;
            int pos = pre[i - 1] + j - 1;
            update(1, 0, len - 1, pos, nc);
        } else{
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << ask(1, 0, len - 1, l, r).count << el;
        }
    }

    return 0;
}