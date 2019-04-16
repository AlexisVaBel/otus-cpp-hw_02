#include <cassert>
#include <algorithm>
#include <cstdarg>
#include <iostream>

#include "commontypes.h"

#include "io/ip_io.h"
#include "filter/ip_filter.h"



int main(int argc , char const *argv[] ){
    try{
        // TODO reverse lexicographically sort
        IntIpVectorsT ip_pool = load_IntIpVectorT_stdin();
        std::sort(ip_pool.begin(), ip_pool.end(), std::greater<IntIpVectorT> () );

        IntIpVectorsT ip_poolOnes   = get_ip_filter_first(ip_pool,1);
        IntIpVectorsT ip_pool46_70  = get_ip_filter_first(ip_pool,46,70);
        IntIpVectorsT ip_pool_any46 = get_ip_filter_any(ip_pool,46);



        std::for_each(ip_pool.begin(), ip_pool.end(), print_vct);
        std::for_each(ip_poolOnes.begin(), ip_poolOnes.end(), print_vct);
        std::for_each(ip_pool46_70.begin(), ip_pool46_70.end(), print_vct);
        std::for_each(ip_pool_any46.begin(), ip_pool_any46.end(), print_vct);

    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

