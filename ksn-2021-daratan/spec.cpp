#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MIDN = 3E4;
const int MAXN = 1E5;

const int MAXLOG = 30;
const int MAXA = (1<<MAXLOG)-1;

const int LOWB = 1E4-1;
const int MIDB = 1E7-1;
const int MAXB = 1E9;

const int MAXN_sub2 = 200;
const int MAXN_sub3 = 2000;
const int MAXLOG_sub6 = 12;
const int MAXA_sub6 = (1<<MAXLOG_sub6)-1;

class ProblemSpec : public BaseProblemSpec {
protected:
  int N;
  vector<int> A, B;

  vector<long long> ANS;

  void InputFormat() {
    LINE(N);
    LINE(A % SIZE(N));
    LINE(B % SIZE(N));
  }

  void OutputFormat() {
    LINES(ANS) % SIZE(N);
  }
  
  void GradingConfig() {
    TimeLimit(1);
    MemoryLimit(256);
  }

  void Constraints() {
    CONS(between(N, 1, MAXN));
    CONS(allBetween(A, 1, MAXA));
    CONS(allBetween(B, 1, MAXB));
  }

  void Subtask1() {
    Points(8);
    CONS(N == 8);
    CONS(A == vector<int>({6, 39, 11, 63, 3, 39, 1, 43}));
    CONS(B == vector<int>({4, 8, 3, 7, 9, 1, 2, 2}));
  }

  void Subtask2() {
    Points(13);
    CONS(between(N, 1, MAXN_sub2));
  }

  void Subtask3() {
    Points(10);
    CONS(between(N, 1, MAXN_sub3));
  }

  void Subtask4() {
    Points(4);
    CONS(allSame(A));
  }

  void Subtask5() {
    Points(7);
    CONS(allPowerOfTwo(A));
  }

  void Subtask6() {
    Points(19);
    CONS(allBetween(A, 1, MAXA_sub6));
  }

