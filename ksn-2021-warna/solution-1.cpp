#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int X, Y;
int A[MAXN];
int B[MAXN];

bool ask(int x,int y) {
  cout<<"? "<<y<<" "<<x<<endl;
  cin>>X;
  return X==1;
}

int main () {
  cin>>T>>N>>Q;
  
  for (int i=1;i<=N;i++) {
    B[i]=i;
  }
  
  for (int i=1;i<=N;i=Y) {
    Y=lower_bound(B+i+1,B+N+1,i,ask)-B;
    for (int j=i;j<Y;j++) {
      A[j]=A[i-1]+1;
    }
  }
  
  cout<<"!";
  for (int i=1;i<=N;i++) {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
