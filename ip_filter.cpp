#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iostream>

#include "commontypes.h"
// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]





auto split(const StdStrT &str, char d)
{
    StdVectorT<StdStrT> r;

    StdStrT::size_type start = 0;
    StdStrT::size_type stop = str.find_first_of(d);

    while(stop != StdStrT::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

//some filters to work
bool f_byFirst(const StdVectorT<StdStrT>& elm){
    std::cout << "byFirst applying"<< *elm.begin()<<std::endl;
    return true;
}
//~some filters to work

// will produce another vector, applying some function
// returning if all ok in vector
auto applyable_filter(std::function<bool (const StdVectorT<StdStrT>& elm)> f,IpVectorT ip_vct){
    IpVectorT ip_product;

    for(IpVectorT::const_iterator ip = ip_vct.cbegin(); ip != ip_vct.cend(); ++ip){
        f(*ip->begin());

    }
    return ip_product;
};
//auto filter_vector();

struct lexicographical_desc{
    inline bool operator() (const StdVectorT<StdStrT>& fst, const StdVectorT<StdStrT>& snd){
        // all vector to compare
        return !(std::lexicographical_compare(fst.begin(),fst.end(),snd.begin(),snd.end()));
    }
};

int main(int argc [[gnu::unused]], char const *argv[] ){
    try
    {
        IpVectorT ip_pool; // already contains vector of elements

        for(StdStrT line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        };

        std::sort(ip_pool.begin(),ip_pool.end(),lexicographical_desc()); // some lexicographical desc. sorting


    // TODO reverse lexicographically sort
        std::function<bool (const StdVectorT<StdStrT>& elm)> func_by1 = f_byFirst;
        applyable_filter(func_by1, ip_pool);

	//

	// just  printing vector out
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

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        // ip = filter(1)

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
        // ip = filter(46, 70)

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
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
