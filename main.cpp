#include <cassert>
#include <cstdlib>

#include <iostream>
#include <cstring>

#include "commontypes.h"

#include "io/ip_inout.h"
#include "sort/ip_sort.h"
#include "filter/ip_filter.h"



int main(int argc , char const *argv[] ){
    try    {
        //ip pool for lexicographical sort
        // TODO reverse lexicographically sort
        IpVectorsT ip_pool_base;
        for(StdStrT line; std::getline(std::cin, line);){
            auto v = split(line, '\t');
            ip_pool_base.push_back(split(v.at(0), CH_IP_DELIM));
        }        
        std::sort(ip_pool_base.begin(),ip_pool_base.end(),lexicographical_desc_vct()); // some lexicographical desc. sorting
        //~ip pool for lexicographical sort

        //representative ip pool
        IpVectorsT ip_pool_working = getUnPrependedVector(ip_pool_base);

        print_vct_of_vcts_out(ip_pool_working);
        //~representative ip pool

        // TODO filter by first byte and output        
        applyable_filter_print(f_byFirst_One       , ip_pool_working);
        applyable_filter_print(f_byFirst46_Second70, ip_pool_working);
        applyable_filter_print(f_byAny46           , ip_pool_working);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

