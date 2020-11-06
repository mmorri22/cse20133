#include "LIS.h"

template<class T>
long unsigned int getLIS( const std::vector< T >& theVec );


template<class T>
void FindAndUpdateElement( std::vector< T >& LIS_Vec, T searchVal  );