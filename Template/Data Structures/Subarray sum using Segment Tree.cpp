#include<bits/stdc++.h>
using namespace std;
long long tree[300004],a[200005];
void initialize(int node,int l,int r){
	if(l==r){
		tree[node]=a[l];
		return;
	}
	int mid=(l+r)/2;
	initialize(node*2,l,mid);
	initialize(node*2+1,mid+1,r);
	tree[node]=tree[node*2]+tree[node*2+1];
	return;
}
void update(int node,int l,int r,int ind,int value){
	if(l>ind || r<ind)return;
	if(l==ind && r==ind){
		tree[node]+=value;
		return;
	}
	int mid=(l+r)/2;
	update(node*2,l,mid,ind,value);
	update(node*2+1,mid+1,r,ind,value);
	tree[node]=tree[node*2]+tree[node*2+1];
}
long long query(int node,int l,int r,int lef,int rig){
	if(l>rig || r<lef)return 0;
	if(lef<=l && r<=rig){
		return tree[node];
	}
	int mid=(l+r)/2;
	return query(node*2,l,mid,lef,rig)+query(node*2+1,mid+1,r,lef,rig);
}
int main()
{
	long long n,i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	initialize(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<query(1,1,n,l,r)<<endl;
	}

}
