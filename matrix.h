#ifndef CPP_MATRIX2
#define CPP_MATRIX2
#include <vector>
#include <iostream>
#include <cassert>
#include <type_traits>

template <typename T, size_t N>
class Matrix{
public:
   static constexpr  size_t order = N;
   // Construction
   explicit Matrix(const std::vector<size_t>& shape_arg);
   Matrix(const std::vector<T> &x, const std::vector<size_t>& shape);

   // TODO: Arithmetic operations
   Matrix & operator+=(const Matrix & x);
   //Matrix & dot_product(const Matrix & x);

   // Indexing
   template <typename... Exts>
   T operator ()(Exts... exts);


private:
   std::vector<size_t> shape;
   std::vector<T> data;
};

template <typename T, size_t N>
Matrix<T, N>::Matrix(const std::vector<T> &x, const std::vector<size_t>& shape_arg)
{
   size_t n_data = x.size();
   size_t n_shape = shape_arg.size();
   assert(n_shape == order);
   size_t n_elms = 1;

   for (size_t i = 0; i < n_shape; i++){
   n_elms = n_elms * shape_arg[i];
   }
   assert(n_elms == n_data);

   data = x;  //copy
   shape = shape_arg;
}

template<typename T, size_t N>
Matrix<T, N>::Matrix(const std::vector<size_t> &shape_arg) {
   size_t n_shape = shape_arg.size();
   size_t n_elms = 1;
   for (size_t i=0; i<n_shape; i++){
      n_elms = n_elms*shape_arg[i];
   }

   shape = shape_arg; // copy
   data = std::vector<T>(n_elms); // copy
}

template<typename T, size_t N>
Matrix<T,N> &Matrix<T, N>::operator+=(const Matrix &x) {

}

template<typename T, size_t N>
template<typename... Exts>
T Matrix<T, N>::operator()(Exts... exts) {

   static_assert(sizeof...(Exts) == N, "");
   size_t args[N] = {size_t(exts)...};
   static size_t index;
   static size_t prod;

   index = args[0];
   prod = 1;
   for(size_t i = 1; i < N; i++){
      prod = prod * shape[i];
      index = index + args[i] * prod;
   }

   return data[index];
}

#endif // CPP_MATRIX2