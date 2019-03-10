#ifndef FOREACH_H
#define FOREACH_H

namespace HPM {

  template<class DataAccessList, class MeshDT, typename LoopBody> 
  void
  forEach(MeshDT const& mesh, DataAccessList& data, LoopBody f) {

    for(int i = 0; i < mesh.size; ++i) {
      f(i, data.data);
    }

  }

}

#endif
