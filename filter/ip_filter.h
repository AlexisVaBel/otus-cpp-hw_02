#ifndef IP_FILTER_H
#define IP_FILTER_H

//TODO a lot of same code, need to reduce,
//have not enough time (
template <typename ... inArgs>
IntIpVectorsT get_ip_filter_first(IntIpVectorsT &vctIn, inArgs ...inVals){
    IntIpVectorsT vct;
    const int size = sizeof...(inVals);
    if(size == 0) return vct;
    int arrInVals[size] = {inVals...};
    bool bAppend = true;
    for(IntIpVectorsT::const_iterator it = vctIn.cbegin(); it != vctIn.cend(); ++it){
        bAppend = true;        
        for(int i=0; i < size; ++i){
            // vector size is less than size of args
            if(((*it).size() < size) || arrInVals[i] != (*it).at(i)){
                bAppend = false;
                break;
            }
        }

        if(bAppend) vct.push_back(*it);
    }
    return vct;
}

// can use a lot of any, or none
template <typename ... inArgs>
IntIpVectorsT get_ip_filter_any(IntIpVectorsT &vctIn, inArgs ...inVals){
    IntIpVectorsT vct;
    const int size = sizeof...(inVals);
    if(size == 0) return vct;
    int arrInVals[size] = {inVals...};
    bool bAppend = true;
    for(IntIpVectorsT::const_iterator it = vctIn.cbegin(); it != vctIn.cend(); ++it){
        bAppend = true;
        for(int i=0; i < size; ++i){
            if (std::find((*it).begin(), (*it).end(), arrInVals[i]) == (*it).end()){
                bAppend = false;
                break;
            }
        }
        if(bAppend) vct.push_back(*it);
    }
    return vct;
}

#endif // IP_FILTER_H
