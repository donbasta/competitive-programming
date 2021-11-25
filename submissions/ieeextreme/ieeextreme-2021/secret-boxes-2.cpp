#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// vector<int> ISI = {2, 3, 4, 1, 5};
vector<int> ISI = {4, 5, 6, 1, 2, 7, 8, 3, 9, 10};// {4, 5, 6, 1, 2, 7, 8, 3, 9, 10};// {1, 2, 3, 4, 5};
// vector<int> ISI = {7, 3, 1, 8, 9, 2, 6, 5, 4, 10};

int ask(vector<int> vec){
    assert(vec.size() == 4);
    cout << "? " << vec[0] << " " << vec[1] << " " << vec[2] << " " << vec[3] << endl;
    // char res;
    // cin >> res;
    // if (res == '<') return -1;
    // else if (res == '=') return 0;
    // return 1;
    int a = ISI[vec[0] - 1] + ISI[vec[1] - 1];
    int b = ISI[vec[2] - 1] + ISI[vec[3] - 1];
    if (a < b){
        cout << "<" << el;
        return -1;
    } else if (a == b){
        cout << "=" << el;
        return 0;
    }
    cout << ">" << el;
    return 1;
}
int ask(int a, int b, int c, int d){
    return ask(vector<int>{a, b, c, d});
}
vector<vector<int>> urutan = {
    {0, 1, 2, 3},
    {0, 2, 1, 3},
    {0, 3, 1, 2}
};
vector<int> bf4(vector<int> vec){
    assert(vec.size() == 4);
    vector<int> ret(4, 0);
    for (auto& urut : urutan){
        vector<int> temp;
        for (auto& x : urut) temp.pb(vec[x]);
        int res = ask(temp);
        if (res == -1){
            for (int i=0;i<4;i++){
                if (i < 2) ret[urut[i]]--;
                else ret[urut[i]]++;
            }
        } else if (res == 1){
            for (int i=0;i<4;i++){
                if (i < 2) ret[urut[i]]++;
                else ret[urut[i]]--;
            }
        }
    }
    return ret;
}
vector<int> bf5(vector<int> vec){ // length = 5
    vector<int> ret(5, 0);
    vector<vector<int>> higher(5, vector<int>(5, 0));
    for (int ex=0;ex<5;ex++){
        vector<int> tvec, id;
        for (int i=0;i<5;i++){
            if (i == ex) continue;
            tvec.pb(vec[i]);
            id.pb(i);
        }
        auto temp = bf4(tvec);
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                if (i == j) continue;
                if (temp[i] > temp[j]) higher[id[i]][id[j]] = 1;
                if (temp[j] > temp[i]) higher[id[j]][id[i]] = 1;
            }
        }
    }
    for (int i=0;i<5;i++){
        for (int j=0;j<5;j++){
            ret[i] += higher[i][j];
            // cout << higher[i][j] << ' ';
        }
        // cout << el;
    }
    return ret;
}
vector<int> find_min(vector<int> vec, vector<int> cnt){
    vector<pii> temp;
    int n = vec.size();
    for (int i=0;i<n;i++){
        temp.emplace_back(cnt[i], vec[i]);
    }
    sort(temp.begin(), temp.end());
    return {temp[0].se, temp[1].se, temp[2].se};
}
vector<int> find_max(vector<int> vec, vector<int> cnt){
    vector<pii> temp;
    int n = vec.size();
    for (int i=0;i<n;i++){
        temp.emplace_back(cnt[i], vec[i]);
    }
    sort(temp.begin(), temp.end());
    return {temp[n - 1].se, temp[n - 2].se, temp[n - 3].se};
}

