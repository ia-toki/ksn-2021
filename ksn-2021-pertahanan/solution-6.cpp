// O(NM)

#include <cstdio>
#include <vector>

const int kMod = 1000000007;

void solve() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  char S[N + 5];
  scanf("%s", S + 1);
  S[0] = S[N + 1] = 0;

  std::vector<int> dpL0(N + 1), dpL1(N + 1);
  dpL0[0] = dpL1[0] = 1;

  for (int i = 1; i <= N; ++i) {
    bool okay0 = (S[i] != 'B'), okay1 = (S[i] != 'A');
    for (int j = 1; j < M; ++j) {
      if (i - j < 0) break;
      if (okay0) dpL0[i] = (dpL0[i] + dpL1[i - j]) % kMod;
      if (okay1) dpL1[i] = (dpL1[i] + dpL0[i - j]) % kMod;
      if (S[i - j] == 'B') okay0 = false;
      if (S[i - j] == 'A') okay1 = false;
    }
  }

  std::vector<int> dpR0(N + 2), dpR1(N + 2);
  dpR0[N + 1] = dpR1[N + 1] = 1;

  for (int i = N; i > 0; --i) {
    bool okay0 = (S[i] != 'B'), okay1 = (S[i] != 'A');
    for (int j = 1; j < M; ++j) {
      if (i + j > N + 1) break;
      if (okay0) dpR0[i] = (dpR0[i] + dpR1[i + j]) % kMod;
      if (okay1) dpR1[i] = (dpR1[i] + dpR0[i + j]) % kMod;
      if (S[i + j] == 'B') okay0 = false;
      if (S[i + j] == 'A') okay1 = false;
    }
  }

  int ans = 0;
  if (K >= 1) for (int i = M; i <= N; ++i) {
    bool okay0 = true, okay1 = true;
    for (int j = 0; j < M; ++j) {
      if (S[i - j] == 'B') okay0 = false;
      if (S[i - j] == 'A') okay1 = false;
    }

    if (okay0) ans = (ans + 1LL * dpL1[i - M] * dpR1[i + 1]) % kMod;
    if (okay1) ans = (ans + 1LL * dpL0[i - M] * dpR0[i + 1]) % kMod;
  } else {
    ans = (dpL0[N] + dpL1[N]) % kMod;
  }
  printf("%d\n", ans);
}

int main() {
  solve();
  return 0;
}
