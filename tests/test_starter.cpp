#define BOOST_TEST_MODULE ip_sort_test_module

#include <boost/test/unit_test.hpp>

#include "../commontypes.h"
#include "../io/ip_inout.h"
#include "../sort/ip_sort.h"


BOOST_AUTO_TEST_SUITE(ip_sort_test_suite)

BOOST_AUTO_TEST_CASE(ip_sort_test_sorting){

    IpVectorsT ip_pool_base{IpVectorT{"222.82_.198.61"},IpVectorT{"222.173.235.246"},IpVectorT{"222.130.177.64"}};

    IpVectorsT ip_pool_sorted_desc{IpVectorT{"222.173.235.246"},IpVectorT{"222.130.177.64"},IpVectorT{"222.82.198.61"}};


    BOOST_CHECK(!std::equal(ip_pool_base.begin(), ip_pool_base.end(), ip_pool_sorted_desc.begin()));
    std::sort(ip_pool_base.begin(),ip_pool_base.end(),lexicographical_desc_vct());
    IpVectorsT ip_pool_working = getUnPrependedVector(ip_pool_base);

    BOOST_CHECK(std::equal(ip_pool_working.begin(), ip_pool_working.end(), ip_pool_sorted_desc.begin()));

//    std::equal()
    // print_vct_out(ip_pool_working);
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
