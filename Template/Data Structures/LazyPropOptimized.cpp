#include<bits/stdc++.h>
using namespace std;
int a[200050],N=200029;
struct st{
	int sum,prop;
}tree[800005];

inline void propagate(int node,int l,int r){

	int sz=(r-l+1);
	
	tree[node].sum += (sz * tree[node].prop);

	if(l!=r){
		tree[node*2].prop+=tree[node].prop;
		tree[node*2+1].prop+=tree[node].prop;
	}
	tree[node].prop=0;
}
inline void initialize(int node,int l,int r){
	
	if(l==r){
	
		tree[node].sum=a[l];return;

	}
	int md=(l+r)/2;
	initialize(node*2,l,md);
	initialize(node*2+1,md+1,r);

	tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;


	

}

inline int query(int node,int l,int r,int ll,int rr){
	if(l>r)return 0;
	if(tree[node].prop!=0)propagate(node,l,r);
	if(ll>r || rr<l)return 0;
	if(l>=ll && r<=rr)return tree[node].sum;
	int md=(l+r)/2;

	int ans=0;
	if(l<=md)ans+=query(node*2,l,md,ll,rr);
	if(r>=md)ans+=query(node*2+1,md+1,r,ll,rr);
	return ans;
}

inline void update(int node,int l,int r,int ll,int rr,int value){
	if(l>r)return;
	if(tree[node].prop!=0)propagate(node,l,r);
	if(ll>r || rr<l)return ;
	if(l>=ll && r<=rr){
		tree[node].prop += value;
		propagate(node,l,r);
		return;
	}
	int md=(l+r)/2;
	if(l<=md)update(node*2,l,md,ll,rr,value);
	if(r>=md)update(node*2+1,md+1,r,ll,rr,value);

	tree[node].sum= tree[node*2].sum+tree[node*2+1].sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q,n,m,i,j,k,l,p;
	cin>>n>>q;
	int b[n+2];
	for(i=0;i<=200029;i++){
		a[i]=0;
	}
	for(i=1;i<=n;i++){
		cin>>k;b[i]=k;
		a[k]++;
	}
	for(i=1;i<=200029;i++){
		if(a[i]%2){
			a[i+1]+=(a[i]/2);a[i]=1;
		}
		else {
			a[i+1]+=(a[i]/2);a[i]=0;
		}
	}

	initialize(1,1,N);
	
	

	while(q--){
		int ind,value;
		cin>>ind>>value;

		//remove bit 
		int in = ind;
		ind = b[in];

		int l=ind,r=N,md,ans=-1;
		while(l<=r){
			md=(l+r)/2;

			int sm=query(1,1,N,ind,md);
			if(sm>=1){
				ans=md;
				r=md-1;
			}
			else l=md+1;
		}




		update(1,1,N,ans,ans,-1);
		if(ans!=ind){
			update(1,1,N,ind,ans-1,1);
		}

		
		//add bit

		b[in]=value;
		ind = value;

		
		l=ind,r=N,ans=-1;
		
		while(l<=r){
			md=(l+r)/2;

			int sm=query(1,1,N,ind,md);
			
			if(sm<(md-ind+1)){
				ans=md;
				r=md-1;
			}
			else l=md+1;
		}

		update(1,1,N,ans,ans,1);
		if(ans!=ind){
			update(1,1,N,ind,ans-1,-1);
		}



		



		r=N,l=1,ans=-1;
		while(l<=r){
			md=(l+r)/2;

			int sm=query(1,1,N,md,N);
			if(sm>=1){
				ans=md;
				l=md+1;
			}
			else {
				r=md-1;
			}
			
		}

		cout<<ans<<"\n";


	}


}
