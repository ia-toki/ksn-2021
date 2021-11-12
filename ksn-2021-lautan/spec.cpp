#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int kMaxN = 1e9;
const int kMaxQ = 100000;
const int kQuadN = 2000;
const int kCubeN = 200;

class ProblemSpec : public BaseProblemSpec {
 protected:
  int N, M, Q;
  vector<int> A, B, C, D;

  vector<int> ANS;

  void InputFormat() {
    LINE(N, M, Q);
    LINES(A, B, C, D) % SIZE(Q);
  }

  void OutputFormat() {
    LINES(ANS) % SIZE(Q);
  }

  void Constraints() {
    CONS(1 <= N && N <= kMaxN);
    CONS(1 <= M && M <= kMaxN);
    CONS(1 <= Q && Q <= kMaxQ);
    CONS(inRange(0, A, C, N - 1));
    CONS(inRange(0, B, D, M - 1));
  }

  void Subtask1() {
    Points(5);
    CONS(N == 12); CONS(M == 12); CONS(Q == 3);
    CONS(A == vector<int>({1, 8, 4}));
    CONS(B == vector<int>({1, 8, 3}));
    CONS(C == vector<int>({9, 11, 5}));
    CONS(D == vector<int>({8, 11, 9}));
  }

  void Subtask2() {
    Points(11);
    CONS(N <= kCubeN);
    CONS(M <= kCubeN);
    CONS(Q <= kCubeN);
  }

  void Subtask3() {
    Points(10);
    CONS(N <= kQuadN);
    CONS(M <= kQuadN);
    CONS(Q <= kQuadN);
    CONS(A == C);
  }

  void Subtask4() {
    Points(20);
    CONS(N <= kQuadN);
    CONS(M <= kQuadN);
    CONS(Q <= kQuadN);
  }

  void Subtask5() {
    Points(4);
    CONS(A == vector<int>(Q, 0));
    CONS(B == vector<int>(Q, 0));
  }

  void Subtask6() {
    Points(6);
    CONS(A == C);
    CONS(all_of(A.begin(), A.end(), [](int x) { return x == (x & -x); }));
  }

  void Subtask7() {
    Points(29);
    CONS(A == C);
  }

  void Subtask8() {
    Points(15);
  }

