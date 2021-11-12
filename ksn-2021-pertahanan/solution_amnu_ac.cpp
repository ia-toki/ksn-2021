#include <bits/stdc++.h>
using namespace std;

const int MAXN=3e3+5, MOD=1e9+7;

int N, M, K;
string S;
int dp[MAXN][MAXN][2];
int pref[MAXN][2], inc[MAXN][2];
int last[2];

inline int sum(int x,int y) {
  return x+y>=MOD?x+y-MOD:x+y;
}

inline void add(int &x,int y) {
  x=sum(x,y);
}

inline void sub(int &x,int y) {
  add(x,MOD-y);
}

int main() {
  cin>>N>>M>>K>>S;
  dp[0][0][0]=1;
  dp[0][0][1]=1;
  pref[0][0]=1;
  pref[0][1]=1;
  
  for (int i=1;i<=N;i++) {
    if (S[i-1]!='?') {
      last[S[i-1]-'A']=i;
      for (int j=0;j<=K;j++) {
        pref[j][S[i-1]-'A']=0;
        inc[j][S[i-1]-'A']=0;
      }
    }
    for (int j=K;j>=0;j--) {
      if (last[0]<=i-M) sub(pref[j][0],dp[i-M][j][0]);
      if (last[1]<=i-M) sub(pref[j][1],dp[i-M][j][1]);
      if (j) {
        inc[j][0]=inc[j-1][0];
        inc[j][1]=inc[j-1][1];
        if (last[0]<=i-M) add(inc[j][0],dp[i-M][j-1][0]);
        if (last[1]<=i-M) add(inc[j][1],dp[i-M][j-1][1]);
      }
      add(dp[i][j][0],sum(pref[j][1],inc[j][1]));
      add(dp[i][j][1],sum(pref[j][0],inc[j][0]));
      add(pref[j][0],dp[i][j][0]);
      add(pref[j][1],dp[i][j][1]);
    }
  }
  
  cout<<sum(dp[N][K][0],dp[N][K][1])<<'\n';
  return 0;
}
