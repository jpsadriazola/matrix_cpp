//#include <iostream>
#include "matrix.h"



int main(){
   // Construction from vectors
   std::vector<double> arr = {2.3,5.,2345.,3., 1., 5., 7., 19.};
   std::vector<size_t> shape = {2,2,2};

   Matrix <double, 3> mat(arr, shape);

   // Indexing
   std::cout << mat(1,1,1) << std::endl;

	return 0;
}

