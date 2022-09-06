//2D array sum using BIT


#include<bits/stdc++.h>
using namespace std;
long long d[1003][1003],bit[1003][1003],n;
void update(long long a,long long bb){
	while(a<=n){
		long long b=bb;
		while(b<=n){
			bit[a][b]++;
			b+=(b&-b);
		}
		a+=(a&-a);
	}
}
long long query(long long a,long long bb){
	long long ans=0;
	while(a>0){
		long long b=bb;
		while(b>0){
			ans+=bit[a][b];
			b-=(b&-b);
		}a-=(a&-a);
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc,r=0;
	cin>>tc;
	while(tc--){
		cout<<"Case "<<++r<<":\n";
		long long m,i,j,k,a,q,b,aa,bb;
		cin>>q;
		n=1000;
		for(i=0;i<=1000;i++){
			for(j=0;j<=1000;j++){
				bit[i][j]=0;
				d[i][j]=0;
			}
		}
		for(i=0;i<q;i++){
			cin>>k;
			if(k==0){
				cin>>a>>b;
				a++,b++;
				if(d[a][b]==0){
				update(a,b);
				d[a][b]=1;}

			}
			else{
				cin>>a>>b>>aa>>bb;
				a++,b++,aa++,bb++;
				k=query(aa,bb)+query(a-1,b-1)-query(a-1,bb)-query(aa,b-1);
				cout<<k<<"\n";
			}
		}
	} 
}
