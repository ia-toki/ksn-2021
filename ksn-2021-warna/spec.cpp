#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
  int T, N, Q;
  vector <int> A;
  
  void InputFormat() {
    LINE(T);
    LINE(N,Q);
    LINE(A%SIZE(N));
  }
  
  void GradingConfig() {
    TimeLimit(2);
    MemoryLimit(256);
  }
  
  void StyleConfig() {
    InteractiveEvaluator();
  }
  
  void Constraints() {
    CONS(2<=N&&N<=1000);
    CONS(minLexicography(A));
  }
  
  void Subtask1() {
    Points(8);
    CONS(T==1);
    CONS(Q==10000);
    CONS(isSorted(A));
  }
  
  void Subtask2() {
    Points(7);
    CONS(T==2);
    CONS(Q==2000);
    CONS(isSorted(A));
  }
  
  void Subtask3() {
    Points(19);
    CONS(T==3);
    CONS(Q==2000);
    CONS(maxValue(A)<=3);
  }
  
  void Subtask4() {
    Points(14);
    CONS(T==4);
    CONS(Q==2000);
    CONS(maxValue(A)<=4);
  }
  
  void Subtask5() {
    Points(12);
    CONS(T==5);
    CONS(Q==2000);
    CONS(maxValue(A)>=N-1);
  }
  
  void Subtask6() {
    Points(21);
    CONS(T==6);
    CONS(Q==10000);
    CONS(N<=100);
  }
  
  void Subtask7() {
    Points(19);
    CONS(T==7);
    CONS(Q==10000);
  }
  
