#pragma once

#include<bits/stdc++.h>
#define ll long long
using namespace std;

//fenwick tree, bit
struct ftree{
    int n;
    int* bit;
    ftree(int size){
        n=size;
        bit= new int[n+1];
        fill_n(bit,n+1,0);
    }
    void update(int x, int val){
        while(x<=n){
            bit[x]+=val;
            x+=x&(-x);
        }
    }
    ll get_sum(int l, int r){
        ll res=0;
        while(r>0){
            res+=(ll) bit[r];
            r-=r&(-r);
        }
        l--;
        while(l>0){
            res-=(ll) bit[l];
            l-=l&(-l);
        }
        return res;
    }
};
