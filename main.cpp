//#include <iostream>
#include "matrix.h"


int main(){
   // Construction from vectors
   // Matrix A
   std::vector<double> arr_a = {2.3,5.,2345.,3., 1., 5., 7., 19.};
   std::vector<size_t> shape_a = {2,2,2};
   Matrix <double, 3> A(arr_a, shape_a);
   // Matrix B
   std::vector<double> arr_b = {4.5,10.,25.,31., 16., 15., 7., 19.};
   std::vector<size_t> shape_b = {2,2,2};
   Matrix <double, 3> B(arr_b, shape_b);

   // Construction from matrix
   Matrix <double,  3> C(A);

   // Construction from addition
   Matrix <double, 3> D = A + B;

   // Indexing
   std::cout << D.get(0,0,0) << std::endl;
   std::cout << A.get(0,0,0) << std::endl;
   std::cout << B.get(0,0,0) << std::endl;

	return 0;
}

