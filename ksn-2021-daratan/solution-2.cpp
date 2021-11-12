#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1E5;

int n;
long long a[MAXN+10], b[MAXN+10];
long long ans[MAXN+10];

vector<int> adj[MAXN+10];
bool vis[MAXN+10];

long long dfs(int cur) {
  if (vis[cur]) return 0;
  vis[cur] = true;
  long long ret = b[cur];
  for (auto next:adj[cur]) {
    ret += dfs(next);
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
  
  for (int i = 0; i < n; i++) {
    memset(vis, false, sizeof vis);
    ans[i] = dfs(i);
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
