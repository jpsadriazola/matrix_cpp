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
   //explicit Matrix(const std::vector<size_t>& shape_arg);
   Matrix(const Matrix<T,N> & mat);

   Matrix(const std::vector<T> &x, const std::vector<size_t>& shape);

   //TODO: Arithmetic
   template<std::__enable_if_t<std::is_arithmetic<T>::value, bool> =true>
   Matrix <T,N> operator + (const Matrix<T,N> & mat);

   // Indexing
   template <typename... Exts>
   T get(Exts... exts);

   // Getters and Setters
   std::vector<size_t> get_shape() const;
   std::vector<T> get_data() const;


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

/*
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
*/


template<typename T, size_t N>
template<typename... Exts>
T Matrix<T, N>::get(Exts... exts) {

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

template<typename T, size_t N>
Matrix<T, N>::Matrix(const Matrix<T,N> &mat) {
   data = mat.get_data();  // copy
   shape = mat.get_shape(); // copy
}

template<typename T, size_t N>
std::vector<size_t> Matrix<T, N>::get_shape() const {
   return shape;
}

template<typename T, size_t N>
std::vector<T> Matrix<T, N>::get_data() const {
   return data;
}

template<typename T, size_t N>
template<std::__enable_if_t<std::is_arithmetic<T>::value, bool>>
Matrix<T, N> Matrix<T, N>::operator+(const Matrix<T,N> & mat) {
   Matrix mat_res(mat);
   static size_t n_elms;
   static size_t i;
   n_elms = data.size();

   for(i = 0; i < n_elms; i++){
      mat_res.data[i] = data[i] + mat.data[i];
   }
   return mat_res;
}




#endif // CPP_MATRIX2