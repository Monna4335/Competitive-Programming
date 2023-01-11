#include<bits/stdc++.h>
using namespace std;
vector<int>root,v[500005];
vector<pair<int,int>>query[500005];
int a[500005],mxx=-1,depth=-1,num=0,bigg[500005],freq[500004],n,ans[500005],dis[500005],siz[500005],big[500005];
int mop[500005][27],nope[500005];
string s;
void sizedfs(int x,int p){
	siz[x]=1;
	int mx=-1;
	big[x]=-1;
	for(auto t:v[x]){
		if(t!=p){
			dis[t]=dis[x]+1;
			sizedfs(t,x);
			siz[x]+=siz[t];
			if(siz[t]>mx){
				mx=siz[t];
				big[x]=t;
			}
		}
	}
	
}
void add(int ind,int par,int k)
{
	//Do calculation
	for(auto t:v[ind]){
		if(t==par || bigg[t])continue;

			add(t,ind,k);
		

	}
	

	
}
void dfs_dsu(int ind,int par,int keep){
	int bigChild=-1,mx=-1;
	//cout<<ind<<" "<<par<<" "<<keep<<endl;
	for(auto t:v[ind]){
		if(t!=par && t!=big[ind]){
			dfs_dsu(t,ind,0);
		}
	}
	if(big[ind]!=-1){
		dfs_dsu(big[ind],ind,1);
		bigg[big[ind]]=1;
	}
	add(ind,par,1);
	
//Do calculation
	if(big[ind]!=-1){
		bigg[big[ind]]=0;
	}
	if(keep==0){
		add(ind,par,-1);
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m,k,i,l,p;
	cin>>n>>m;
	for(i=2;i<=n;i++){
		cin>>k;
		v[k].push_back(i);
		v[i].push_back(k);
	}
	cin>>s;
	s='3'+s;
	for(i=1;i<=m;i++){
		cin>>p>>l;
		query[p].push_back({l,i});
	}
	sizedfs(1,-1);
	dfs_dsu(1,-1,1);
	for(i=1;i<=m;i++){
		if(nope[i]==0)cout<<"Yes\n";
		else cout<<"No\n";
	}
}
