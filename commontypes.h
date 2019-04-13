#ifndef COMMONTYPES_H
#define COMMONTYPES_H
#include <string>
#include <vector>


// conventions for types - NameT
using StdStrT    = std::string;

template <typename T>
using StdVectorT = std::vector<T>;

using IpVectorT     = std::vector<StdStrT>;
using IpVectorsT    = std::vector<std::vector<StdStrT>>;

using IntIpVectorT     = std::vector<int>;
using IntIpVectorsT    = std::vector<std::vector<int>>;
//
const char * const CHPNT_FOR_SORT = "-";
const char  CH_FOR_SORT = '-';
const char  CH_IP_DELIM = '.';

#endif // COMMONTYPES_H
