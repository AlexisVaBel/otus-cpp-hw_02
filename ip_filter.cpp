#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iostream>

#include "commontypes.h"
#include "ip_sort_filter.h"

auto split(const StdStrT &str, char d)
{
    StdVectorT<StdStrT> r;

    StdStrT::size_type start = 0;
    StdStrT::size_type stop = str.find_first_of(d);
    StdStrT tmp;
    while(stop != StdStrT::npos)
    {
        tmp = str.substr(start, stop - start);
        if(tmp.size() < 3){
            auto addCnt = 3 - tmp.size();
            while(addCnt > 0){
                addCnt--;
                tmp=CH_FOR_SORT+tmp;
            }

        }
        r.push_back(tmp);

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    tmp = str.substr(start);

    if(tmp.size() < 3){
        auto addCnt = 3 - tmp.size();
        while(addCnt > 0){
            addCnt--;
            tmp=CH_FOR_SORT+tmp;
        }

    }
    r.push_back(tmp);

    return r;
}




struct lexicographical_desc_vct{
    inline bool operator() (const StdVectorT<StdStrT>& fst, const StdVectorT<StdStrT>& snd){
        return !(std::lexicographical_compare(fst.begin(),fst.end(),snd.begin(),snd.end()));
    }
};


void print_vct_out(IpVectorT ip_pool){
    for(IpVectorT::const_iterator ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

int main(int argc [[gnu::unused]], char const *argv[] ){
    try
    {
        IpVectorT ip_pool; // already contains vector of elements


        for(StdStrT line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }

        std::sort(ip_pool.begin(),ip_pool.end(),lexicographical_desc_vct()); // some lexicographical desc. sorting

    // TODO reverse lexicographically sort        
        auto byFirst = applyable_filter(f_byFirst_One, ip_pool);
        auto by46And70 = applyable_filter(f_byFirst46_Second70, ip_pool);
	//
	// just  printing vector out
        print_vct_out(ip_pool);
        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)
        print_vct_out(byFirst);

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)
//        print_vct_out(by46And70);
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
        // ip = filter_any(46)

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