  bool inRange(int lo, vector<int> A, vector<int> B, int hi) {
    for (int i = 0; i < static_cast<int>(A.size()); ++i) {
      if (!(lo <= A[i] && A[i] <= B[i] && B[i] <= hi)) return false;
    }
    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
  void SampleTestCase1() {
    Subtasks({2, 4, 8});
    Input({
      "6 5 4",
      "0 0 3 2",
      "0 2 1 3",
      "0 1 2 4",
      "5 4 5 4",
    });
    Output({
      "1",
      "1",
      "2",
      "0",
    });
  }

  void BeforeTestCase() {
    A.clear(); B.clear(); C.clear(); D.clear();
  }

  void AfterTestCase() {
    Q = static_cast<int>(A.size());
  }

  void TestGroup1() {
    Subtasks({1, 2, 4, 8});
    CASE(N = 12; M = 12; Q = 3;
         A = {1, 8, 4}; B = {1, 8, 3}; C = {9, 11, 5}; D = {8, 11, 9});
  }

  // N, M, Q ≤ 200; A = C
  void TestGroup2() {
    Subtasks({2, 3, 4, 7, 8});

    CASE(N = kCubeN; M = kCubeN; randomACQueries(N, M, kCubeN));
    CASE(N = kCubeN; M = kCubeN; largeACQueries(N, M, kCubeN));
    CASE(N = kCubeN; M = kCubeN; customACQueries(N, M));
  }

  // N, M, Q ≤ 200
  void TestGroup3() {
    Subtasks({2, 4, 8});
 
    CASE(N = kCubeN; M = kCubeN; randomQueries(N, M, kCubeN));
    CASE(N = kCubeN; M = kCubeN; maxQueries(N, M, kCubeN - 1); addQuery(1, 1, N - 1, M - 1));
    CASE(N = kCubeN; M = kCubeN; largeQueries(N, M, kCubeN));
    CASE(N = kCubeN; M = kCubeN; customQueries(N, M));
    CASE(N = rnd.nextInt(1, kCubeN/2); M = rnd.nextInt(kCubeN/2 + 1, kCubeN); randomQueries(N, M, kCubeN));
    CASE(N = rnd.nextInt(kCubeN/2 + 1, kCubeN); M = rnd.nextInt(1, kCubeN/2); randomQueries(N, M, kCubeN));
  }

  // N, M, Q ≤ 2000; A = C
  void TestGroup4() {
    Subtasks({3, 4, 7, 8});

    CASE(N = kQuadN; M = kQuadN; randomACQueries(N, M, kQuadN));
    CASE(N = kQuadN; M = kQuadN; largeACQueries(N, M, kQuadN));
    CASE(N = kQuadN; M = kQuadN; randomACQueries(N, M, kQuadN - 100); customACQueries(N, M));
    CASE(N = rnd.nextInt(1, kQuadN/2); M = rnd.nextInt(kQuadN/2 + 1, kQuadN); randomACQueries(N, M, kQuadN));
    CASE(N = rnd.nextInt(kQuadN/2 + 1, kQuadN); M = rnd.nextInt(1, kQuadN/2); randomACQueries(N, M, kQuadN));
  }

  // N, M, Q ≤ 2000
  void TestGroup5() {
    Subtasks({4, 8});

    CASE(N = kQuadN; M = kQuadN; randomQueries(N, M, kQuadN));
    CASE(N = kQuadN; M = kQuadN; maxQueries(N, M, kQuadN - 1); addQuery(1, 1, N - 1, M - 1));
    CASE(N = kQuadN; M = kQuadN; largeQueries(N, M, kQuadN));
    CASE(N = kQuadN; M = kQuadN; randomQueries(N, M, kQuadN - 100); customQueries(N, M));
    CASE(N = rnd.nextInt(1, kQuadN/2); M = rnd.nextInt(kQuadN/2 + 1, kQuadN); randomQueries(N, M, kQuadN));
    CASE(N = rnd.nextInt(kQuadN/2 + 1, kQuadN); M = rnd.nextInt(1, kQuadN/2); randomQueries(N, M, kQuadN));
  }

  // N, M, Q ≤ 2000; A = 0; B = 0
  void TestGroup6() {
    Subtasks({4, 5, 8});

    CASE(N = kQuadN; M = kQuadN; randomRootedQueries(N, M, kQuadN));
    CASE(N = kQuadN - 1; M = kQuadN - 1; randomRootedQueries(N, M, kQuadN - 3));
  }

  // A = 0; B = 0
  void TestGroup7() {
    Subtasks({5, 8});

    CASE(N = kMaxN; M = kMaxN; randomRootedQueries(N, M, kMaxQ));
    CASE(N = kMaxN - 1; M = kMaxN - 1; randomRootedQueries(N, M, kMaxQ - 3));
  }

  // A = C; A = 2^k
  void TestGroup8() {
    Subtasks({6, 7, 8});

    CASE(N = kMaxN; M = kMaxN; twoPowerQueries(N, M, kMaxQ));
    CASE(N = kMaxN; M = kMaxN; twoPowerQueries(N, M, kMaxQ - 20); customTwoPowerQueries(N, M));
  }

  // A = C
  void TestGroup9() {
    Subtasks({7, 8});

    CASE(N = kMaxN; M = kMaxN; randomACQueries(N, M, kMaxQ));
    CASE(N = kMaxN; M = kMaxN; largeACQueries(N, M, kMaxQ));
  }

  // Full
  void TestGroup10() {
    Subtasks({8});

    CASE(N = kMaxN; M = kMaxN; randomQueries(N, M, kMaxQ));
    CASE(N = kMaxN; M = kMaxN; maxQueries(N, M, kMaxQ - 1); addQuery(1, 1, N - 1, M - 1));
    CASE(N = kMaxN; M = kMaxN; largeQueries(N, M, kMaxQ));
    CASE(N = kMaxN; M = kMaxN; randomQueries(N, M, kMaxQ - 100); customQueries(N, M));
  }

  void addQuery(int a, int b, int c, int d) {
    A.push_back(a); B.push_back(b); C.push_back(c); D.push_back(d);
  }

  void randomACQueries(int N, int M, int Q) {
    for (int i = 0; i < Q; ++i) {
      A.push_back(rnd.nextInt(N));
      B.push_back(rnd.nextInt(M));
      C.push_back(A.back());
      D.push_back(rnd.nextInt(M));
      if (B.back() > D.back()) swap(B.back(), D.back());
    }
  }

  void randomQueries(int N, int M, int Q) {
    for (int i = 0; i < Q; ++i) {
      A.push_back(rnd.nextInt(N));
      B.push_back(rnd.nextInt(M));
      C.push_back(rnd.nextInt(N));
      D.push_back(rnd.nextInt(M));
      if (A.back() > C.back()) swap(A.back(), C.back());
      if (B.back() > D.back()) swap(B.back(), D.back());
    }
  }

  void randomRootedQueries(int N, int M, int Q) {
    for (int i = 0; i < Q; ++i) {
      A.push_back(0);
      B.push_back(0);
      C.push_back(rnd.nextInt(N));
      D.push_back(rnd.nextInt(M));
    }
  }

  void maxQueries(int N, int M, int Q) {
    for (int i = 0; i < Q; ++i) {
      A.push_back(0);
      B.push_back(0);
      C.push_back(N - 1);
      D.push_back(M - 1);
    }
  }

  void largeQueries(int N, int M, int Q, int margin=10) {
    for (int i = 0; i < Q; ++i) {
      A.push_back(rnd.nextInt(margin));
      B.push_back(rnd.nextInt(margin));
      C.push_back(N - rnd.nextInt(margin) - 1);
      D.push_back(M - rnd.nextInt(margin) - 1);
    }
  }

  void largeACQueries(int N, int M, int Q, int margin=10) {
    for (int i = 0; i < Q; ++i) {
      A.push_back(rnd.nextInt(N));
      B.push_back(rnd.nextInt(margin));
      C.push_back(A.back());
      D.push_back(M - rnd.nextInt(margin) - 1);
    }
  }

  void twoPowerQueries(int N, int M, int Q) {
    int lg = 32 - __builtin_clz(N - 1);
    for (int i = 0; i < Q; ++i) {
      A.push_back(1 << rnd.nextInt(lg));
      B.push_back(rnd.nextInt(M));
      C.push_back(A.back());
      D.push_back(rnd.nextInt(M));
      if (B.back() > D.back()) swap(B.back(), D.back());
    }
  }

  void customTwoPowerQueries(int N, int M) {
    int lg = 32 - __builtin_clz(N - 1) - 1;
    addQuery(1, 0, 1, M - 1);
    addQuery(1, 0, 1, 0);
    addQuery(1, M - 1, 1, M - 1);
    addQuery(1, M - 2, 1, M - 2);
    addQuery(1, M - 3, 1, M - 3);
    addQuery(1, M - 4, 1, M - 4);
    addQuery(1, 1, 1, 1);
    addQuery(1, 2, 1, 2);
    addQuery(1 << lg, 1 << lg, 1 << lg, 1 << lg);
    addQuery(1 << lg, (1 << lg) - 1, 1 << lg, (1 << lg) - 1);
    addQuery(1 << lg, (1 << lg) - 1, 1 << lg, (1 << lg));
    addQuery(1 << lg, (1 << lg) - 2, 1 << lg, (1 << lg) - 1);
    addQuery(1 << lg, (1 << lg), 1 << lg, (1 << lg) + 1);
  }

  void customACQueries(int N, int M) {
    customTwoPowerQueries(N, M);

    int lg = 32 - __builtin_clz(N - 1) - 1;

    int r = (1 << lg) - 1;
    addQuery(r, 0, r, M - 1);
    addQuery(r, 0, r, 1 << lg);
    addQuery(r, 0, r, (1 << lg) - 1);
    addQuery(r, 1, r, M - 1);
    addQuery(r, (1 << lg) - 1, r, 1 << lg);
    addQuery(r, 1 << lg, r, 1 << lg);
    addQuery(r, (1 << lg) - 1, r, (1 << lg) - 1);
    addQuery(r, (1 << lg) + 1, r, (1 << lg) + 1);
    addQuery(r, 0, r, 0);
    addQuery(r, 1, r, 1);
  }

  // Rough estimate: < 100 additional queries
  void customQueries(int N, int M) {
    vector<int> _A = A, _B = B, _C = C, _D = D;
    A.clear(); B.clear(); C.clear(); D.clear();

    int lgN = 32 - __builtin_clz(N - 1) - 1, lgM = 32 - __builtin_clz(M - 1) - 1;

    customACQueries(M, N);
    swap(A, B); swap(C, D);
    customACQueries(N, M);
    addQuery(1, 1, N - 1, M - 1);
    addQuery(1, 1, (1 << lgN) - 1, (1 << lgM) - 1);
    addQuery(2, 3, (1 << lgN), (1 << lgM));

    for (int i = 0; i < A.size(); ++i) {
      _A.push_back(A[i]); _B.push_back(B[i]); _C.push_back(C[i]); _D.push_back(D[i]);
    }
    A = _A, B = _B, C = _C, D = _D;
  }
};
