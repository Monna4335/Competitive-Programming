#include<bits/stdc++.h>
using namespace std;
vector<long long>v[500005],in(500005),out(500005);
int tim=0;
void dfs(int ind,int par){
    in[ind]=++tim;
    for(auto t:v[ind]){
        if(t!=par){
            dfs(t,ind);
        }
    }
    out[ind]=tim;

}
struct st{
        int prop,val;
};
struct Segtree{
    vector<int>tree_prop;
    vector<int>tree_val;
    Segtree(){
        tree_val.resize(2000005,0);
        tree_prop.resize(2000005,0);
    }
    void initialize(int node,int l,int r){
        if(l==r){
            tree_prop[node]=0;return;
        }
        int md=(l+r)/2;
        initialize(node*2,l,md);
        initialize(node*2+1,md+1,r);
    }
    void propagate(int node,int l,int r){
        tree_val[node]=max(tree_val[node],tree_prop[node]);
        if(l!=r){
            tree_prop[node*2]=max(tree_prop[node],tree_prop[node*2]);
            tree_prop[node*2+1]=max(tree_prop[node],tree_prop[node*2+1]);
        }
        tree_prop[node]=0;
    }
    void update(int node,int l,int r,int ll,int rr,int value){
         propagate(node,l,r);
        if(l>rr || r<ll)return;
        if(l>=ll && r<=rr){
           tree_prop[node]=value;
            propagate(node,l,r);return;

        }
        int md=(l+r)/2;
        update(node*2,l,md,ll,rr,value);
        update(node*2+1,md+1,r,ll,rr,value);
         propagate(node,l,r);
        tree_val[node]=max(tree_val[node*2],tree_val[node*2+1]);
      
    }

    int query(int node,int l,int r,int ll,int rr){
        propagate(node,l,r);
        if(l>rr || r<ll)return -10;
        if(l>=ll && r<=rr){
            return tree_val[node];

        }
        int md=(l+r)/2;
        return max(query(node*2,l,md,ll,rr),query(node*2+1,md+1,r,ll,rr));

    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m,i,j,k,l,p;
    cin>>n;
    for(i=1;i<n;i++){
        cin>>k>>l;
        v[k].push_back(l);
        v[l].push_back(k);
    }

    dfs(1,-1);

    Segtree pre,post;
    pre.initialize(1,1,tim);
    post.initialize(1,1,tim);

    long long cur=0,q,typ;
    cin>>q;
    while(q--){
        cur++;
        cin>>typ>>k;
        if(typ==1){
            post.update(1,1,tim,in[k],out[k],cur);
        }
        else if(typ==2){
            pre.update(1,1,tim,in[k],in[k],cur);
        }
        else{
            long long aa=post.query(1,1,tim,in[k],in[k]);
            long long bb=pre.query(1,1,tim,in[k],out[k]);
          
            if(aa>bb){
                cout<<1<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
    }




}
