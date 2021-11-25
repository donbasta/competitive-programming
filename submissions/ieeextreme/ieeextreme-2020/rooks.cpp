#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
#define DEBUG false
using namespace std;

vector<pii> ans;
vector<char> ansc;
pii a[20],b[20];

void swapx(pii *a, pii *b) {
    ans.pb(mp((*a).fi,(*a).se));
    ansc.pb('T');
    ans.pb(mp((*b).fi,(*b).se));
    ansc.pb('L');
    (*b).fi--;
    ans.pb(mp((*b).fi,(*b).se));
    ansc.pb('L');
    (*b).fi--;
    ans.pb(mp((*a).fi,(*a).se));
    ansc.pb('P');
}

void swapy(pii *a, pii *b) {
    ans.pb(mp((*a).fi,(*a).se));
    ansc.pb('T');
    ans.pb(mp((*b).fi,(*b).se));
    ansc.pb('D');
    (*b).se--;
    ans.pb(mp((*b).fi,(*b).se));
    ansc.pb('D');
    (*b).se--;
    ans.pb(mp((*a).fi,(*a).se));
    ansc.pb('P');
}

bool stat(pii a, pii b) {
    return (b.se-a.se)*(b.fi-a.fi)<0;
}

void flip(pii *a){
    int tmp = (*a).fi;
    (*a).fi = (*a).se;
    (*a).se = tmp;
}

void move(pii *a, char dir){
	ans.pb(*a);
    ansc.pb(dir);
	if(dir == 'U') (*a).se++;
	else if(dir == 'D') (*a).se--;
	else if(dir == 'L') (*a).fi--;
	else if(dir == 'R') (*a).fi++;
}

void flipsort(pii a[], int n){
	for (int i=1;i<=n;i++) flip(&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) flip(&a[i]);
}

int main () {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i].fi >> a[i].se;
    for (int i=1;i<=n;i++) cin >> b[i].fi >> b[i].se;
    sort (a+1,a+n+1);
    sort (b+1,b+n+1);

    // swapx
    for (int j=1;j<=n;j++) {
        for (int i=1;i<n;i++) {
            if (stat(a[i],a[i+1])!=stat(b[i],b[i+1])) {
                int l=i,r=i+1;
                while (a[l].fi<a[r].fi-1) {
                	move(&a[l], 'R');
                }
                swapx(&a[l],&a[r]);
            }
            sort (a+1,a+n+1);
        }
    }
    
    if (DEBUG){
	    for (int i=1;i<=n;i++) cout << a[i].fi << " " << a[i].se << endl;
	    cout << endl;
	    for (int i=1;i<=n;i++) cout << b[i].fi << " " << b[i].se << endl;
	    cout << endl;
	}

    flipsort(a, n);
    flipsort(b, n);

    for (int j=1;j<=n;j++) {
        for (int i=1;i<n;i++) {
            if (stat(a[i],a[i+1])!=stat(b[i],b[i+1])) {
                int l=i,r=i+1;
                while (a[l].se<a[r].se-1) {
                    move(&a[l], 'U');
                }
                swapy(&a[l],&a[r]);
            }
            flipsort(a, n);
        }
    }

    sort (a+1,a+n+1);
    sort (b+1,b+n+1);
    
    // move to target
    for (int i=n;i>=1;i--) {
        while (a[i].fi>b[i].fi) {
        	move(&a[i], 'L');
        }
        while (a[i].fi<b[i].fi) {
        	move(&a[i], 'R');
        }
        while (a[i].se>b[i].se) {
        	move(&a[i], 'D');
        }
        while (a[i].se<b[i].se) {
        	move(&a[i], 'U');
        }
    }

    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++) {
        cout << ans[i].fi << " " << ans[i].se << " " << ansc[i] << endl;
    }
	if (DEBUG){
	    for (int i=1;i<=n;i++) cout << a[i].fi << " " << a[i].se << endl;
	}

    return 0;
}