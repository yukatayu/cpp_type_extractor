#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "type_ext.hpp"

#include <boost/type_index.hpp>

#define typeof(...) boost::typeindex::type_id_with_cvr<__VA_ARGS__>().pretty_name()

#define assert_eq(x, ...) \
    std::cout << "assert_equal(\n\t" << (#__VA_ARGS__) << ",\n\t" << (x) << "\n)\n" << std::endl; \
    assert((x) == (__VA_ARGS__));

// tester
template<class A, class B, class C>
struct TestStruct { };

int main() {
    using namespace std;

    std::cout << "using test_t = TestStruct <int, char&, float&&>;\n" << std::endl;
    using test_t = TestStruct <int, char&, float&&>;

    assert_eq("std::tuple<int, char&, float&&>"s, typeof(type_ext::extract_to<std::tuple, test_t>));

    assert_eq("int"s, typeof(type_ext::extract_idx<0, test_t>));
    assert_eq("char&"s, typeof(type_ext::extract_idx<1, test_t>));
    assert_eq("float&&"s, typeof(type_ext::extract_idx<2, test_t>));

}
