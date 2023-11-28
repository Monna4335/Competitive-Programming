vector<long long>M,B;
int point=0;
bool bad(long long f1,long long f2,long long f3){
    
    return ((1.0*(B[f3]-B[f1])*(M[f1]-M[f2]))<(1.0*(B[f2]-B[f1])*(M[f1]-M[f3])));
}
void add(long long m,long long b){
    M.push_back(m);
    B.push_back(b);
 
    while(M.size()>=3 && bad(M.size()-3,M.size()-2,M.size()-1)){
        M.erase(M.end()-2);
        B.erase(B.end()-2);
    }
}
long long f(long long p,long long x){
    return M[p]*x+B[p];
}
long long query(long long x){
    if(point>=M.size()){
        point=M.size()-1;
    }
    while(point+1<M.size() && f(point,x)>f(point+1,x)){
        point++;
    }
    return f(point,x);
}
