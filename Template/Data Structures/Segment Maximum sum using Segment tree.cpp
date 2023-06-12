struct st{
    long long mx_sum=0,prefix_max=0,suffix_max=0,value=0;
}tree[1200005];
long long a[300005],n,ans=0,d[300005],c[300005],tre[1200005];
map<long long,set<int>>mp;
st merge(st aa,st bb){
    st cc;
   
    cc.mx_sum=max(aa.mx_sum,bb.mx_sum);
    cc.mx_sum=max(cc.mx_sum,aa.suffix_max+bb.prefix_max);
    cc.value=aa.value+bb.value;
    cc.prefix_max=max(aa.prefix_max,aa.value+bb.prefix_max);
    cc.suffix_max=max(bb.suffix_max,aa.suffix_max+bb.value);
    return cc;

}
void initialize(int node,int l,int r){
   
    if(l==r){
        tree[node].mx_sum=a[l];
        tree[node].prefix_max=a[l];
        tree[node].suffix_max=a[l];
        tree[node].value=a[l];
        return;
    }
    int md=(l+r)/2;
    initialize(node*2,l,md);
    initialize(node*2+1,md+1,r);
    tree[node]=merge(tree[node*2],tree[node*2+1]);
   // cout<<node<<"fdfdf "<<tree[node].mx_sum<<" "<<tree[node].value<<endl;

}

st query(int node,int l,int r,int ll,int rr){
    if(l>rr || r<ll)return tree[1200000];

    if(l>=ll && r<=rr)return tree[node];

    int md=(l+r)/2;
    return merge(query(node*2,l,md,ll,rr),query(node*2+1,md+1,r,ll,rr));

}

// end segment treeee
