// O(NM 2^N)

#include <cstdio>

void solve() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  char S[N + 5];
  scanf("%s", S);

  int ans = 0;
  for (int mask = 0; mask < 1 << N; ++mask) {
    bool good = true;
    for (int i = 0; i < N; ++i) {
      if (S[i] == 'A' && (mask >> i & 1) == 1) good = false;
      if (S[i] == 'B' && (mask >> i & 1) == 0) good = false;
    }
    if (!good) continue;

    int k = 0;
    for (int i = M - 1; i < N; ++i) {
      bool okay = true;
      for (int j = 1; j < M; ++j) {
        if ((mask >> (i - j) & 1) != (mask >> i & 1)) okay = false;
      }
      if (okay) ++k;
    }

    if (k == K) {
      ++ans;
    }
  }
  printf("%d\n", ans);
}

int main() {
  solve();
  return 0;
}
