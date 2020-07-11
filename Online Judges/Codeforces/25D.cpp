#include <bits/stdc++.h>

#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int N = 1005;

int par[N];
int size[N];
bool in[N];

int find(int x){
    return (x==par[x] ? x : par[x]=find(par[x]));
}

void uni(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y){
        if(size[x]<size[y]) swap(x,y);
        par[y] = x;
        size[x] += y;
    }
} 

int main(){

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        par[i] = i;
        size[i] = i;
    }

    int a,b;
    vector<pii> del;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        if(find(a)==find(b)){
            del.pb({a,b});
        } else {
            uni(a,b);
        }
    }

    vector<int> add;
    for(int i=1; i<=n; i++){
        int ii = find(i);
        if(!in[ii]){
            in[ii] = true;
            add.pb(ii);
        }
    }

    cout << del.size() << "\n";
    for(int i=0; i<(int)del.size(); i++){
        cout << del[i].ff << " " << del[i].ss << " ";
        cout << add[i] << " " << add[i+1] << "\n";
    }

}