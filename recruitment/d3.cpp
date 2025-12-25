#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> dp(n+2,vector<int>(n + 2));
    for(int len=1;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            int y=n-len+1;
            dp[i][j]=max(dp[i+1][j]+y*a[i],dp[i][j-1]+y*a[j]);
        }
    }
    cout<<dp[1][n]<<endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}