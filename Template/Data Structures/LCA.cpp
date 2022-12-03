#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long>>v[200005];
long long par[200005][23],in_time[200005],out_time[200005],timm=1,vis[200005];
void dfs(int ind,int parr){
	vis[ind]=true;
	in_time[ind]=timm++;
	par[ind][0]=parr;
	for(auto t:v[ind]){
		if(vis[t.first]==false){
			dfs(t.first,ind);
		}
	}
	for(int i=1;i<=20;i++){
		par[ind][i]=par[par[ind][i-1]][i-1];
	}
	out_time[ind]=timm++;
}
bool is_an(long long u,long long v){
	return (in_time[u]<=in_time[v] && out_time[u]>=out_time[v]);
}
long long ancestor(long long u,long long v){
	if(is_an(u,v)){
		return u;
	}
	if(is_an(v,u))return v;
	for(int i=20;i>=0;i--){
		if(is_an(par[u][i],v)==0){
			u=par[u][i];
		}
	}
	return par[u][0];
}

int main()
{
	int tc,r=0;
	cin>>tc;
	while(tc--){
		cout<<"Case "<<++r<<": ";
		long long n,m,i,j,a,b,c,k,l;
		cin>>n;
		for(i=1;i<n;i++){
			cin>>a>>b>>c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		in_time[0]=0;
		dfs(1,0);
		out_time[0]=timm+10;
		cout<<ancestor(4,8)<<"\n";
	}
}
