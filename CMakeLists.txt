cmake_minimum_required(VERSION 3.0)

project(
  TemplateStuff 
  VERSION      0.0.1 
  DESCRIPTION  "Project for testing out template meta-programming" 
  LANGUAGES    CXX
)

add_executable(TestApp src/main.cpp)

set_target_properties(TestApp PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
)
