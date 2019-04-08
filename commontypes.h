#ifndef COMMONTYPES_H
#define COMMONTYPES_H
#include <string>
#include <vector>
#include <tuple>


// conventions for types - NameT
using StdStrT    = std::string;

template <typename T>
using StdVectorT = std::vector<T>;

using IpVectorT     = std::vector<StdStrT>;
using IpVectorsT    = std::vector<std::vector<StdStrT>>;

//
const char * CHPNT_FOR_SORT = "-";
const char  CH_FOR_SORT = '-';
const char  CH_IP_DELIM = '.';

#endif // COMMONTYPES_H
