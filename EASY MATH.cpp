#include <bits/stdc++.h>
/* #define int long long int */
typedef long long int ll;
using namespace std;
const int M = 1e9+7;

ll power(ll a, ll b, ll m) {
	ll ans = 1;
	while(b>0) {
		ans*=a;
		b--;
	}
	return ans;
}

ll gcd(ll a, ll b) {
	if(a%b==0) return b;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return (a*b)/gcd(a,b);
}

void solve() {
	ll n, m, a, d; cin >> n >> m >> a >> d;
	vector<ll> v = {a, a+d, a+2*d, a+3*d, a+4*d};
	ll ans = 0;
	for(ll i=1; i<(1<<5); ++i) {
		ll current = 1, cnt = 0;
		for(ll mask = 1, j=0; j<5; ++j) {
			if((mask<<j)&i) {
				++cnt;
				current = lcm(v[j],current);
			}
		}
		ll temp = m/current - (n/current + (n%current?1:0))+1;
		if(cnt&1)
			ans += temp;
		else 
			ans -= temp;
		/* cout << ans << '\n'; */
	}
	cout << m-n+1-ans << '\n';
}

int32_t main () {
	/* DO NOT USE IN UVA */
     /* ios_base::sync_with_stdio(0);cin.tie(0); */

     // #ifndef ONLINE_JUDGE
     // freopen("vs_input.txt", "r", stdin);
     // freopen("vs_output.txt", "w", stdout);
     // #endif

    int t=1 ; 
    cin >> t;
    for(int i=1; i<=t; ++i){
        /* cout << "Case #" << i << ": "; */
        solve();
    }
}
