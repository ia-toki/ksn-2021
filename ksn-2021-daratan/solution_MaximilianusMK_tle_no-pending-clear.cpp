#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1E5;
const int MAXLOG = 30;
const int MAXA = (1<<MAXLOG)-1;

int n;
long long a[MAXN+10], b[MAXN+10];
long long ans[MAXN+10];

int parent[MAXN+10];
long long point[MAXN+10];

vector<int> group[MAXLOG+10];
vector<int> pending[MAXLOG+10];

//Start of Disjoint Set
int findRoot(int cur) {
  if (parent[cur] == cur) return cur;
  return parent[cur] = findRoot(parent[cur]);
}

bool combine(int u,int v) {
  int root_u = findRoot(u), root_v = findRoot(v);
  if (root_u == root_v) return false;
  point[root_u] += point[root_v];
  parent[root_v] = root_u;
  return true;
}

void reset() {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    point[i] = b[i];
  }
}
//End of Disjoint Set

int msb(int x) {
  int ret=-1;
  for (int i = 0; i < MAXLOG; i++) {
    if (x&(1<<i)) ret = i;
  }
  return ret;
}

void solve() {
  reset();
  for (int i = 0; i < n; i++) group[msb(a[i])].push_back(i);
  
  for (int cur_msb = MAXLOG-1; cur_msb >= 0; cur_msb--) {
    for (auto cur: group[cur_msb]) {
      
      if (!pending[cur_msb].empty()) {
        for (auto p: pending[cur_msb]) combine(cur, p);
      }
      
      for (int i = 0; i < cur_msb; i++) {
        if (a[cur]&(1<<i)) continue;
        pending[i].push_back(cur);
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    ans[i] = point[findRoot(i)];
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

