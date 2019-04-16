#define BOOST_TEST_MODULE ip_sort_test_module

#include <iostream>
#include <boost/test/unit_test.hpp>


#include "../commontypes.h"
#include "../io/ip_io.h"
#include "../filter/ip_filter.h"


BOOST_AUTO_TEST_SUITE(ip_sort_test_suite)


bool check_vector_of_vector_equal(IntIpVectorsT& vct1, IntIpVectorsT& vct2){
    if(vct1.size() == vct2.size()){
        for(uint i = 0; i < vct1.size(); i++){
            if(!std::equal(vct1.at(i).begin(), vct1.at(i).end(),vct2.at(i).begin())){
                std::cout << "missmatcg in elm comparison " <<std::endl;
                std::cout << "---------" <<std::endl;
                return false;
            }
        };
        return true;
    };
    std::cout << "diff in size " <<std::endl;
    return false;
}

BOOST_AUTO_TEST_CASE(ip_sort_test_sorting){

    IntIpVectorsT ip_pool_base         {IntIpVectorT{222, 82, 198, 46},     IntIpVectorT{222, 173, 235, 246},   IntIpVectorT{222, 130, 177, 64},IntIpVectorT{222, 131, 177, 65}};
    IntIpVectorsT ip_pool_sorted_desc  {IntIpVectorT{222, 173, 235, 246},   IntIpVectorT{222, 131, 177, 65},    IntIpVectorT{222, 130, 177, 64},IntIpVectorT{222, 82, 198, 46}};

//    // check not equals
    std::cout << "Check missmatch vectors of vectors"<< std::endl;
    BOOST_CHECK(!check_vector_of_vector_equal(ip_pool_base,ip_pool_sorted_desc));

    std::sort(ip_pool_base.begin(), ip_pool_base.end(), std::greater<IntIpVectorT> () );
//    // check sorted with helping elements
    std::cout << "Check match vectors of vectors"<< std::endl;
    BOOST_CHECK(check_vector_of_vector_equal(ip_pool_base,ip_pool_sorted_desc));
}


BOOST_AUTO_TEST_CASE(ip_sort_test_filter1){    
    IntIpVectorsT ip_pool_sorted_desc  {IntIpVectorT{222, 173, 235, 246},   IntIpVectorT{1, 131, 177, 65},    IntIpVectorT{1, 130, 177, 64},IntIpVectorT{1, 82, 198, 46}};
    IntIpVectorsT ip_pool_filtered  {IntIpVectorT{1, 131, 177, 65},    IntIpVectorT{1, 130, 177, 64},IntIpVectorT{1, 82, 198, 46}};
    IntIpVectorsT ip_poolOnes   = get_ip_filter_first(ip_pool_sorted_desc,1);
    std::cout << "Check filtered ones"<< std::endl;
    BOOST_CHECK(check_vector_of_vector_equal(ip_pool_filtered,ip_poolOnes));

}


BOOST_AUTO_TEST_CASE(ip_sort_test_filter46_70){
    IntIpVectorsT ip_pool_sorted_desc  {IntIpVectorT{222, 173, 235, 246},   IntIpVectorT{46, 131, 177, 65},    IntIpVectorT{46, 70, 177, 64},IntIpVectorT{46, 70, 168, 46},IntIpVectorT{46, 70, 145, 46}};
    IntIpVectorsT ip_pool_filtered  {IntIpVectorT{46, 70, 177, 64},IntIpVectorT{46, 70, 168, 46},IntIpVectorT{46, 70, 145, 46}};
    IntIpVectorsT ip_pool_46_70   = get_ip_filter_first(ip_pool_sorted_desc,46,70);
    std::cout << "Check filtered 46 and 70"<< std::endl;
    BOOST_CHECK(check_vector_of_vector_equal(ip_pool_filtered,ip_pool_46_70));
}


BOOST_AUTO_TEST_CASE(ip_sort_test_filter_any46){
    IntIpVectorsT ip_pool_sorted_desc  {IntIpVectorT{222, 173, 235, 246},   IntIpVectorT{46, 131, 177, 65},    IntIpVectorT{46, 70, 177, 64},IntIpVectorT{46, 70, 168, 46},IntIpVectorT{46, 70, 145, 46}};
    IntIpVectorsT ip_pool_filtered  {IntIpVectorT{46, 131, 177, 65}, IntIpVectorT{46, 70, 177, 64},IntIpVectorT{46, 70, 168, 46},IntIpVectorT{46, 70, 145, 46}};
    IntIpVectorsT ip_pool_46_any   = get_ip_filter_any(ip_pool_sorted_desc,46);
    std::cout << "Check filtered any 46"<< std::endl;
    BOOST_CHECK(check_vector_of_vector_equal(ip_pool_filtered,ip_pool_46_any));
}

BOOST_AUTO_TEST_SUITE_END()
