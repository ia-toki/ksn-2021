// O(N)

#include <cstdio>

void solve() {
  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  char S[N + 5];
  scanf("%s", S);

  bool okay1 = true, okay2 = true;
  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      if (S[i] == 'A') okay1 = false;
      if (S[i] == 'B') okay2 = false;
    } else {
      if (S[i] == 'B') okay1 = false;
      if (S[i] == 'A') okay2 = false;
    }
  }

  int ans = 0;
  if (okay1) ++ans;
  if (okay2) ++ans;
  printf("%d\n", ans);
}

int main() {
  solve();
  return 0;
}
