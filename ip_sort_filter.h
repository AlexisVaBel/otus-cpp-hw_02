#ifndef IP_SORT_FILTER_H
#define IP_SORT_FILTER_H

#include "commontypes.h"


// will produce another vector, applying some function
// returning if all ok in vector
auto applyable_filter( bool (*f)(const StdVectorT<StdStrT>& elm),IpVectorT ip_vct){
    IpVectorT ip_product;
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
    if((elm.front().compare("46") == 0) && (elm.at(2).compare("70"))){
        return true;
    }
    return false;
}
//~some filters to work

#endif // IP_SORT_FILTER_H
