cmake_minimum_required(VERSION 3.0)

project(
  TemplateStuff 
  VERSION      0.0.1 
  DESCRIPTION  "Project for testing out template meta-programming" 
  LANGUAGES    CXX
)

add_executable(TestApp src/main.cpp)
target_include_directories(TestApp PUBLIC include)

add_library(HPM INTERFACE)
target_include_directories(HPM
    INTERFACE 
    $<INSTALL_INTERFACE:include/HPM>    
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/HPM>
)

target_link_libraries(TestApp 
  PUBLIC 
    HPM
)

set_target_properties(TestApp PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)
