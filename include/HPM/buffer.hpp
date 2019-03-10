#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <mesh.hpp>

namespace HPM {

  template<typename T> class buffer {
  public:
 
    template<class scalarT, unsigned dim, class elemT> 
      buffer(const mesh<scalarT, dim, elemT>& mesh) : 
        data(mesh.size) 
      {}

    std::vector<T> data;

  };


}

#endif
