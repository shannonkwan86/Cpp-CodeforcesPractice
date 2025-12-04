#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//dfs解决小数据范围版本
const int MX = 2e5 + 5;
int n, m;
int a[MX];
vector<vector<int>> g;
set<int> path_values;

bool build_path(int u, int target, int parent, vector<int> &path)
{
    path.push_back(u);
    if (u == target)
    {
        return true;
    }
    for (int v : g[u])
    {
        if (v == parent)
            continue;
        if (build_path(v, target, u, path))
        {
            return true;
        }
    }
    path.pop_back();
    return false;
}

void dfs(int x,int y){
    vector<int> path;
    path_values.clear();
    if (build_path(x, y, 0, path))
    {
        for (int node : path)
        {
            path_values.insert(a[node]);
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    g.assign(n + 1, {});
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    while (m--)
    {
        int x,y;
        cin>>x>>y;
        dfs(x,y);
        int mex = 0;
        while (path_values.count(mex))
        {
            mex++;
        }
        cout << mex << '\n';
    }
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