#define BOOST_TEST_MODULE ip_sort_test_module

#include <boost/test/unit_test.hpp>

#include "../commontypes.h"
#include "../io/ip_inout.h"
#include "../sort/ip_sort.h"


BOOST_AUTO_TEST_SUITE(ip_sort_test_suite)


bool check_vector_of_vector_equal(IpVectorsT& vct1, IpVectorsT& vct2){
    if(vct1.size() == vct2.size()){
        for(uint i = 0; i < vct1.size(); i++){
            if(!std::equal(vct1.at(i).begin(), vct1.at(i).end(),vct2.at(i).begin())){
                std::cout << "missmatcg in elm comparison " <<std::endl;
                print_vct_out(vct1.at(i));
                std::cout << "---------" <<std::endl;
                print_vct_out(vct2.at(i));
                return false;
            }
        };
        return true;
    };
    std::cout << "diff in size " <<std::endl;
    return false;
}

BOOST_AUTO_TEST_CASE(ip_sort_test_sorting){

    IpVectorsT ip_pool_base{IpVectorT{"222.-82.198.-61"},IpVectorT{"222.173.235.246"},IpVectorT{"222.130.177.-64"}};

    IpVectorsT ip_pool_sorted_desc{IpVectorT{"222.173.235.246"},IpVectorT{"222.130.177.-64"},IpVectorT{"222.-82.198.-61"}};

    IpVectorsT ip_pool_sorted_desc_no_helping{IpVectorT{"222.173.235.246"},IpVectorT{"222.130.177.64"},IpVectorT{"222.82.198.61"}};
    // check not equals
    BOOST_CHECK(!check_vector_of_vector_equal(ip_pool_base,ip_pool_sorted_desc));

    std::sort(ip_pool_base.begin(),ip_pool_base.end(),lexicographical_desc_vct());
    // check sorted with helping elements
    BOOST_CHECK(check_vector_of_vector_equal(ip_pool_base,ip_pool_sorted_desc));

    IpVectorsT ip_pool_working  = getUnPrependedVector(ip_pool_base);


    // removed helping elements and sorted
    BOOST_CHECK(check_vector_of_vector_equal(ip_pool_working,ip_pool_sorted_desc_no_helping));

    // 222.173.235.246
    // 222.130.177.64
    // 222.82.198.61
}


BOOST_AUTO_TEST_CASE(ip_sort_test_filter1){
//    BOOST_CHECK(false);
    // print_vct_out(ip_pool_working);
    // 222.173.235.246
    // 222.130.177.64
    // 222.82.198.61
}


BOOST_AUTO_TEST_CASE(ip_sort_test_filter46_70){
//    BOOST_CHECK(false);
    // 46.70.225.39
    // 46.70.147.26
    // 46.70.113.73
    // 46.70.29.76
}


BOOST_AUTO_TEST_CASE(ip_sort_test_filter_any46){
//    BOOST_CHECK(false);
    // print_vct_out(ip_pool_working);
    // 186.204.34.46
    // 186.46.222.194
    // 185.46.87.231
    // 185.46.86.132
    // 185.46.86.131
}

BOOST_AUTO_TEST_SUITE_END()
