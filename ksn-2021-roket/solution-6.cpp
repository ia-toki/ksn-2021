// O(N + Q)

#include <cstdio>
#include <vector>

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

int N;
std::vector<int> H;

std::vector<long long> ans;

void init() {
  ans.resize(N);

  int maxH = H[0], maxPosL = -H[0], maxPosR = H[0];
  for (int i = 1; i < N; ++i) {
    maxH = max(maxH, H[i]);
    maxPosL = min(maxPosL, i - H[i]);
    maxPosR = max(maxPosR, i + H[i]);

    ans[i] = 4LL * (maxH - H[0])
           + 2LL * ((maxPosR - maxH) - (maxPosL + maxH))
           + 1LL * (maxH - H[i]);
  }
}

long long query(int S, int T) {
  return ans[T];
}

void solve() {
  scanf("%d", &N);
  H.resize(N);
  for (int i = 0; i < N; ++i) scanf("%d", &H[i]);

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