private:
  bool minLexicography(vector <int> V) {
    int now=1;
    for (int x:V) {
      if (x<1||x>now) {
        return false;
      }
      if (x==now) {
        now++;
      }
    }
    return true;
  }
  
  bool isSorted(vector <int> V) {
    int last=1;
    for (int x:V) {
      if (x<last) {
        return false;
      }
      last=x;
    }
    return true;
  }
  
  int maxValue(vector <int> V) {
    int mx=1;
    for (int x:V) {
      mx=max(mx,x);
    }
    return mx;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
  void SampleTestCase1() {
    Subtasks({1});
    Input({
      "1",
      "5 10000",
      "1 1 1 2 2"
    });
  }
  
  void TestGroup1() {
    Subtasks({1});
    CASE(T=1,N=2,Q=10000,A={1,1});
    CASE(T=1,N=2,Q=10000,A={1,2});
    CASE(T=1,N=1000,Q=10000,A=sorted(N,0,1));
    CASE(T=1,N=1000,Q=10000,A=sorted(N,1,1));
    CASE(T=1,N=999,Q=10000,A=sorted(N,1,2));
    CASE(T=1,N=997,Q=10000,A=sorted(N,1,100));
    CASE(T=1,N=996,Q=10000,A=sorted(N,99,100));
  }
  
  void TestGroup2() {
    Subtasks({2});
    CASE(T=2,N=1000,Q=2000,A=sorted(N,0,1));
    CASE(T=2,N=1000,Q=2000,A=sorted(N,1,1));
    CASE(T=2,N=994,Q=2000,A=sorted(N,1,2));
    CASE(T=2,N=995,Q=2000,A=sorted(N,1,100));
    CASE(T=2,N=998,Q=2000,A=sorted(N,99,100));
  }
  
  void TestGroup3() {
    Subtasks({3});
    CASE(T=3,N=1000,Q=2000,A=periodic(N,1,2));
    CASE(T=3,N=1000,Q=2000,A=periodic(N,2,2));
    CASE(T=3,N=1000,Q=2000,A=periodic(N,1,3));
    CASE(T=3,N=1000,Q=2000,A=periodic(N,2,3));
    CASE(T=3,N=1000,Q=2000,A=periodic(N,3,3));
    CASE(T=3,N=1000,Q=2000,A=superPermutation(N,3));
    CASE(T=3,N=1000,Q=2000,A=maxRandom(N,3));
    CASE(T=3,N=999,Q=2000,A=maxRandom(N,3));
  }
  
  void TestGroup4() {
    Subtasks({4});
    CASE(T=4,N=1000,Q=2000,A=periodic(N,1,3));
    CASE(T=4,N=1000,Q=2000,A=periodic(N,2,3));
    CASE(T=4,N=1000,Q=2000,A=periodic(N,3,3));
    CASE(T=4,N=1000,Q=2000,A=periodic(N,1,4));
    CASE(T=4,N=1000,Q=2000,A=periodic(N,2,4));
    CASE(T=4,N=1000,Q=2000,A=periodic(N,3,4));
    CASE(T=4,N=1000,Q=2000,A=periodic(N,4,4));
    CASE(T=4,N=1000,Q=2000,A=superPermutation(N,4));
    CASE(T=4,N=1000,Q=2000,A=maxRandom(N,4));
    CASE(T=4,N=999,Q=2000,A=maxRandom(N,4));
  }
  
  void TestGroup5() {
    Subtasks({5});
    CASE(T=5,N=1000,Q=2000,A=sorted(N,1,1));
    CASE(T=5,N=1000,Q=2000,A=sameType(N,1,2));
    CASE(T=5,N=1000,Q=2000,A=sameType(N,N-1,N));
    CASE(T=5,N=1000,Q=2000,A=sameType(N,1,N));
    CASE(T=5,N=1000,Q=2000,A=sameType(N,1,673));
    CASE(T=5,N=1000,Q=2000,A=sameType(N,318,N));
    CASE(T=5,N=1000,Q=2000,A=sameType(N,294,712));
    CASE(T=5,N=1000,Q=2000,A=sameType(N,451,452));
  }
  
  void TestGroup6() {
    Subtasks({6});
    CASE(T=6,N=100,Q=10000,A=sorted(N,0,1));
    CASE(T=6,N=100,Q=10000,A=sorted(N,1,1));
    CASE(T=6,N=100,Q=10000,A=superPermutation(N,5));
    CASE(T=6,N=100,Q=10000,A=maxRandom(N,N));
    CASE(T=6,N=99,Q=10000,A=maxRandom(N,N));
    CASE(T=6,N=93,Q=10000,A=maxRandom(N,N));
    CASE(T=6,N=85,Q=10000,A=maxRandom(N,N));
  }
  
  void TestGroup7() {
    Subtasks({7});
    CASE(T=7,N=1000,Q=10000,A=sorted(N,0,1));
    CASE(T=7,N=1000,Q=10000,A=sorted(N,1,1));
    CASE(T=7,N=1000,Q=10000,A=superPermutation(N,6));
    CASE(T=7,N=1000,Q=10000,A=maxRandom(N,N));
    CASE(T=7,N=998,Q=10000,A=maxRandom(N,N));
    CASE(T=7,N=975,Q=10000,A=maxRandom(N,N));
    CASE(T=7,N=891,Q=10000,A=maxRandom(N,N));
  }
  
private:
  vector <int> sorted(int N,int p,int q) {
    vector <int> V={1};
    for (int i=1;i<N;i++) {
      if (rnd.nextInt(1,q)<=p) {
        V.push_back(V[i-1]+1);
      }
      else {
        V.push_back(V[i-1]);
      }
    }
    return V;
  }
  
  vector <int> periodic(int N,int l,int r) {
    vector <int> V={1};
    for (int i=1;i<N;i++) {
      if (V[i-1]==r) {
        V.push_back(l);
      }
      else {
        V.push_back(V[i-1]+1);
      }
    }
    return V;
  }
  
  vector <int> superPermutation(int N,int K) {
    // http://superpermutation.com/
    string S="1";
    if (K==2) S="121";
    if (K==3) S="123121321";
    if (K==4) S="123412314231243121342132413214321";
    if (K==5) S="123451234152341253412354123145231425314235142315423124531243512431524312543121345213425134215342135421324513241532413524132541321453214352143251432154321";
    if (K==6) S="12345612345162345126345123645132645136245136425136452136451234651234156234152634152364152346152341652341256341253641253461253416253412653412356412354612354162354126354123654132654312645316243516243156243165243162543162453164253146253142653142563142536142531645231465231456231452631452361452316453216453126435126431526431256432156423154623154263154236154231654231564213564215362415362145362154362153462135462134562134652134625134621536421563421653421635421634521634251634215643251643256143256413256431265432165432615342613542613452613425613426513426153246513246531246351246315246312546321546325146325416325461325463124563214563241563245163245613245631246532146532416532461532641532614532615432651436251436521435621435261435216435214635214365124361524361254361245361243561243651423561423516423514623514263514236514326541362541365241356241352641352461352416352413654213654123";
    vector <int> V;
    for (int i=0;i<N;i++) {
      V.push_back(S[i%S.length()]-'0');
    }
    return V;
  }
  
  vector <int> maxRandom(int N,int m) {
    vector <int> V;
    int now=1;
    for (int i=0;i<N;i++) {
      V.push_back(rnd.nextInt(1,now));
      if (V[i]==now&&now<m) {
        now++;
      }
    }
    return V;
  }
  
  vector <int> sameType(int N,int x,int y) {
    vector <int> V(N);
    iota(V.begin(),V.end(),1);
    V[y]=x;
    for (int i=y+1;i<=N;i++) {
      V[i]--;
    }
    return V;
  }
};
