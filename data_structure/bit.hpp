#ifndef O_O
#include "../template.hpp"
#endif

#ifndef BIT_HPP
#define BIT_HPP

struct bit{
    
    int n;
    vector<long long> v;

    bit(int _n):n(_n), v(_n+10){}

    void update(int id, int x){
        for(int i=id; i<=n; i+=(i&(-i))){
            v[i]+=x;
        }
    }

    long long query(int id){
        long long sum=0;
        for(int i=id; i>0; i-=(i&(-i))){
            sum+=v[i];
        }
        return sum;
    }

};
#endif