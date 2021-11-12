#include <cstdio>

int main() {
  int Q, K;
  scanf("%d %d", &Q, &K);
  while (Q--) {
    int C;
    scanf("%d", &C);
    if ((C | K) == C) printf("%d\n", C);
    else printf("-1\n");
  }
  return 0;
}
