// O(Q (N MAXH)log(N MAXH))

#include <cstdio>
#include <vector>
#include <queue>

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

int N;
std::vector<int> H;

int encode(int i, int h) { return (h - 1) * N + i; }
int decodeI(int e) { return e % N; };
int decodeH(int e) { return e / N + 1; };
int cost(int h, int nh) { return h < nh ? 4 : h > nh ? 1 : 2; }

int maxH;
void init() {
  maxH = 0;
  for (int i = 0; i < N; ++i) {
    maxH = max(maxH, H[i]);
  }
}

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
long long query(int S, int T) {
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>
                      > pq;

  std::vector<int> dist(maxH * N, -1);
  pq.emplace(0, encode(S, H[S]));
  dist[encode(S, H[S])] = 0;

  while (!pq.empty()) {
    int enc = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    if (dist[enc] != d) continue;

    int i = decodeI(enc), h = decodeH(enc);
    for (int k = 0; k < 8; ++k) {
      int ni = i + dx[k], nh = h + dy[k];
      if (ni < 0 || ni >= N || nh < H[ni] || nh > maxH) continue;

      int nd = d + cost(h, nh);
      int nenc = encode(ni, nh);
      if (dist[nenc] == -1 || nd < dist[nenc]) {
        dist[nenc] = nd;
        pq.emplace(nd, nenc);
      }
    }
  }

  return dist[encode(T, H[T])];
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
