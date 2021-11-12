#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

const int MAXN=100000;
const int QUADRATIC=3000;
const int CUBIC=200;
const int HRF=26;

namespace solution {
  static int N, L, C[HRF];

  static bool isValid(int x) {
    int sum=0, maks=0;
    for (int i=0;i<HRF;i++) {
      sum+=C[i];
      if (i!=x&&C[i]>maks) {
        maks=C[i];
      }
    }
    return 2*maks<=sum;
  }

  static int minChar() {
    for (int i=0;i<HRF;i++) {
      if (i!=L&&C[i]&&isValid(i)) {
        C[i]--;
        return L=i;
      }
    }
    assert(0);
    return -1;
  }

  static string answer(string S) {
    N=S.length();
    L=-1;
    memset(C,0,sizeof(C));
    for (char c : S) {
      C[c-'A']++;
    }
    string T="";
    for (int i=0;i<N;i++) {
      T+=char('A'+minChar());
    }
    return T;
  }
}

class ProblemSpec : public BaseProblemSpec {
protected:
  int N;
  string S, T;
  
  void InputFormat() {
    LINE(N);
    LINE(S);
  }
  
  void OutputFormat() {
    LINE(T);
  }
  
  void GradingConfig() {
    TimeLimit(1);
    MemoryLimit(256);
  }
  
  void Constraints() {
    CONS(1<=N&&N<=MAXN);
    CONS(S.length()==N);
    CONS(onlyContains(S,'A','Z'));
    CONS(isSelfWord(S));
  }
  
  void Subtask1() {
    Points(8);
    CONS(N==7);
    CONS(S=="ACBACAB");
  }
  
  void Subtask2() {
    Points(6);
    CONS(S==solution::answer(S));
  }
  
  void Subtask3() {
    Points(9);
    CONS(onlyContains(S,'A','B'));
  }
  
  void Subtask4() {
    Points(12);
    CONS(uniqueCharacters(S));
  }
  
  void Subtask5() {
    Points(14);
    CONS(N<=10);
  }
  
  void Subtask6() {
    Points(13);
    CONS(N<=CUBIC);
  }
  
  void Subtask7() {
    Points(15);
    CONS(N<=QUADRATIC);
  }
  
  void Subtask8() {
    Points(23);
  }
  
private:
  bool onlyContains(string S,char L,char R) {
    for (char c : S) {
      if (c<L||c>R) {
        return false;
      }
    }
    return true;
  }
  
  bool isSelfWord(string S) {
    char b=0;
    for (char c : S) {
      if (b==c) {
        return false;
      }
      b=c;
    }
    return true;
  }
  
