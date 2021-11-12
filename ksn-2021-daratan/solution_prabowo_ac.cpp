#include <cstdio>
#include <vector>

const int kLog = 30;

class DSU {
  std::vector<int> par;
 public:
  DSU(int n) {
    par.resize(n);
    for (int i = 0; i < n; ++i) {
      par[i] = i;
    }
  }

  int root(int u) {
    if (u == par[u]) return u;
    return par[u] = root(par[u]);
  }

  void merge(int u, int v) {
    if (root(u) == root(v)) return;
    par[par[v]] = par[u];
  }
};

void solve() {
  int N;
  scanf("%d", &N);
  std::vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
  for (int i = 0; i < N; ++i) scanf("%d", &B[i]);

  std::vector<int> msb(N);
  std::vector<std::vector<int>> msbPos(kLog);
  for (int i = 0; i < N; ++i) {
    msb[i] = 31 - __builtin_clz(A[i]);
    msbPos[msb[i]].push_back(i);
  }

  DSU dsu(N + kLog);
  std::vector<bool> connected(kLog);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < msb[i]; ++j) {
      if (A[i] >> j & 1) continue;
      if (msbPos[j].empty()) continue;

      if (!connected[j]) {
        connected[j] = true;
        for (int pos : msbPos[j]) dsu.merge(N + j, pos);
      }
      dsu.merge(i, N + j);
    }
  }

  std::vector<long long> sum(N + kLog);
  for (int i = 0; i < N; ++i) {
    sum[dsu.root(i)] += B[i];
  }
  for (int i = 0; i < N; ++i) {
    printf("%lld", sum[dsu.root(i)]);
    if (i == N - 1) printf("\n");
    else printf(" ");
  }
}

int main() {
  solve();
  return 0;
}
