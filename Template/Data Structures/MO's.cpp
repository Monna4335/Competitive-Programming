#include<bits/stdc++.h>
using namespace std;
struct st{
	int l,r,ind;
}qr[200005];
long long mp[1000005];
long long cur=0,cnt=0;
long long bs,a[200005],k,ans[200005];
bool cmp(st aa,st bb){
	if(aa.l/bs==bb.l/bs){
		return (aa.r/bs<bb.r/bs);
	}
	else{
		return (aa.l/bs<bb.l/bs);
	}
}
void ini(){mp[0]=1;}
void add(long long p){
	cur-=(a[p]*mp[a[p]]*mp[a[p]]);
	mp[a[p]]++;
	cur+=(a[p]*mp[a[p]]*mp[a[p]]);
	
}
void del(long long p){
	cur-=(a[p]*mp[a[p]]*mp[a[p]]);
	mp[a[p]]--;
	cur+=(a[p]*mp[a[p]]*mp[a[p]]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m,i,lft,rit,j;
	cin>>n>>m;
	cur=0;
	bs=sqrtl(n)+1;
	a[0]=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(i=0;i<m;i++){
		cin>>j>>lft;
		qr[i].l=j;
		qr[i].r=lft;
		qr[i].ind=i+1;
	}
	sort(qr,qr+m,cmp);
	lft=0,rit=0;
	for(i=0;i<m;i++){

		int lf=qr[i].l;
		int rt=qr[i].r;
		
		while(rt>rit){
			add(++rit);
		}
		while(lf>lft){
			del(lft++);
		}
		while(lf<lft){
			add(--lft);
		}
		while(rt<rit){
			del(rit--);
		}
		
		ans[qr[i].ind]=cur;
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<"\n";

}