  bool uniqueCharacters(string S) {
    sort(S.begin(),S.end());
    return isSelfWord(S);
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
  void SampleTestCase1() {
    Subtasks({5,6,7,8});
    Input({
      "5",
      "BADBC"
    });
    Output({
      "ABCBD"
    });
  }
  
  void SampleTestCase2() {
    Subtasks({2,3,5,6,7,8});
    Input({
      "3",
      "ABA"
    });
    Output({
      "ABA"
    });
  }
  
  void TestGroup1() {
    Subtasks({1,5,6,7,8});
    CASE(N=7,S="ACBACAB");
  }
  
  void TestGroup2() {
    Subtasks({2,3,4,5,6,7,8});
    CASE(N=1,S="A");
    CASE(N=1,S="B");
    CASE(N=2,S="AB");
  }
  
  void TestGroup3() {
    Subtasks({2,3,8});
    CASE(N=MAXN-1,S=alternate(N,"AB"));
    CASE(N=MAXN-1,S=alternate(N,"BA"));
    CASE(N=MAXN,S=alternate(N,"AB"));
  }
  
  void TestGroup4() {
    Subtasks({2,4,6,7,8});
    CASE(N=HRF/2,S=unique(N),sort(S.begin(),S.end()));
    CASE(N=HRF-1,S=unique(N),sort(S.begin(),S.end()));
    CASE(N=HRF,S=unique(N),sort(S.begin(),S.end()));
  }
  
  void TestGroup5() {
    Subtasks({2,8});
    CASE(N=MAXN,S=alternate(N,"BC"));
    CASE(N=MAXN-1,S=sature(N),S=solution::answer(S));
    CASE(N=MAXN,S=sature(N),S=solution::answer(S));
    CASE(N=MAXN,S=dominant(N),S=solution::answer(S));
    CASE(N=MAXN,S=random(N),S=solution::answer(S));
    CASE(N=MAXN,S=limited(N,3),S=solution::answer(S));
  }
  
  void TestGroup6() {
    Subtasks({3,8});
    CASE(N=MAXN/2,S=alternate(N,"BA"));
    CASE(N=MAXN,S=alternate(N,"BA"));
  }
  
  void TestGroup7() {
    Subtasks({4,6,7,8});
    CASE(N=HRF/2,S=unique(N));
    CASE(N=HRF-1,S=unique(N));
    CASE(N=HRF,S=unique(N));
  }
  
  void TestGroup8() {
    Subtasks({5,6,7,8});
    CASE(N=9,S="MFMYMDMLM");
    CASE(N=10,S="GCGTGHGDGI");
    CASE(N=10,S="WCDTCWCWOC");
    CASE(N=10,S="HDYFKLWDTK");
    CASE(N=10,S="HTRHRTHRHT");
  }
  
  void TestGroup9() {
    Subtasks({6,7,8});
    CASE(N=CUBIC-1,S=sature(N));
    CASE(N=CUBIC,S=sature(N));
    CASE(N=CUBIC,S=dominant(N));
    CASE(N=CUBIC,S=random(N));
    CASE(N=CUBIC,S=limited(N,3));
  }
  
  void TestGroup10() {
    Subtasks({7,8});
    CASE(N=QUADRATIC-1,S=sature(N));
    CASE(N=QUADRATIC,S=sature(N));
    CASE(N=QUADRATIC,S=dominant(N));
    CASE(N=QUADRATIC,S=random(N));
    CASE(N=QUADRATIC,S=limited(N,3));
  }
  
  void TestGroup11() {
    Subtasks({8});
    CASE(N=MAXN-1,S=sature(N));
    CASE(N=MAXN,S=sature(N));
    CASE(N=MAXN,S=dominant(N));
    CASE(N=MAXN,S=random(N));
    CASE(N=MAXN,S=limited(N,3));
  }
  
private:
  char except(string s) {
    string ret=" ";
    do {
      ret[0]=rnd.nextInt('A','Z');
    }
    while (s.find(ret)<s.length());
    return ret[0];
  }
  
  string alternate(int N,string c) {
    string ret="";
    for (int i=0;i<N;i++) {
      ret+=c[i&1];
    }
    return ret;
  }
  
  string unique(int N) {
    string ret="";
    for (int i=0;i<HRF;i++) {
      ret+=char('A'+i);
    }
    rnd.shuffle(ret.begin(),ret.end());
    ret.erase(N);
    return ret;
  }
  
  string sature(int N) {
    string ret="", c="";
    c+=except(c);
    for (int i=0;i<N;i++) {
      if (i&1) {
        ret+=except(c);
      }
      else {
        ret+=c[0];
      }
    }
    return ret;
  }
  
  string dominant(int N) {
    string ret="", c=" ";
    c+=except(c);
    for (int i=0;i<N;i++) {
      if (rnd.nextInt(0,1)&&c[0]!=c[1]) {
        ret+=c[1];
      }
      else {
        ret+=except(c);
      }
      c[0]=ret[i];
    }
    return ret;
  }
  
  string random(int N) {
    string ret="", c=" ";
    for (int i=0;i<N;i++) {
      c[0]=except(c);
      ret+=c[0];
    }
    return ret;
  }
  
  string limited(int N,int K) {
    string ret="", c=" ";
    for (int i=K;i<HRF;i++) {
      c+=except(c);
    }
    for (int i=0;i<N;i++) {
      c[0]=except(c);
      ret+=c[0];
    }
    return ret;
  }
};
