#pragma once
#include <utility>

namespace type_ext {

// extract to
template<template<class...> class T, template<class...> class U, class... Args>
auto extract_to_impl(const U<Args...>&) -> T<Args...>;

template<template<class...> class T, class U>
using extract_to = decltype(extract_to_impl<T>(std::declval<U>()));

// extract idx
template<unsigned int i, class U, class... Args>
struct extract_idx_getter{
    using type = typename extract_idx_getter<i-1, Args...>::type;
};

template<class U, class... Args>
struct extract_idx_getter<0, U, Args...>{ using type = U; };

template<unsigned int i, template<class...> class U, class... Args>
auto extract_idx_impl(const U<Args...>&) -> typename std::enable_if<(i<sizeof...(Args)), extract_idx_getter<i, Args...>>::type;

template<unsigned int i, class U>
using extract_idx = typename decltype(extract_idx_impl<i>(std::declval<U>()))::type;

}
