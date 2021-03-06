#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <cassert>
#define makmu using
#define ndasmu namespace
#define gundulmu std

makmu ndasmu gundulmu;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<string,string> pss;
typedef pair<int,double> pid;
typedef pair<int,LL> pil;
typedef pair<LL,LL> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SYNC ios_base::sync_with_stdio(false)
#define TIE cin.tie(0)
#define g getchar_unlocked
#define INF 1000000000
#define INFLL 4000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
#define DEBUG puts("DEBUG")


int dx8[8]={-1,-1,0,1,1,1,0,-1},dx4[4]={-1,0,1,0};
int dy8[8]={0,-1,-1,-1,0,1,1,1},dy4[4]={0,-1,0,1};

inline void open(string name){
 freopen((name+".in").c_str(),"r",stdin);
 freopen((name+".out").c_str(),"w",stdout);
}

inline void close(){
 fclose(stdin);
 fclose(stdout);
}

inline int io(){
 register char c;
 while(1){
  c=g();
  if(c!='\n' && c!=' ') break;
 }
 int res=0,sign=1;
 if(c=='-') sign=-1;
 else       res=c-'0';
 while(1){
  c=g();
  if(c==' ' || c=='\n' || c==EOF) break;
  res=(res<<3)+(res<<1)+c-'0';
 }
 return res*sign;
}

///////////////////////////////////////////////////
//////            End of Template            /////
/////////////////////////////////////////////////

LL arr[100005];
int n;

int main(){
 n=io();
 while(n){
  LL ans=0;
  LL itpos=0,itneg=0;
  for(LL i=0;i<n;i++){
   arr[i]=io();
   while(itpos<i && arr[i]<0){
    if(arr[itpos]<=0) itpos++;
    else if(arr[itpos]<=-arr[i])
     ans+=(i-itpos)*(arr[itpos]),arr[i]+=arr[itpos],arr[itpos]=0,itpos++;
    else
     ans+=(i-itpos)*(-arr[i]),arr[itpos]+=arr[i],arr[i]=0;
   }
   while(itneg<i && arr[i]>0){
    if(arr[itneg]>=0) itneg++;
    else if(-arr[itneg]<=arr[i])
     ans+=(i-itneg)*(-arr[itneg]),arr[i]+=arr[itneg],arr[itneg]=0,itneg++;
    else
     ans+=(i-itneg)*(arr[i]),arr[itneg]+=arr[i],arr[i]=0; 
   }
  }
  printf("%lld\n",ans);
  n=io();
 }
 //puts("ganteng");
 return 0;
}

