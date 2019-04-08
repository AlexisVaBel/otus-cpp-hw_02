#ifndef IP_SORT_H
#define IP_SORT_H

#include "../commontypes.h"

struct lexicographical_desc_vct{
    inline bool operator() (const IpVectorT& fst, const IpVectorT& snd){
        return !(std::lexicographical_compare(fst.begin(),fst.end(),snd.begin(),snd.end()));
    }
};


#endif // IP_SORT_H
