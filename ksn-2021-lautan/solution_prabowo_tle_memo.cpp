#include <bits/stdc++.h>

std::map<std::tuple<int, int, int, int>, int> memo;
int countCc(int A, int B, int C, int D) {
  std::tuple<int, int, int, int> t = std::make_tuple(A, B, C, D);
  if (memo.find(t) != memo.end()) return memo[t];

  std::vector<std::vector<bool>> vis(C - A + 1, std::vector<bool>(D - B + 1, false));
  auto bfs = [&](int x, int y) {
    std::queue<std::pair<int, int>> q;
    q.emplace(x, y);
    vis[x - A][y - B] = true;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    while (!q.empty()) {
      int x, y;
      std::tie(x, y) = q.front();
      q.pop();

      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < A || nx > C || ny < B || ny > D) continue;
        if (vis[nx - A][ny - B]) continue;  
        if ((nx & ny) != 0) continue;
        
        vis[nx - A][ny - B] = true;
        q.emplace(nx, ny);
      }
    }
  };

  int cc = 0;
  for (int i = A; i <= C; ++i) {
    for (int j = B; j <= D; ++j) {
      if (vis[i - A][j - B]) continue;
      if ((i & j) != 0) continue;
      bfs(i, j);
      ++cc;
    }
  }
  return memo[t] = cc;
}

void solve() {
  int N, M, Q;
  scanf("%d %d %d", &N, &M, &Q);
  for (int i = 0; i < Q; ++i) {
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("%d\n", countCc(A, B, C, D));
  }
}

int main() {
  solve();
  return 0;
}
