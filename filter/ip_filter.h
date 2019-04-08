#ifndef IP_SORT_FILTER_H
#define IP_SORT_FILTER_H

#include "commontypes.h"
#include "io/ip_inout.h"


// improved version going through only suspected parts of vector
// g returns starting index for searching elements
void applyable_filter_printImproved( bool (*f)(const StdVectorT<StdStrT>& elm ), int (*g)(const IpVectorsT &ips_vct) ,IpVectorsT ip_vct [[gnu::unused]]){
    //TODO create improved version
    int iStartPos = g(ip_vct);
    for(uint i = iStartPos; i < ip_vct.size(); i++){
        if(f(ip_vct.at(i))) print_vct_out(ip_vct.at(i));
    }
}

// not improved version going through all vector
void applyable_filter_print( bool (*f)(const StdVectorT<StdStrT>& elm),IpVectorsT ip_vct){
    for ( auto n : ip_vct ) {
        if(f(n))print_vct_out(n);
    }
}
//


// will produce another vector, applying some function
// returning if all ok in vector
auto applyable_filter( bool (*f)(const StdVectorT<StdStrT>& elm),IpVectorsT ip_vct){
    IpVectorsT ip_product;
    for ( auto n : ip_vct ) {
        if(f(n))ip_product.push_back(n);
    }
    return ip_product;
}

//some filters to work
bool f_byFirst_One(const StdVectorT<StdStrT>& elm){
    if(elm.front().compare("1") == 0){
        return true;
    }
    return false;
}

bool f_byFirst46_Second70(const StdVectorT<StdStrT>& elm){
    if((elm.at(1).compare("46") == 0) && (elm.at(2).compare("70"))){
        return true;
    }
    return false;
}

bool f_byAny46(const StdVectorT<StdStrT>& elm){
    for(auto str: elm){
        if(str.compare("46") == 0)return true;
    }
    return false;
}
//~some filters to work

#endif // IP_SORT_FILTER_H
