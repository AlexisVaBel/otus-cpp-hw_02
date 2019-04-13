#include <cassert>
#include <cstdlib>
#include <algorithm>

#include <iostream>

#include "io/io_filter.h"
#include "commontypes.h"

// from documentation:
//The less-than comparison (operator<) behaves as if using algorithm lexicographical_compare, which compares the elements
// so we can use both
// <> or (std::lexicographical_compare(fst.begin(),fst.end(),snd.begin(),snd.end()));
struct lexicographical_desc_vct{
    inline bool operator() (const IntIpVectorT& fst, const IntIpVectorT& snd){
        return fst > snd;
    }
};
//

int main(int argc , char const *argv[] ){
    try{
        // TODO reverse lexicographically sort
        IntIpVectorsT ip_pool = load_IntIpVectorT_stdin();
        std::sort(ip_pool.begin(), ip_pool.end(), lexicographical_desc_vct() );

        // print with '.' delimiter, to be captured with lambda
        auto print_vct_with_delimiter = [](IntIpVectorT vct){
            for(IntIpVectorT::const_iterator it = vct.cbegin(); it != vct.cend(); ++it){
                if(it != vct.cbegin()) std::cout << ".";
                std::cout << *it;
            }
            std::cout<< std::endl;
        };
        //~ print with '.' delimiter, to be captured with lambda

        auto print_vct_any_is_46        = [=](IntIpVectorT vct){if( std::find(vct.begin(), vct.end(), 46) != vct.end() ) print_vct_with_delimiter(vct);};
        auto print_vct_first_is_one     = [=](IntIpVectorT vct){if( vct.at(0) == 1 ) print_vct_with_delimiter(vct);};
        auto print_vct_first_46_next_70 = [=](IntIpVectorT vct){if( vct.at(0) == 46 && vct.at(1) == 70 ) print_vct_with_delimiter(vct);};

        std::for_each(ip_pool.begin(), ip_pool.end(), print_vct_with_delimiter);
        std::for_each(ip_pool.begin(), ip_pool.end(), print_vct_first_is_one);
        std::for_each(ip_pool.begin(), ip_pool.end(), print_vct_first_46_next_70);
        std::for_each(ip_pool.begin(), ip_pool.end(), print_vct_any_is_46);
    }
    catch(const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

