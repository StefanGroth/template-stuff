#ifndef MESH_H
#define MESH_H

namespace HPM {

  template<class scalarT, unsigned dim, class elemT> 
    class mesh {
  public:

    mesh(int size) : size(size) {}
    const int size;

  };

}

#endif /** MESH_H */
