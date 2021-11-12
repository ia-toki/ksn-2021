#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1E5;
const int MAXLOG = 20;
const int MAXA = (1<<MAXLOG)-1;

int n;
long long a[MAXN+10], b[MAXN+10];
long long ans[MAXN+10];

int parent[MAXN+10];
long long point[MAXN+10];

vector<int> group[MAXA+10];
bool compressed[MAXA+10];

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

void compress(int idx) {
  if (compressed[idx]) return;
  for (auto i: group[idx]) combine(group[idx][0], i);
  compressed[idx] = true;
}

void solve() {
  reset();
  long long maks = 0;
  for (int i = 0; i < n; i++) {
    group[a[i]].push_back(i);
    maks = max(maks, a[i]);
  }
  memset(compressed, false, sizeof compressed);
  
  for (int i = 1; i <= maks; i++) {
    if (group[i].empty()) continue;
    for (int j = 1; j <= maks; j++) {
      if (group[j].empty()) continue;
      if ((i^j) > max(i,j)) {
        compress(i);
        compress(j);
        combine(group[i][0], group[j][0]);
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

