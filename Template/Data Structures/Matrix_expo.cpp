#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int P = 1e9 + 7;
//template for Matrix expo
struct Matrix {
    vector<vector<ll>> a;
    int n, m;
    Matrix(int _n, int _m) : n(_n), m(_m), a(_n + 1, vector<ll> (_m + 1)){}
};
Matrix operator * (const Matrix &A, const Matrix &B) {
    Matrix C(A.n, B.m);
    for (int i = 0; i < A.n; i++) {
        for (int j = 0; j < A.m; j++) {
            for (int k = 0; k < B.m; k++) {
                C.a[i][k] = (C.a[i][k] + A.a[i][j] * B.a[j][k] % P) % P;
            }
        }
    }
    return C;
}
Matrix power(Matrix a,Matrix b, ll c){
    Matrix ans = a;
    while(c) {
            if(c & 1) ans = ans * b; 
            b = b * b;
            c >>= 1;
     }
     return ans;
}


int main()
{
    long long  n,m,i,j,k,l;
    cin>>n>>m;
    Matrix A(n,n),B(n,n);;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            B.a[i][j]=1;
            A.a[i][j]=0;
            if(i==0)A.a[i][j]=1;
        }
    }

   // A=power(A,A,2);
    long long a[n+2];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
   
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(__builtin_popcountll(a[i]^a[j])%3){
                B.a[i][j]=0;
            }
        }
    }

    if(m==1){
        cout<<n<<"\n";
    }
    else{
        A=power(A,B,m-1);//A*B^(m-1)
        long long ANS=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                ANS+=A.a[i][j];ANS%=P;
            }
        }
        cout<<ANS<<"\n";
    }
}
//sEPOD
