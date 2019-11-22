# C++ Type Extractor

# Types

```cpp
template<unsigned int i, class U>
type_ext::extract_idx

template<template<class...> class T, class U>
type_ext::extract_to
```

# Usage

```cpp
template<class A, class B, class C>
struct TestStruct { };

TestStruct<int, char&, float&&> val;
char c = 1;

// std::tuple<int, char&, float&&>
type_ext::extract_to<std::tuple, decltype(val)> val_tuple {0,c,0};

// int
type_ext::extract_idx<0, decltype(val)> int_val;

// char&
type_ext::extract_idx<1, decltype(val)> char_ref = c;
char_ref = 2;
std::cout << (int)c << std::endl; // outputs 2

// no matching function for call to ‘extract_idx_impl(TestStruct<int, char&, float&&>)’
// type_ext::extract_idx<3, decltype(val)> undefined_val;
```

