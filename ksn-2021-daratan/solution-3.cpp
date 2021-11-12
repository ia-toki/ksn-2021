#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1E5;

int n;
long long a[MAXN+10], b[MAXN+10];
long long ans[MAXN+10];

vector<int> adj[MAXN+10];
int vis[MAXN+10];

long long dfs(int cur, long long val=-1) {
  if (vis[cur]) return 0;
  vis[cur] = true;
  if (val != -1) ans[cur] = val;
  
  long long ret = b[cur];
  for (auto next: adj[cur]) {
    ret += dfs(next, val);
  }
  return ret;
}

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((a[i]^a[j]) > max(a[i], a[j])) {
        adj[i].push_back(j);
      }
    }
  }
  
  memset(ans, -1, sizeof ans);
  memset(vis, false, sizeof vis);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) ans[i] = dfs(i);
  }
  
  memset(vis, false, sizeof vis);
  for (int i = 0; i < n; i++) {
    if (!vis[i] && ans[i] != -1) dfs(i, ans[i]);
  }
}

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
}

void output() {
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  input();
  solve();
  output();
  return 0;
}