int q;
int n;
void msort(vector<int>& vec, int l, int r, int a, int b){
    if (l >= r) return;
    int m = (l + r) / 2;
    msort(vec, l, m, a, b);
    msort(vec, m + 1, r, a, b);

    int i = l;
    int j = m + 1;
    vector<int> temp;
    while (i <= m && j <= r){
        if (vec[i] == a || vec[i] == b){
            if (vec[j] == a || vec[j] == b){
                if (vec[i] == a) temp.pb(vec[i++]);
                else temp.pb(vec[j++]);
            } else{
                temp.pb(vec[i++]);
            }
        } else if (vec[j] == a || vec[j] == b){
            temp.pb(vec[j++]);
        } else{
            auto res = ask(vec[i], b, vec[j], a);
            if (res <= 0) temp.pb(vec[i++]);
            else temp.pb(vec[j++]);
        }
    }
    while (i <= m){
        temp.pb(vec[i++]);
    }
    while (j <= r){
        temp.pb(vec[j++]);
    }
    for (int i=l;i<=r;i++){
        vec[i] = temp[i - l];
    }
}
void answer(vector<int> vec){
    vector<int> ans(n);
    for (int i=0;i<n;i++){
        ans[vec[i] - 1] = i + 1;
    }
    cout << "! ";
    for (auto& x : ans) cout << x << ' ';
    cout << endl;
    cout << "ISI: ";
    for (auto& x : ISI) cout << x << ' ';
    cout << endl;
    assert(ans == ISI);
    string res;
    cin >> res;
}
void solve(){
    if (n == 5){
        vector<int> cur = {1, 2, 3, 4, 5};
        auto temp = bf5(cur);
        vector<pii> ans;
        for (int i=0;i<5;i++){
            ans.emplace_back(temp[i], cur[i]);
        }
        sort(ans.begin(), ans.end());
        vector<int> ret(5);
        for (int i=0;i<5;i++){
            ret[i] = ans[i].se;
        }
        answer(ret);
        next_permutation(ISI.begin(), ISI.end());
        return;
    }
    vector<int> vec;
    for (int i=1;i<=n;i++){
        vec.pb(i);
    }
    vector<int> carry;
    // cari 3 minimum
    for (int i=0;i<n;i+=2){
        if (i == 0){
            vector<int> cur;
            for (int j=0;j<5;j++){
                cur.pb(vec[i + j]);
            }
            carry = find_min(cur, bf5(cur));
            i += 3;
            cout << "CUR: ";
            for (auto& x : cur){
                cout << x << " ";
            }
        } else{
            vector<int> cur = carry;
            for (int j=0;j<2;j++){
                if (i + j >= n) break;
                cur.pb(vec[i + j]);
            }
            while (cur.size() < 5){
                for (int j=0;j<n;j++){
                    bool ok = 1;
                    for (auto& x : cur){
                        if (vec[j] == x){
                            ok = 0;
                            break;
                        }
                    }
                    if (ok){
                        cur.pb(vec[j]);
                        break;
                    }
                }
            }
            carry = find_min(cur, bf5(cur));
            cout << "CUR: ";
            for (auto& x : cur){
                cout << x << " ";
            }
            cout << endl;
            
        }
        cout << "CARRY: ";
        for (auto& x : carry){
            cout << x << " ";
        }
        cout << endl;
    }
    int a = carry[0];
    int b = carry[1];
    int c = carry[2];

    //cari 3 maximum
    for (int i=0;i<n;i+=2){
        if (i == 0){
            vector<int> cur;
            for (int j=0;j<5;j++){
                cur.pb(vec[i + j]);
            }
            carry = find_max(cur, bf5(cur));
            i += 3;
        } else{
            vector<int> cur = carry;
            for (int j=0;j<2;j++){
                if (i + j >= n) break;
                cur.pb(vec[i + j]);
            }
            while (cur.size() < 5){
                for (int j=0;j<n;j++){
                    bool ok = 1;
                    for (auto& x : cur){
                        if (vec[j] == x){
                            ok = 0;
                            break;
                        }
                    }
                    if (ok){
                        cur.pb(vec[j]);
                        break;
                    }
                }
            }
            carry = find_max(cur, bf5(cur));
        }
    }
    int ma = carry[0];
    int mb = carry[1];
    int mc = carry[2];

    int mn3, mx3;

    vector<int> test = find_max({a, b, c, ma, mb}, bf5({a, b, c, ma, mb}));
    for (int i = 0; i < 3; i++) {
        if (test[i] == a) {
            //a adalah yg third smallest 
            mn3 = a;
            break;
        } else if (test[i] == b) {
            mn3 = b;
            break;
        } else if (test[i] ==c) {
            mn3 = c;
            break;
        }
    }
    test = find_min({a, b, ma, mb, mc}, bf5({a, b, ma, mb, mc}));
    for (int i = 0; i < 3; i++) {
        if (test[i] == ma) {
            //ma adalah yg third largest 
            mx3 = ma;
            break;
        } else if (test[i] == mb) {
            mx3 = mb;
            break;
        } else if (test[i] == mc) {
            mx3 = mc;
            break;
        }
    }

    vector<int> mn2s, mx2s;
    for (int x : {a, b, c}) {
        if (x == mn3) {
            continue;
        }
        mn2s.push_back(x);
    }
    for (int x : {ma, mb, mc}) {
        if (x == mx3) {
            continue;
        }
        mx2s.push_back(x);
    }
    a = mn2s[0], b = mn2s[1];
    {
        int y = mx2s[0], z = mx2s[1];
        vector<int> cnt(2, 0);
        int temp;
        temp = ask(a, y, b, z);
        if (temp == -1) cnt[0]++;
        else if (temp == 1) cnt[1]++;
        temp = ask(a, z, b, y);
        if (temp == -1) cnt[0]++;
        else if (temp == 1) cnt[1]++;
        if (cnt[0] < cnt[1]) swap(a, b);
    }

    msort(vec, 0, n - 1, a, b);
    answer(vec);
    next_permutation(ISI.begin(), ISI.end());
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // cin >> q >> n;
    q = 10;
    n = 10;
    while (q--){
        solve();
    }

    return 0;
}