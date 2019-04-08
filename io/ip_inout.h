#ifndef IP_INOUT_H
#define IP_INOUT_H

#include "../commontypes.h"
#include <iostream>
#include <algorithm>

// prepend character is used for simple - solution
// lexicographical sort in vector of strings view
inline StdStrT prependStr(StdStrT prepStr,StdStrT str){
    if(str.size() < 3){
        auto addCnt = 3 - str.size();
        while(addCnt > 0){
            addCnt--;
            str=prepStr+str;
        }
    }
    return str;
}

auto split(const StdStrT &str, char d){
    StdVectorT<StdStrT> r;
    StdStrT::size_type start = 0;
    StdStrT::size_type stop = str.find_first_of(d);
    StdStrT tmp;
    while(stop != StdStrT::npos)
    {
        tmp = prependStr(CHPNT_FOR_SORT,str.substr(start, stop - start));
        r.push_back(tmp);
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    tmp = prependStr(CHPNT_FOR_SORT,str.substr(start));
    r.push_back(tmp);
    return r;
}
//~lexicographical sort in vector of strings view
auto getUnPrependedVector(IpVectorsT ip_pool){
    IpVectorsT ip_unprepended;
    for (auto vctStrs: ip_pool) {
        IpVectorT vctTmp;
        for(auto strs: vctStrs){
            strs.erase(std::remove_if(strs.begin(),
                                          strs.end(),
                                          [](unsigned char x){return (x) == CH_FOR_SORT;}),strs.end());
            vctTmp.push_back(strs);
        }
        ip_unprepended.push_back(vctTmp);
    }

    return ip_unprepended;
}




void print_vct_of_vcts_out(IpVectorsT ip_pool){
    for(IpVectorsT::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip){
        for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part){
            if (ip_part != ip->cbegin()){
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}


void print_vct_out(StdVectorT<StdStrT> ip_pool){
    for(StdVectorT<StdStrT>::const_iterator ip_part = ip_pool.cbegin(); ip_part != ip_pool.cend(); ++ip_part){
        if (ip_part != ip_pool.cbegin()){
            std::cout << ".";

        };
        std::cout << *ip_part;
    };
    std::cout << std::endl;
}

#endif // IP_INOUT_H
