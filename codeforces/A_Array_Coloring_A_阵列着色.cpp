#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> co(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i % 2)
            co[a[i]] = 1;
        else
            co[a[i]] = 0;
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<n;i++){
        // cout<<
        if(co[a[i]]==co[a[i+1]]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}