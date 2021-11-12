// O(N + Q)

#include <cstdio>
#include <vector>

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

int N;
std::vector<int> H;

long long query(int S, int T) {
  if (H[S] < H[T]) return 4LL * (H[T] - H[S]);
  if (H[S] > H[T]) return 1LL * (H[S] - H[T]);
  return 2LL;
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
