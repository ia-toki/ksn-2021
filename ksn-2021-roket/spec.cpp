#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int kMaxN = 200000;
const int kMaxH = 1000000000;
const int kMaxQ = 200000;

const int kCubeN = 100;
const int kCubeQ = 100;
const int kCubeH = 100;

const int kQuadN = 1000;
const int kQuadQ = 1000;

class ProblemSpec : public BaseProblemSpec {
 protected:
  int N;
  vector<int> H;
  int Q;
  vector<int> S, T;

  vector<long long> ANS;

  void InputFormat() {
    LINE(N);
    LINE(H % SIZE(N));
    LINE(Q);
    LINES(S, T) % SIZE(Q);
  }

  void OutputFormat() {
    LINES(ANS) % SIZE(Q);
  }

  void Constraints() {
    CONS(2 <= N && N <= kMaxN);
    CONS(eachElementBetween(H, 1, kMaxH));
    CONS(1 <= Q && Q <= kMaxQ);
    CONS(eachElementBetween(S, 1, N));
    CONS(eachElementBetween(T, 1, N));
    CONS(eachDifferent(S, T));
  }

  void Subtask1() {
    Points(7);
    CONS(N == 8);
    CONS(H == vector<int>({1, 9, 3, 3, 5, 4, 8, 2}));
    CONS(Q == 4);
    CONS(S == vector<int>({1, 3, 6, 7}));
    CONS(T == vector<int>({8, 6, 4, 2}));
  }

  void Subtask2() {
    Points(5);
    CONS([&]() { 
      for (int i = 0; i < Q; ++i) if (S[i] + 1 != T[i]) return false;
      return true;
    }());
  }

  void Subtask3() {
    Points(6);
    CONS([&]() { 
      for (int i = 0; i < N; ++i) if (H[i] != i + 1) return false;
      return true;
    }());
  }

  void Subtask4() {
    Points(18);
    CONS(N <= kCubeN);
    CONS(Q <= kCubeQ);
    CONS(eachElementBetween(H, 1, kCubeH));
  }

  void Subtask5() {
    Points(24);
    CONS(N <= kQuadN);
    CONS(Q <= kQuadQ);
  }

  void Subtask6() {
    Points(13);
    CONS(all_of(S.begin(), S.end(), [](int s) { return s == 1; }));
  }

  void Subtask7() {
    Points(27);
  }

  bool eachElementBetween(const vector<int> &A, int lo, int hi) {
    return all_of(A.begin(), A.end(), [&](int a) { return lo <= a && a <= hi; });
  }

