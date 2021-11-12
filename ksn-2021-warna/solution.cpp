#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e3+5;

int T, N, Q;
int X, Y;
int A[MAXN];
int B[MAXN];
int C[MAXN];

bool findPart(int x,int y) {
  if (!B[x]) return 0;
  cout<<"? "<<B[x]<<" "<<y<<endl;
  cin>>X;
  return X!=x;
}

bool findRight(int x,int y) {
  cout<<"? 1 "<<x<<endl;
  cin>>X;
  return X==x;
}

bool findLeft(int x,int y) {
  cout<<"? "<<x<<" "<<y<<endl;
  cin>>X;
  return X==y-x;
}

bool findAll(int x,int y) {
  cout<<"? "<<x<<" "<<y<<endl;
  cin>>X;
  return X==B[x];
}

int main () {
  cin>>T>>N>>Q;
  
  if (T==1||T==2) {
    for (int i=1;i<=N;i++) {
      cout<<"? 1 "<<i<<endl;
      cin>>A[i];
    }
  }
  
  if (T==3||T==4) {
    for (int i=1;i<=3;i++) {
      C[i]=i;
    }
    for (int i=1;i<=N;i++) {
      Y=lower_bound(C+1,C+4,i,findPart)-C;
      if (!B[Y]) {
        if (Y==4) {
          A[i]=10-A[B[1]]-A[B[2]]-A[B[3]];
        }
        else {
          A[i]=Y;
        }
      }
      else {
        A[i]=A[B[Y]];
      }
      for (int j=Y;j;j--) {
        B[j]=B[j-1];
      }
      B[1]=i;
    }
  }
  
  if (T==5) {
    for (int i=1;i<=N;i++) {
      A[i]=i;
    }
    Y=lower_bound(A+1,A+N+1,0,findRight)-A;
    if (Y<=N) {
      A[Y]=lower_bound(A+1,A+Y,Y,findLeft)-A;
      for (int i=Y;i<=N;i++) {
        A[i]--;
      }
    }
  }
  
  if (T==6||T==7) {
    for (int i=1;i<=N;i++) {
      Y=lower_bound(C+1,C+i,i,findAll)-C-1;
      if (!Y) {
        A[0]++;
      }
      A[i]=A[Y];
      for (int j=Y+1;j<=i;j++) {
        B[j]++;
      }
      C[i]=i;
    }
  }
  
  cout<<"!";
  for (int i=1;i<=N;i++) {
    cout<<" "<<A[i];
  }
  cout<<endl;
}