  void Subtask7() {
    Points(39);
  }
private:
  bool between(int x,int l,int r) {
    return l <= x && x <= r;
  }
  bool allBetween(vector<int> &v,int l,int r) {
    for (auto x: v) {
      if (!between(x, l, r)) return false;
    }
    return true;
  }
  bool allSame(vector<int> &v) {
    for (auto x: v) {
      if (x != v[0]) return false;
    }
    return true;
  }
  bool allPowerOfTwo(vector<int> &v) {
    for (auto x: v) {
      if (__builtin_popcount(x) != 1) return false;
    }
    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
  void SampleTestCase1() {
    Subtasks({2, 3, 5, 6, 7});
    Input({
      "3",
      "2 1 1",
      "20 30 10"
    });
    Output({
      "60",
      "60",
      "60"
    });
  }
  
  void SampleTestCase2() {
    Subtasks({2, 3, 6, 7});
    Input({
      "4",
      "5 4 4 5",
      "10 20 30 40"
    });
    Output({
      "10",
      "20",
      "30",
      "40"
    });
  }
  
  void SampleTestCase3() {
    Subtasks({2, 3, 6, 7});
    Input({
      "5",
      "1 2 1 7 11",
      "20 10 30 100 100"
    });
    Output({
      "60",
      "60",
      "60",
      "200",
      "200"
    });
  }

  void BeforeTestCase() {
    A.clear();
    B.clear();
  }

  void AfterTestCase() {
    if (A != vector<int>({6, 39, 11, 63, 3, 39, 1, 43})) {
      vector<pair<int,int> > temp;
      for (int i = 0; i < N; i++) temp.push_back({A[i], B[i]});
      rnd.shuffle(temp.begin(), temp.end());
      for (int i = 0; i < N; i++) {
        A[i] = temp[i].first;
        B[i] = temp[i].second;
      }
    }
  }

  //Open subtask
  void TestGroup1() {
    Subtasks({1, 2, 3, 6, 7});
    CASE(
      N = 8;
      A = {6, 39, 11, 63, 3, 39, 1, 43};
      B = {4, 8, 3, 7, 9, 1, 2, 2};
    );
  }

  //N<=200, A_i all same, A_i < 2^10
  void TestGroup2() {
    Subtasks({2, 3, 4, 6, 7});
    
    CASE(
      N = 3;
      A = {3, 3, 3},
      B = {7, 8, 9}
    );
    
    CASE(
      N = MAXN_sub2;
      uniformVector(A, N, 1023, 1023);
      randomVector(B, N, 1, MAXB);
    );
    
    
  }
  
  //N<=200, A_i power of 2, A_i < 2^10
  void TestGroup3() {
    Subtasks({2, 3, 5, 6, 7});
    
    CASE(N = 2, A = {1, 2}, B = {3, 4});
    CASE(N = 3, A = {1, 2, 1}, B = {3, 4, 5});
    CASE(N = 5, A = {1, 2, 1, 2, 1}, B = {3, 4, 5, 6, 7});
    CASE(N = 5, A = {1, 2, 4, 2, 1}, B = {3, 4, 5, 6, 7});
    
    //Overflow Killer
    CASE(
      N = MAXN_sub2;
      powerOfTwoVector(A, N, 0, MAXLOG_sub6-1);
      randomVector(B, N, MAXB-1000, MAXB);
    );
    
    CASE(
      N = MAXN_sub2;
      powerOfTwoVector(A, N, 0, MAXLOG_sub6-1);
      randomVector(B, N, 1, MAXB);
    );
  }
  
  //N<=200, A_i all same, A_i power of 2, A_i < 2^10
  void TestGroup4() {
    Subtasks({2, 3, 4, 5, 6, 7});
    
    CASE(N = 1, A = {1}, B = {1});
    CASE(N = 2, A = {1, 1}, B = {1, 2});
    
    CASE(
      N = MAXN_sub2;
      uniformVector(A, N, 512, 512);
      randomVector(B, N, 1, MAXB);
    );
  }
  
  //N<=200, A_i < 2^10
  void TestGroup5() {
    Subtasks({2, 3, 6, 7});
    
    //Verify union mechanism
    CASE(
      N = 10;
      A = fromBinary({
        "111",
        "101",
        "010",
        "001"
      });
      addNoise(A, N);
      randomVector(B, N, 1, 1);
    );
    
    CASE(
      N = MAXN_sub2;
      A = fromBinary({
        "10111101",
        "10011111",
        "11011101",
        "00101111",
        "00011101",
        "00001011",
        "00001101",
        "00000110",
        "00000001"
      });
      addNoise(A, N);
      randomVector(B, N, 1, 1);
    );

    //Prabowo's bug
    CASE(
      N = 33;
      A = {189, 159, 221, 47, 29, 11, 6, 1,
         189, 159, 221, 47, 29, 11, 6, 1,
         189, 159, 221, 47, 29, 11, 6, 1,
         189, 159, 221, 47, 29, 11, 6, 1,
         13
      };
      randomVector(B, N, 1, 1);
    );
    
    CASE(
      N = MAXN_sub2;
      byMSBVector(A, N, MAXLOG_sub6-1);
      randomVector(B, N, 1, MAXB);
    );
    CASE(
      N = MAXN_sub2;
      byMSBVector(A, N/2, MAXLOG_sub6-1);
      byMSBVector(A, N/2, MAXLOG_sub6-2);
      randomVector(B, N, 1, MAXB);
    );
    CASE(
      N = MAXN_sub2;
      byCCVector(A, N/2, 2, MAXLOG_sub6);
      addNoise(A, N);
      randomVector(B, N, 1, MAXB);
    );
  }
  
  //N<=200, A_i all same
  void TestGroup6() {
    Subtasks({2, 3, 4, 7});
    
    CASE(
      N = MAXN_sub2;
      uniformVector(A, N, MAXA, MAXA);
      randomVector(B, N, 1, MAXB);
    );
  }
  
  //N<=200, A_i power of 2
  void TestGroup7() {
    Subtasks({2, 3, 5, 7});
    
    CASE(
      N = MAXN_sub2;
      powerOfTwoVector(A, N, 0, MAXLOG-1);
      randomVector(B, N, 1, MAXB);
    );
  }
  
  //N<=200, A_i all same, A_i power of 2
  void TestGroup8() {
    Subtasks({2, 3, 4, 5, 7});
    
    CASE(
      N = MAXN_sub2;
      uniformVector(A, N, 1 << (MAXLOG-1), 1 << (MAXLOG-1));
      randomVector(B, N, 1, MAXB);
    );
  }
  
  //N<=200
  void TestGroup9() {
    Subtasks({2, 3, 7});
    
    CASE(
      N = MAXN_sub2;
      byMSBVector(A, N, MAXLOG-1);
      randomVector(B, N, 1, MAXB);
    );
    CASE(
      N = MAXN_sub2;
      byMSBVector(A, N/2, MAXLOG-1);
      byMSBVector(A, N/2, MAXLOG-2);
      randomVector(B, N, 1, MAXB);
    );
    
    CASE(
      N = MAXN_sub2;
      byCCVector(A, N-10, 5, MAXLOG);
      addNoise(A, N);
      randomVector(B, N, 1, MAXB);
    );
    CASE(
      N = MAXN_sub2;
      byCCVector(A, N/2, 3, MAXLOG);
      addNoise(A, N);
      randomVector(B, N, 1, MAXB);
    );
    
    CASE(
      N = MAXN_sub2;
      stairs(A, N, MAXLOG);
      randomVector(B, N, 1, MAXB);
    );
  }
  
  //N<=2000, A_i all same, A_i < 2^10
  void TestGroup10() {
    Subtasks({3, 4, 6, 7});
    
    CASE(
      N = MAXN_sub3;
      uniformVector(A, N, 99, 99);
      randomVector(B, N, 1, MIDB);
    );
  }
  
  //N<=2000, A_i power of 2, A_i < 2^10
  void TestGroup11() {
    Subtasks({3, 5, 6, 7});
    
    CASE(
      N = MAXN_sub3;
      powerOfTwoVector(A, N, 0, MAXLOG_sub6-1);
      randomVector(B, N, MIDB-10000, MIDB);
    );
  }
    
  
  //N<=2000, A_i all same, A_i power of 2, A_i < 2^10
  void TestGroup12() {
    Subtasks({3, 4, 5, 6, 7});
    
    CASE(
      N = MAXN_sub3;
      uniformVector(A, N, 64, 64);
      randomVector(B, N, 1, MIDB);
    );
  }
  
  //N<=2000, A_i < 2^10
  void TestGroup13() {
    Subtasks({3, 6, 7});
    
    CASE(
      N = MAXN_sub3;
      byMSBVector(A, N, MAXLOG_sub6-1);
      randomVector(B, N, 1, MIDB);
    );
    CASE(
      N = MAXN_sub3;
      byMSBVector(A, N/2, MAXLOG_sub6-1);
      byMSBVector(A, N/2, MAXLOG_sub6-2);
      randomVector(B, N, 1, MIDB);
    );
    
    CASE(
      N = MAXN_sub3;
      byCCVector(A, N/4, 2, MAXLOG_sub6);
      addNoise(A, N);
      randomVector(B, N, 1, MIDB);
    );
    CASE(
      N = MAXN_sub3;
      byCCVector(A, N/4, 3, MAXLOG_sub6);
      addNoise(A, N);
      randomVector(B, N, 1, MIDB);
    );
    
    CASE(
      N = MAXN_sub3;
      arithmetic(A, N, MAXLOG_sub6);
      randomVector(B, N, 1, MIDB);
    );
  }
  
  //N<=2000, A_i all same
  void TestGroup14() {
    Subtasks({3, 4, 7});
    
    CASE(
      N = MAXN_sub3;
      uniformVector(A, N, 9999, 9999);
      randomVector(B, N, 1, MIDB);
    );
  }
  
  //N<=2000, A_i power of 2
  void TestGroup15() {
    Subtasks({3, 5, 7});
    
    CASE(
      N = MAXN_sub3;
      powerOfTwoVector(A, N, 0, MAXLOG-1);
      randomVector(B, N, MIDB-10000, MIDB);
    );
  }
  
  //N<=2000, A_i all same, A_i power of 2
  void TestGroup16() {
    Subtasks({3, 4, 5, 7});
    
    CASE(
      N = MAXN_sub3;
      uniformVector(A, N, 8192, 8192);
      randomVector(B, N, 1, MIDB);
    );
  }
  
  //N<=2000
  void TestGroup17() {
    Subtasks({3, 7});
    
    CASE(
      N = MAXN_sub3;
      byMSBVector(A, N, MAXLOG-1);
      randomVector(B, N, 1, MIDB);
    );
    CASE(
      N = MAXN_sub3;
      byMSBVector(A, N/2, MAXLOG-1);
      byMSBVector(A, N/2, MAXLOG-2);
      randomVector(B, N, 1, MIDB);
    );
    
    CASE(
      N = MAXN_sub3;
      A = {(1 << (MAXLOG-1))};
      randomVector(A, N-1, 1, (1 << (MAXLOG-1))-1);
      randomVector(B, N, 1, MIDB);
    );
    CASE(
      N = MAXN_sub3;
      A = {(1 << (MAXLOG-1))};
      byCCVector(A, N-1, 2, MAXLOG);
      randomVector(B, N, 1, MIDB);
    );
    
    CASE(
      N = MAXN_sub3;
      byCCVector(A, N-200, 5, MAXLOG);
      addNoise(A, N);
      randomVector(B, N, 1, MIDB);
    );
    CASE(
      N = MAXN_sub3;
      byCCVector(A, N-200, 3, MAXLOG);
      addNoise(A, N);
      randomVector(B, N, 1, MIDB);
    );
    
    CASE(
      N = MAXN_sub3;
      stairs(A, N, MAXLOG);
      randomVector(B, N, 1, MIDB);
    );
  }
  
  //A_i all same, A_i < 2^10
  void TestGroup18() {
    Subtasks({4, 6, 7});
    
    CASE(
      N = MIDN;
      uniformVector(A, N, 9, 9);
      randomVector(B, N, 1, 9);
    );
  }
  
  //A_i power of 2, A_i < 2^10
  void TestGroup19() {
    Subtasks({5, 6, 7});
    
    CASE(
      N = MIDN;
      uniformVector(A, N/2, 1, 1);
      uniformVector(A, N/2, 2, 2);
      randomVector(B, N, LOWB-100, LOWB);
    );
    
    CASE(
      N = MIDN;
      powerOfTwoVector(A, N, 0, MAXLOG_sub6-1);
      randomVector(B, N, LOWB-100, LOWB);
    );
  }
  
  //A_i all same, A_i power of 2, A_i < 2^10
  void TestGroup20() {
    Subtasks({4, 5, 6, 7});
    
    CASE(
      N = MAXN;
      uniformVector(A, N, 1, 1);
      randomVector(B, N, 1, 9);
    );
  }
  
  //A_i < 2^10
  void TestGroup21() {
    Subtasks({6, 7});
    
    CASE(
      N = MIDN;
      byMSBVector(A, N/2, MAXLOG_sub6-1);
      byMSBVector(A, N/2, MAXLOG_sub6-2);
      randomVector(B, N, 1, LOWB);
    );
    
    CASE(
      N = MIDN;
      byCCVector(A, N/4, 2, MAXLOG_sub6);
      addNoise(A, N);
      randomVector(B, N, 1, LOWB);
    );
    
    CASE(
      N = MIDN;
      arithmetic(A, N, MAXLOG_sub6);
      randomVector(B, N, 1, LOWB);
    );
    
    CASE(
      N = MAXN;
      A = {(1 << MAXLOG_sub6) - 1};
      byMSBVector(A, N/2-1, MAXLOG_sub6-1);
      randomVector(A, N/2, 1, (1 << (MAXLOG_sub6-1)) - 1);
      randomVector(B, N, 1, 9);
    );
    
    CASE(
      N = MAXN;
      counterNMAXA(A, N);
      randomVector(B, N, 1, 9);
    );
  }
  
  //A_i all same
  void TestGroup22() {
    Subtasks({4, 7});
    
    CASE(
      N = MIDN;
      uniformVector(A, N, MAXA_sub6+2, MAXA_sub6+2);
      randomVector(B, N, 1, 9);
    );
  }
  
  //A_i power of 2
  void TestGroup23() {
    Subtasks({5, 7});
    
    //Haram killer: forgot to clear pending union
    CASE(
      N = MIDN;
      uniformVector(A, N/2, 1 << (MAXLOG-1), 1 << (MAXLOG-1));
      uniformVector(A, N/2, 1, 1);
      randomVector(B, N, 1, 9);
    );
    
    CASE(
      N = MIDN;
      uniformVector(A, N/2, 1 << (MAXLOG-1), 1 << (MAXLOG-1));
      powerOfTwoVector(A, N/2, 0, MAXLOG-2);
      randomVector(B, N, 1, 9);
    );
    
    CASE(
      N = MIDN;
      for (int i = 0; i < MAXLOG; i++) {
        uniformVector(A, 1, 1<<i, 1<<i);
      }
      addNoise(A, N);
      randomVector(B, N, 1, 9);
    );
    
    CASE(
      N = MIDN;
      powerOfTwoVector(A, N, 0, MAXLOG-1);
      randomVector(B, N, 1, 9);
    );
  }
  
  //A_i all same, A_i power of 2
  void TestGroup24() {
    Subtasks({4, 5, 7});
    
    CASE(
      N = MIDN;
      uniformVector(A, N, MAXA_sub6+1, MAXA_sub6+1);
      randomVector(B, N, 1, 9);
    );
  }
  
  //Full
  void TestGroup25() {
    Subtasks({7});
    
    CASE(
      N = MIDN;
      byCCVector(A, N-1000, 5, MAXLOG);
      addNoise(A, N);
      randomVector(B, N, 1, LOWB);
    );
    CASE(
      N = MIDN;
      byCCVector(A, N-1000, 3, MAXLOG);
      addNoise(A, N);
      randomVector(B, N, 1, LOWB);
    );
    
    CASE(
      N = MIDN;
      stairs(A, N, MAXLOG);
      randomVector(B, N, 1, LOWB);
    );
    
    CASE(
      N = 70000;
      arithmetic(A, N, 16);
      randomVector(B, N, 1, 9);
    );
    
    CASE(
      N = MAXN;
      A = {(1 << MAXLOG) - 1};
      byMSBVector(A, N/2-1, MAXLOG-1);
      randomVector(A, N/2, 1, (1 << (MAXLOG-1)) - 1);
      randomVector(B, N, 1, 9);
    );
    
    CASE(
      N = MAXN;
      A = {(1 << (MAXLOG-1))};
      randomVector(A, N-1, 1, (1 << (MAXLOG-1))-1);
      randomVector(B, N, 1, 9);
    );
    CASE(
      N = MAXN;
      A = {(1 << (MAXLOG-1))};
      byCCVector(A, N-1, 2, MAXLOG);
      randomVector(B, N, 1, 9);
    );
    
    CASE(
      N = MAXN;
      byCCVector(A, N-1000, 3, MAXLOG);
      addNoise(A, N);
      randomVector(B, N, 1, 9);
    );
    CASE(
      N = MAXN;
      byCCVector(A, N-1000, 2, MAXLOG);
      addNoise(A, N);
      randomVector(B, N, 1, 9);
    );
  }

private:
//MSB
  int msb(int x) {
    int ret=-1;
    for (int i = 0; i < MAXLOG; i++) {
      if (x&(1<<i)) ret = i;
    }
    return ret;
  }

//TC Generator
  void randomVector(vector<int> &v, int sz, int l, int r) {
    while (sz--) v.push_back(rnd.nextInt(l, r));
  }
  void uniformVector(vector<int> &v, int sz, int l, int r) {
    int k = rnd.nextInt(l, r);
    randomVector(v, sz, k, k);
  }
  void powerOfTwoVector(vector<int> &v, int sz, int l, int r) {
    while (sz--) v.push_back(1 << (rnd.nextInt(l, r)));
  }
  void byMSBVector(vector<int> &v, int sz, int msb) {
    randomVector(v, sz, 1 << msb, (1 << (msb+1))-1);
  }
  void subsetVector(vector<int> &v, int sz, int mask) {
    int remove_msb = 0;
    for (int i = 0; i < MAXLOG; i++) {
      int toss = rnd.nextInt(8);
      if (toss == 0) remove_msb |= (1 << i);
    }
    remove_msb &= mask;
    while (sz--) {
      while (true) {
        int toss = rnd.nextInt(1, (1 << MAXLOG)-1);
        int cur = mask & toss;
        while ((1 << msb(cur)) & remove_msb) cur ^= (1 << msb(cur));
        if (cur > 0) {
          v.push_back(cur);
          break;
        }
      }
      
    }
  }
  void byCCVector(vector<int> &v, int sz, int max_cc, int max_log, bool debug=false) {
    assert(sz >= max_cc);
    
    vector<int> round_robin;
    for (int i = 0; i < max_cc; i++) round_robin.push_back(i);
    rnd.shuffle(round_robin.begin(), round_robin.end());
    
    vector<int> cc_msb[max_cc];
    int idx = 0;
    for (int msb = 0; msb < max_log; msb++) {
      cc_msb[round_robin[idx]].push_back(msb);
      idx++;
      idx %= max_cc;
    }
    
    vector<int> cc_mask(max_cc, 0);
    vector<int> weight(max_cc, 0);
    for (int i = 0; i < max_cc; i++) {
      for (auto mbs: cc_msb[i]) cc_mask[i] |= (1 << mbs);
    }
    
    weight[0] = (1 << __builtin_popcount(cc_mask[0]));
    for (int i = 1; i < max_cc; i++) {
      weight[i] = weight[i-1] + (1 << __builtin_popcount(cc_mask[i]));
    }
    
    for (int i = 0; i < max_cc; i++) subsetVector(v, 1, cc_mask[i]);
    sz -= max_cc;
    if (sz == 0) return;
    
    vector<int> distribute_size(max_cc, 0);
    while (sz--) {
      int toss = rnd.nextInt(weight.back());
      if (toss < weight[0]) distribute_size[0]++;
      else for (int i = 1; i < max_cc; i++) {
        if (toss >= weight[i-1] && toss < weight[i]) {
          distribute_size[i]++;
          break;
        }
      }
    }
    
    for (int i = 0; i < max_cc; i++) {
      subsetVector(v, distribute_size[i], cc_mask[i]);
    }
  }
  void addNoise(vector<int> &v, int n) {
    vector<int> tmp = v;
    while (v.size() != n) v.push_back(tmp[rnd.nextInt(tmp.size())]);
  }

//Special property TC
  void stairs(vector<int> &v, int sz, int max_log) {
    assert(sz >= max_log);
    for (int i = 0; i < max_log; i++) {
      int cur = (1 << (i+1)) - 1;
      if (i > 0) cur ^= (1 << (i-1));
      v.push_back(cur);
    }
    addNoise(v, sz);
  }
  void arithmetic(vector<int> &v, int sz, int max_log) {
    if (sz >= (1 << max_log)-1) {
      for (int i = 1; i < (1 << max_log); i++) v.push_back(i);
      addNoise(v, sz);
    }
    else {
      for (int i = 1; i <= sz; i++) v.push_back(i);
    }
  }
  void counterNMAXA(vector<int> &v, int sz) {
    uniformVector(v, sz-MAXA_sub6/2, 1, 1);
    for (int i = 2; i <= MAXA_sub6; i += 2) {
      v.push_back(i);
    }
  }


//Hardcode helpers
  
  int binaryToInt(string s) {
    int ret = 0;
    for (auto c: s) {
      ret *= 2;
      ret += (c-'0');
    }
    return ret;
  }
  vector<int> fromBinary(vector<string> v) {
    vector<int> ret;
    for (auto s: v) ret.push_back(binaryToInt(s));
    return ret;
  }
};