  bool eachDifferent(const vector<int> &S, const vector<int> &T) {
    for (int i = 0; i < static_cast<int>(S.size()); ++i) {
      if (S[i] == T[i]) return false;
    }
    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
  void SampleTestCase1() {
    Subtasks({4, 5, 7});
    Input({
      "4",
      "9 1 8 2",
      "2",
      "1 3",
      "4 2",
    });
    Output({
      "3",
      "31",
    });
  }

  void SampleTestCase2() {
    Subtasks({4, 5, 7});
    Input({
      "9",
      "1 2 3 2 1 2 3 2 1",
      "4",
      "1 9",
      "4 6",
      "2 6",
      "5 2",
    });
    Output({
      "18",
      "4",
      "9",
      "9",
    });
  }

  void BeforeTestCase() {
    H.clear();
    S.clear(); T.clear();
  }

  void AfterTestCase() {
    inc(S); inc(T);
  }

  void TestGroup1() {
    Subtasks({1, 4, 5, 7});
    CASE(N = 8; Q = 4;
         H = {1, 9, 3, 3, 5, 4, 8, 2};
         S = {0, 2, 5, 6}; T = {7, 5, 3, 1});
  }

  // S + 1 = T
  void TestGroup2() {
    Subtasks({2, 7});

    CASE(N = kMaxN; Q = kMaxQ;
         H = randomH(N);
         S = randomH(Q, N - 1); T = S; dec(S); );
    CASE(N = kMaxN; Q = N - 1;
         H = randomH(N);
         S = vector<int>(Q); iota(S.begin(), S.end(), 0); T = S; inc(T); );
  }

  // Hi = i
  void TestGroup3() {
    Subtasks({3, 7});

    CASE(N = kMaxN; Q = kMaxQ;
         H = vector<int>(N); iota(H.begin(), H.end(), 1);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kMaxN; Q = kMaxQ;
         H = vector<int>(N); iota(H.begin(), H.end(), 1);
         tie(S, T) = largeQ(N, Q));
  }

  // N, Q ≤ kCubeN, H ≤ kCubeN
  void TestGroup4() {
    Subtasks({4, 5, 7});
    CASE(N = rnd.nextInt(1, kCubeN); Q = kCubeQ;
         H = randomH(N, kCubeH);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kCubeN; Q = kCubeQ;
         H = randomH(N, kCubeH);
         tie(S, T) = largeQ(N, Q));
    CASE(N = kCubeN / 2; Q = kCubeQ;
         H = noiseLinear(N);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kCubeN / 2; Q = kCubeQ;
         H = noiseLinear(N);
         tie(S, T) = largeQ(N, Q));
    CASE(N = kCubeN / 2; Q = kCubeQ;
         H = noiseLinear(N); reverse(H.begin(), H.end());
         tie(S, T) = randomQ(N, Q));
    CASE(N = kCubeN; Q = kCubeQ;
         H = zigzag(N, kCubeH);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kCubeN; Q = kCubeQ;
         H = vector<int>(N, kCubeH);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kCubeN; Q = kCubeQ;
         H = vector<int>(N, 1);
         tie(S, T) = randomQ(N, Q));
  }

  // N, Q ≤ kQuadN
  void TestGroup5() {
    Subtasks({5, 7});

    CASE(N = kQuadN - 1; Q = kQuadQ - 1;
         H = randomH(N);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kQuadN; Q = kQuadQ;
         H = randomH(N);
         tie(S, T) = largeQ(N, Q));
    CASE(N = kQuadN; Q = kQuadQ;
         H = noiseLinear(N);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kQuadN; Q = kQuadQ;
         H = noiseLinear(N);
         tie(S, T) = largeQ(N, Q));
    CASE(N = kQuadN; Q = kQuadQ;
         H = noiseLinear(N); reverse(H.begin(), H.end());
         tie(S, T) = randomQ(N, Q));
    CASE(N = kQuadN; Q = kQuadQ;
         H = zigzag(N);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kQuadN; Q = kQuadQ;
         H = vector<int>(N, kMaxH);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kQuadN; Q = kQuadQ;
         H = vector<int>(N, 1);
         tie(S, T) = randomQ(N, Q));
  }

  // S = 1
  void TestGroup6() {
    Subtasks({6, 7});

    CASE(N = kMaxN; Q = kMaxQ;
         H = randomH(N);
         S = vector<int>(Q); T = randomH(Q, N - 1));
    CASE(N = kMaxN; Q = N - 1;
         H = randomH(N);
         S = vector<int>(Q); T = S; iota(T.begin(), T.end(), 1));
    CASE(N = kMaxN; Q = N - 1;
         H = noiseLinear(N);
         S = vector<int>(Q); T = S; iota(T.begin(), T.end(), 1));
    CASE(N = kMaxN; Q = N - 1;
         H = vector<int>(N, kMaxH);
         S = vector<int>(Q); T = S; iota(T.begin(), T.end(), 1));
    CASE(N = kMaxN; Q = N - 1;
         H = vector<int>(N, 1);
         S = vector<int>(Q); T = S; iota(T.begin(), T.end(), 1));
  }

  // Full
  void TestGroup7() {
    Subtasks({7});

    CASE(N = kMaxN - 1; Q = kMaxQ - 1;
         H = randomH(N);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kMaxN; Q = kMaxQ;
         H = randomH(N);
         tie(S, T) = largeQ(N, Q));
    CASE(N = kMaxN; Q = kMaxQ;
         H = noiseLinear(N);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kMaxN; Q = kMaxQ;
         H = noiseLinear(N);
         tie(S, T) = largeQ(N, Q));
    CASE(N = kMaxN; Q = kMaxQ;
         H = noiseLinear(N); reverse(H.begin(), H.end());
         tie(S, T) = randomQ(N, Q));
    CASE(N = kMaxN; Q = kMaxQ;
         H = zigzag(N);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kMaxN; Q = kMaxQ;
         H = vector<int>(N, kMaxH);
         tie(S, T) = randomQ(N, Q));
    CASE(N = kMaxN; Q = kMaxQ;
         H = vector<int>(N, 1);
         tie(S, T) = randomQ(N, Q));
  }

  vector<int> randomH(int n, int maxH=kMaxH) {
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) ret[i] = rnd.nextInt(1, maxH);
    return ret;
  }

  vector<int> noiseLinear(int n) {
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) ret[i] = i + 1 + rnd.nextInt(-i, i);
    return ret;
  }

  vector<int> zigzag(int n, int maxH=kMaxH) {
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) ret[i] = (i & 1 ? maxH : 1);
    return ret;
  }

  pair<vector<int>, vector<int>> randomQ(int n, int q) {
    vector<int> s(q), t(q);
    for (int i = 0; i < q; ++i) {
      do {
        s[i] = rnd.nextInt(n);
        t[i] = rnd.nextInt(n);
      } while (s[i] == t[i]);
    }
    return {s, t};
  }

  pair<vector<int>, vector<int>> largeQ(int n, int q, int margin=-1) {
    vector<int> s(q), t(q);
    if (margin == -1) margin = sqrt(q);
    for (int i = 0; i < q; ++i) {
      s[i] = rnd.nextInt(margin);
      t[i] = n - rnd.nextInt(margin) - 1;
    }
    return {s, t};
  }

  void inc(vector<int> &v) { for (int &x : v) ++x; }
  void dec(vector<int> &v) { for (int &x : v) --x; }
};
