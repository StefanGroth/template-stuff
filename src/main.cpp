#include <iostream>
#include <string>

#include <buffer.hpp>
#include <for_each.hpp>
#include <mesh.hpp>

#include <is_detected.hpp>

class MyScalar {};
class MyElement {};

enum class Access {
  read, write
};

int main(int argc, char ** argv) {
 
  HPM::mesh<MyScalar, 3, MyElement> mesh(10);

  HPM::buffer<double> buf(mesh);

  HPM::forEach(
    mesh,
    buf,
    [](int index, std::vector<double>& data) {
      data[index] = 2;
    }
  );

  for(auto& e : buf.data)
    std::cout << e << std::endl;

}
