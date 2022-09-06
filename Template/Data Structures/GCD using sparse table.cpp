#include<bits/stdc++.h>
using namespace std;
long long sparse[100005][30],lg[100005];
long long gcd(long long l,long long r){
	long long ln=r-l+1;
	return __gcd(sparse[l][lg[ln]],sparse[r-(1<<lg[ln])+1][lg[ln]]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,m,i,cur,q,ind,j;
	cin>>n;
	map<long long,long long>mp;
	long long a[n+4];
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	
	lg[1]=0;
	for(i=2;i<=n;i++){
		lg[i]=lg[i/2]+1;
	}
	
	for(i=1;i<=n;i++){
		sparse[i][0]=a[i];
	}
	for(i=1;i<=lg[n];i++){
		for(j=1;j+(1<<(i-1))<=n;j++){
			sparse[j][i]=__gcd(sparse[j][i-1],sparse[j+(1<<(i-1))][i-1]);
		}
	}
	
	cin>>q;
	while(q--){
		long long p,q;
		cin>>p>>q;
		cout<<gcd(p,q)<<endl;
	}
}
