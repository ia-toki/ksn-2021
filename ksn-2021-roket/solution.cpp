// O(N + Q log N)
// Use solution-expanded.cpp instead if you do not have AC library installed

#include <cstdio>
#include <vector>

#include <atcoder/segtree>

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

int eMin() { return 1000000000; }
int eMax() { return -1; }

using SegtreeMax = atcoder::segtree<int, max, eMax>;
using SegtreeMin = atcoder::segtree<int, min, eMin>;

int N;
std::vector<int> H;

SegtreeMax treeMax;
SegtreeMin treeInc;
SegtreeMax treeDec;

void init() {
  std::vector<int> inc(N), dec(N);
  for (int i = 0; i < N; ++i) {
    inc[i] = i - H[i];
    dec[i] = i + H[i];
  }

  treeMax = SegtreeMax(H);
  treeInc = SegtreeMin(inc);
  treeDec = SegtreeMax(dec);
}

long long query(int S, int T) {
  int L, R;
  if (S < T) L = S, R = T + 1;
  else L = T, R = S + 1;

  int maxH = treeMax.prod(L, R);
  return 4LL * (maxH - H[S])
       + 2LL * ((treeDec.prod(L, R) - maxH) - (treeInc.prod(L, R) + maxH))
       + 1LL * (maxH - H[T]);
}

void solve() {
  scanf("%d", &N);
  H.resize(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &H[i]);
  }

  init();

  int Q;
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
    int S, T;
    scanf("%d %d", &S, &T);
    printf("%lld\n", query(--S, --T));
  }
}

int main() {
  solve();
  return 0;
}
