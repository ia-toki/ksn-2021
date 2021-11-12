// O(QN)

#include <cstdio>
#include <vector>

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

int N;
std::vector<int> H;

long long query(int S, int T) {
  int L, R;
  if (S < T) L = S, R = T;
  else L = T, R = S;

  int maxH = -1;
  for (int i = L; i <= R; ++i) maxH = max(maxH, H[i]);
  
  int maxPosL = N, maxPosR = -1;
  for (int i = L; i <= R; ++i) {
    maxPosL = min(maxPosL, i + (maxH - H[i]));
    maxPosR = max(maxPosR, i - (maxH - H[i]));
  }

  return 4LL * (maxH - H[S]) + 2LL * (maxPosR - maxPosL) + 1LL * (maxH - H[T]);
}

void solve() {
  scanf("%d", &N);
  H.resize(N);
  for (int i = 0; i < N; ++i) scanf("%d", &H[i]);

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
