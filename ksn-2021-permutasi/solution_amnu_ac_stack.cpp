#include <bits/stdc++.h>
using namespace std;

const int MAXN=3e5+5;
const long long MOD=1e9+7;

int N;
int A[MAXN];
int L[MAXN], R[MAXN];
bool LL[MAXN], RR[MAXN];
long long DP[MAXN];
stack <int> SL, SR;

int main () {
  cin>>N;
  for (int i=1;i<=N;i++) {
    cin>>A[i];
  }
  
  for (int i=1;i<=N;i++) {
    L[A[i]]=N+1;
    while (!SL.empty()) {
      if (A[i]>SL.top()) {
        break;
      }
      L[A[i]]=SL.top();
      SL.pop();
    }
    LL[A[i]]=!SL.empty();
    SL.push(A[i]);
  }
  
  for (int i=N;i>=1;i--) {
    R[A[i]]=N+1;
    while (!SR.empty()) {
      if (A[i]>SR.top()) {
        break;
      }
      R[A[i]]=SR.top();
      SR.pop();
    }
    RR[A[i]]=!SR.empty();
    SR.push(A[i]);
  }
  
  DP[N+1]=1;
  for (int i=N;i>=1;i--) {
    DP[i]=DP[L[i]]*DP[R[i]];
    if (LL[i]) DP[i]+=DP[R[i]];
    if (RR[i]) DP[i]+=DP[L[i]];
    if (LL[i]&&RR[i]) DP[i]+=MOD-1;
    DP[i]%=MOD;
  }
  cout<<DP[1]<<'\n';
}
