#include <cassert>
#include <cstdlib>
#include <iostream>

#include "io_filter.h"



IpVectorT split(const std::string &str, char d){
    IpVectorT r;

    StdStrT::size_type start = 0;
    StdStrT::size_type stop = str.find_first_of(d);
    while(stop != StdStrT::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}



IntIpVectorT splitToInts(const std::string &str, char d){
    IntIpVectorT r;

    StdStrT::size_type start = 0;
    StdStrT::size_type stop = str.find_first_of(d);
    while(stop != StdStrT::npos)
    {
        r.push_back(std::stoi(str.substr(start, stop - start)));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(std::stoi(str.substr(start)));

    return r;
}



IntIpVectorsT load_IntIpVectorT_stdin(){
    IntIpVectorsT r;
    for(std::string line; std::getline(std::cin, line);){
        std::vector<std::string> v = split(line, '\t');
        r.push_back(splitToInts(v.at(0), '.'));
    }
    return r;
}


IpVectorsT load_IpVectorT_stdin(){
    IpVectorsT r;
    for(std::string line; std::getline(std::cin, line);){
        std::vector<std::string> v = split(line, '\t');
        r.push_back(split(v.at(0), '.'));
    }
    return r;
}

