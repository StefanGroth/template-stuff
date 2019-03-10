#include <iostream>
#include <utility>
#include <string>

template<typename...> using try_to_instantiate = void; // void is used to detect ill-formed types
using disregard_this = void;

//template<typename T, typename Attempt = void> struct is_incrementable : std::false_type {};

template<template<typename...> class Expression, typename Attempt, typename ... Ts> struct is_detected_impl : std::false_type {};

template<template<typename...> class Expression, typename ... Ts> struct is_detected_impl<Expression, try_to_instantiate<Expression<Ts...>>, Ts...> : std::true_type {};

template<template<typename...> class Expression, typename ... Ts> constexpr bool is_detected = is_detected_impl<Expression, disregard_this, Ts...>::value;

template<typename T, typename U> using assign_expression = decltype(std::declval<T&>() = std::declval<U&>()); //references are used here because no temporary is created

template<typename T, typename U> constexpr bool are_assignable = is_detected<assign_expression, T, U>;

template<typename T> using incremet_expression = decltype(++std::declval<T&>());

template<typename T> constexpr bool is_incrementable = is_detected<incremet_expression, T>; 

int main(int argc, char ** argv) {

  std::cout << std::boolalpha;
  std::cout << "int is incrementable => " << is_incrementable<int> << std::endl;
  std::cout << "string is incrementable => " << is_incrementable<std::string> << std::endl;
  std::cout << "int = double => " << are_assignable<int, double> << std::endl;
  std::cout << "int = string => " << are_assignable<int, std::string> << std::endl;

}
