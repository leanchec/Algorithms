#ifndef O_O
#include "../template.hpp"
#endif

#ifndef BIT_HPP
#include "../data_structure/bit.hpp"
#endif

int main(){
    int n;
    n=5;
    bit Bit(n);

    vector<array<int, 3>> queries;
    queries.push_back({1, 1, 1});
    queries.push_back({1, 2, 2});
    queries.push_back({1, 3, 3});
    queries.push_back({1, 4, 4});
    queries.push_back({1, 5, 5});

    queries.push_back({2, 1, 1});
    queries.push_back({2, 1, 2});
    queries.push_back({2, 1, 3});
    queries.push_back({2, 1, 4});
    queries.push_back({2, 1, 5});

    vector<long long> ans;
    ans.push_back(-1);
    ans.push_back(-1);
    ans.push_back(-1);
    ans.push_back(-1);
    ans.push_back(-1);

    ans.push_back(1);
    ans.push_back(3);
    ans.push_back(6);
    ans.push_back(10);
    ans.push_back(15);

    for(int i=0; i<10; i++){
        auto cur = queries[i];
        int type;
        type = cur[0];

        if(type==1){
            int id, x;
            id = cur[1];
            x = cur[2];
            Bit.update(id, x);
        }
        else{
            int l, r;
            l = cur[1];
            r = cur[2];
            long long query_ans = Bit.query(r)-Bit.query(l-1);

            assert(query_ans == ans[i]);
        }
    }

    cout << "passed all tests\n";
}