#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;

int n;
map<int,bool> mp;
vector<int> ve;
int kiri[MAXN+5], kanan[MAXN+5];
int BIT[MAXN+5];

int get(int x){
    int sum = 0;
    while(x > 0){
        sum += BIT[x];
        x -= x&-x;
    }
}

void upd(int x, int val){
    while(x <= n){
        BIT[x] += val;
        x += x&-x;
    }
}

void compress(){
    sort(ve.begin(),ve.end());
    for(int i=1; i<=n; i++){
        arr[i] = lower_bound(ve.begin(),ve.end(),arr[i]) - ve.begin() + 1;
    }
}

int main(){

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        if(mp.find(arr[i])==mp.end()){
            mp[arr[i]] = true;
            ve.insert(arr[i]);
        }
    }

    compress();

    for(int i=1; i<=n; i++){
        kiri[i] = get(arr[i]-1);
        upd(arr[i],1);
    }


}