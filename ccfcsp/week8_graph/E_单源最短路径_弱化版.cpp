#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//就是说从源节点开始
//如果距离被更新变小，就把这个点放进队列
//然后邻接表找这个点所有相邻的点进行更新，类似bfs进行层序的一种更新
int n, m, s;
vector<pair<int, int>> g[11111];
queue<int> q;
bool vis[11111];
int dis[11111];
void bfs()
{

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
        vis[i] = false;
    }
    vis[s] = true;
    dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int tp = q.front();
        // cout << tp << endl;
        q.pop();
        vis[tp] = false;
        for (int i = 0; i < g[tp].size(); i++)
        {
            // cout << g[tp][i].second + dis[tp] << " " << dis[g[tp][i].first] << endl;
            if (g[tp][i].second + dis[tp] < dis[g[tp][i].first])
            {
                dis[g[tp][i].first] = g[tp][i].second + dis[tp];
                // cout<<dis[g[tp][i].first]<<endl;
                if (vis[g[tp][i].first])
                {
                    continue;
                }
                q.push(g[tp][i].first);
                vis[g[tp][i].first] = true;
            }
        }
            // cout<<endl;

    }
}

void solve()
{
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    bfs();
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == INT_MAX)
            cout << (1 << 31) - 1 << " ";
        else
        {
            cout << dis[i] << " ";
        }
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