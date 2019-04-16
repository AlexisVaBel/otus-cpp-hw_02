#ifndef IO_FILTER_H
#define IO_FILTER_H
#include "../commontypes.h"

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

IntIpVectorsT   load_IntIpVectorT_stdin();

void print_vct(IntIpVectorT vct);

#endif
