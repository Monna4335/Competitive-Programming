#include<bits/stdc++.h>
using namespace std;
long long a[200005];
struct trt
{
	long long l,prop;
}tree[400005];
void propagate(int node,int l,int r){
	//propage value to the next child and add to the current child
	int val=tree[node].prop,number=r-l+1;
	tree[node].l+=val*number;
	if(l!=r){
		tree[node*2].prop+=val;
		tree[node*2+1].prop+=val;
	}
	tree[node].prop=0;
}
void initialize(int node,int l,int r){
	propagate(node,l,r);
	if(l==r){
		tree[node].l=a[l];
		return;
	}
	int mid=(l+r)/2;
	initialize(node*2,l,mid);
	initialize(node*2+1,mid+1,r);
	tree[node].l=tree[node*2].l+tree[node*2+1].l;
	return;
}
void update(int node,int l,int r,int ind,int ind2,int value){
	propagate(node,l,r);
	if(l>ind2 || ind>r)return;

	if(l>=ind && r<=ind2){
		tree[node].prop+=value;
		propagate(node,l,r);
		
		return;
	}
	int mid=(l+r)/2;
	update(node*2,l,mid,ind,ind2,value);
	update(node*2+1,mid+1,r,ind,ind2,value);
	tree[node].l=tree[node*2].l+tree[node*2+1].l;
}
long long query(int node,int l,int r,int lef,int rig){
	propagate(node,l,r);
	if(l>rig || r<lef)return 0;
	if(lef<=l && r<=rig){
		return tree[node].l;
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
		int type;
		cin>>type;
		if(type==1)
		cout<<query(1,1,n,l,r)<<endl;
		else update(1,1,n,l,r,type);
	}

}
