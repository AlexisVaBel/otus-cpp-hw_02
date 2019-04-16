#ifndef COMMONTYPES_H
#define COMMONTYPES_H
#include <string>
#include <vector>


// conventions for types - NameT

//using StdStrT = std::string;
// got some error with 'using'
typedef std::string StdStrT;


typedef  std::vector<StdStrT> IpVectorT;


typedef std::vector<int>  IntIpVectorT;
typedef std::vector<std::vector<int> > IntIpVectorsT;
//

#endif // COMMONTYPES_H
