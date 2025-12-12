#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
const int mod=998244353;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<tuple<ll,int,int>>g(m+1);
    vector<map<int,int>>dp(n+1);
    for(int i=1;i<=m;i++){
        int v,u;
        cin>>v>>u;
        g[i]={a[v],v,u};
        dp[u][a[v]]++;
    }   
    sort(g.begin()+1,g.end());
    for(int i=1;i<=m;i++){
        auto [x,y,z]=g[i];
        for(auto [last,res]:dp[y]){
            if(last+a[y]==a[z]){
                dp[z][x]=(dp[z][x]+res)%mod;
            }
        }
    }   
    int ans=0;
    for(int i=1;i<=n;i++){
        for(auto [last,res]:dp[i]){
            ans=(ans+res)%mod;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}