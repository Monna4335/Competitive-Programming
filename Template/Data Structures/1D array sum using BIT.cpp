#include<bits/stdc++.h>
using namespace std;
long long bit[2000004],n,mod=1000000007;
void update(long long x,long long val){
	
	while(x<=n){
		bit[x]+=val;
		bit[x]%=mod;
		x+=(x&-x);
	}
}
long long query(long long x){
	long long ans=0;
	while(x>0){
		ans+=bit[x];
		ans%=mod;
		x-=(x&-x);
	}
	return ans;
}
long long sumquery(long long a,long long b){
	return query(b)-query(a-1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc,r=0;
	cin>>tc;
	while(tc--){
		cout<<"Case "<<++r<<": ";
		long long i,j,k,ans=0;
		cin>>n;
		long long a[n+3];
		
		for(i=0;i<n;i++){
			cin>>a[i];
			
		}
		
		for(i=0;i<n;i++){
			update(i+1,a[i]);

		}
		int qu;
		cin>>qu;
		while(qu--){
			cin>>j>>k;
			cout<<sumquery(j,k)<<endl;
		}
		
	}
}
