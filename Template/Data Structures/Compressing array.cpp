#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc,r=0;
	cin>>tc;
	while(tc--){
		long long n,i,j,k,q,l;
		cin>>n>>q;
		long long a[n+3],b[n+3],c[q+4];
		set<long long>s;
		map<long long,long long>mp;
		for(i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			s.insert(a[i]);
			s.insert(b[i]);
		}
		for(i=1;i<=q;i++){
			cin>>c[i];
			s.insert(c[i]);
		}
		k=1;
		for(auto t:s){
			mp[t]=k;
			k++;
		}
		for(i=1;i<=n;i++){
			a[i]=mp[a[i]];
			b[i]=mp[b[i]];
		}
		for(i=1;i<=q;i++){
			c[i]=mp[c[i]];
		}

	}
}
