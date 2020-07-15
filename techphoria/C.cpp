#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define REP(i,a,b) for(int i = (int) a; i < (int) b; ++i)
#define fill(a,b) memset(a, (b), sizeof(a))
#define pii pair<int, int>
#define pll pair<long long, long long>

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cout.tie(NULL);

	int x,y;
	int n,fpb,total=0,maks=0,start;
	cin>>n;
	int a[n+1];
	int indeks;
	cin>>a[0]; maks=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		total += a[i];
		if(a[i]!=maks) {start=maks-a[i]; indeks=i;}
		maks = max(a[i],maks);
	}
	fpb=start;
	for(int i=1; i<n; i++){
		{fpb=__gcd(fpb,abs(start-(a[indeks]-a[i])));}
	}
	int sisa = a[1]%fpb;
	if(sisa==0) {x=maks;}
	else {x=maks-sisa+fpb;}
	y=(n*x-total)/fpb;
	cout<<y<<" "<<fpb;

	
}