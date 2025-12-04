#include <bits/stdc++.h>
using namespace std;

//权值线段树解决退化成链的版本
const int MAXN = 2e5 + 5;

int n, m;
int a[MAXN]; 
vector<int> adj[MAXN];

// int seq[MAXN];    
int dfn[MAXN];    
// val_pos 默认初始化为 0。
// 因为查询区间的 L 最小是 1，所以 val_pos[n]=0 永远会被判定为“不在区间内”
int val_pos[MAXN]; 

struct Node {
    int min_p; 
    int max_p; 
} tree[MAXN * 4];

void linearize_chain() {
    int start_node = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            start_node = i;
            break;
        }
    }
    // 特判 n=1 的情况
    if (n == 1) start_node = 1;

    int curr = start_node;
    int prev = 0;
    for (int i = 1; i <= n; i++) {
        // seq[i] = curr;
        dfn[curr] = i;
        val_pos[a[curr]] = i; 
        
        for (int next_node : adj[curr]) {
            if (next_node != prev) {
                prev = curr;
                curr = next_node;
                break;
            }
        }
    }
    // 关键点：val_pos[n] 依然是 0（全局变量默认值）
    // 这代表数值 n "并不在链上的任何有效位置"
}

// 这里的 r 上限会变成 n
void build(int node, int l, int r) {
    if (l == r) {
        tree[node].min_p = val_pos[l];
        tree[node].max_p = val_pos[l];
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    tree[node].min_p = min(tree[node * 2].min_p, tree[node * 2 + 1].min_p);
    tree[node].max_p = max(tree[node * 2].max_p, tree[node * 2 + 1].max_p);
}

int query_mex(int node, int l, int r, int query_l, int query_r) {
    if (l == r) {
        return l; 
    }
    
    int mid = (l + r) / 2;
    
    // 检查左子树 [l, mid] 范围内的数，位置是否都在查询区间 [query_l, query_r] 内
    int L_min = tree[node * 2].min_p;
    int L_max = tree[node * 2].max_p;
    
    // 如果 val_pos[k] 是 0，那么 0 >= query_l (最小为1) 一定为 false
    // 所以如果是数值 n，这里一定会判定为 false
    bool all_in_range = (L_min >= query_l && L_max <= query_r);
    
    if (all_in_range) {
        // 左边的数都齐了，去右边找
        return query_mex(node * 2 + 1, mid + 1, r, query_l, query_r);
    } else {
        // 左边有缺失（包括数值 n 的情况也会进这里，但那是右递归下来的事了），去左边找
        return query_mex(node * 2, l, mid, query_l, query_r);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    linearize_chain();
    
    // 【修改点 1】: 建树范围从 0 到 n
    build(1, 0, n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        int L = dfn[u];
        int R = dfn[v];
        if (L > R) swap(L, R);
        
        // 【修改点 2】: 查询范围从 0 到 n
        cout << query_mex(1, 0, n, L, R) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}