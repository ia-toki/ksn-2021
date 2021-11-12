#include <bits/stdc++.h>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define L(n) (n << 1)
#define R(n) (n << 1 | 1)
#define print_vector(n) for(auto a0 : n) cout << a0 << ' '; cout << endl;
#define vector_sort(n) sort(n.begin(), n.end())
#define print_array(n, l, r) for(int a0 = l; a0 <= r; a0++) cout << n[a0] << ' '; cout << '\n';
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
#define ABS(a) ((a) > 0 ? (a) : -(a))
using namespace std;

template<class T>
istream & operator >> (istream &in, pair<T, T> &p) {
  in >> p.first >> p.second;
  return in;
}

template<class T>
ostream & operator <<(ostream &out, pair<T, T> &p) {
  out << p.first << ' ' << p.second;
  return out;
}

template<class Tuple, std::size_t N>
struct TuplePrinter {
  static void print(ostream &out, const Tuple& t) {
    TuplePrinter<Tuple, N-1>::print(out, t);
    out << ' ' << get<N-1>(t);
  }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1> {
  static void print(ostream &out, const Tuple& t) {
    out << get<0>(t);
  }
};

template<class... Args>
ostream & operator <<(ostream &out, const tuple<Args...> &p) {
  TuplePrinter<decltype(p), sizeof...(Args)>::print(out, p);
  return out;
}

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int N;
int A[MAXN];
long long memo[5][MAXN];
int nextSmaller[MAXN];

void findNextSmaller() {
  A[0] = N + 1;
  vector<pii> stac;
  nextSmaller[N] = N + 1;
  stac.emplace_back(A[N], N);
  for (int i = N - 1; i >= 1; i--) {
    while (!stac.empty() && stac.back().first >= A[i]) {
      stac.pop_back();
    }
    nextSmaller[i] = (stac.empty() ? N + 1 : stac.back().second);
    stac.emplace_back(A[i], i);
  }
}

long long dp(int type, int idx) {
  if (memo[type][idx] != -1) return memo[type][idx];
  long long res = 0;
  if (type == 0) {
    for (int j = idx; j <= N; j++) {
      res += dp(1, j);
    }
  }else {
    res += (nextSmaller[idx] == N + 1);
    int smallest = A[idx + 1];
    for (int j = idx + 2; j <= N; j++) {
      if (A[j] <= smallest || A[idx] <= smallest) {
        res += dp(0, j);
      }
      smallest = min(smallest, A[j]);
    }
  }
  return memo[type][idx] = res % MOD;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  findNextSmaller();
  memset(memo, -1, sizeof(memo));
  cout << dp(0, 0) << "\n"; 
}
