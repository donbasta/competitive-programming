#include <bits/stdc++.h>
 
 
#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
const int N = 1e5 + 10;
 
// 00 01 10 11
int ar[5];
int cnt[2];
 
int cari(ll x){
    ll low = 0, high = N;
    while (low < high){
        ll mid = (low + high) / 2;
        if (mid * (mid - 1LL) / 2LL >= x){
            high = mid;
        } else{
            low = mid + 1;
        }
    }
    if (high == 1) high = 0;
    if (high * (high - 1LL) / 2LL == x) return high;
    return -1;
}
 
void dismiss(){
    cout << "impossible" << el;
    exit(0);
}
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    for (int i=1;i<=4;i++){
        cin >> ar[i];
    }
    cnt[0] = cari(ar[1]);
    cnt[1] = cari(ar[4]);
    if (cnt[0] == -1 || cnt[1] == -1){
        dismiss();
    }
    if (cnt[0] == 0){
        if (ar[2] || ar[3]){
            cnt[0]++;
        }
    } 
    if (cnt[1] == 0){
        if (ar[2] || ar[3]){
            cnt[1]++;
        }
    }
 
    string ans;
    for (int i=0;i<cnt[0];i++){
        ans.pb('0');
    }
    for (int i=0;i<cnt[1];i++){
        ans.pb('1');
    }
    int n = ans.length();
    int last0 = cnt[0] - 1, last1 = n - 1;
    int cur0 = cnt[0] * cnt[1];
    if (cur0 != ar[2] + ar[3]) dismiss();
    if(cnt[0] == 0 && cnt[1] == 0) dismiss();
    cur0 -= ar[2];
 
    while (cur0){
        if (cur0 >= cnt[1]){
            cur0 -= cnt[1];
            swap(ans[last0], ans[last1]);
            last0--;
            last1--;
        } else{
            int p = last0;
            while (cur0){
                swap(ans[p], ans[p + 1]);
                p++;
                cur0--;
            }
        }
    }
    cout << ans << el;
 
    return 0;
}