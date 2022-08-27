#  Distributed under the Boost Software License, Version 1.0.
#       (See accompanying file LICENSE_1_0.txt or copy at
#             http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.13)

project(hello-world VERSION 1.0.0
    DESCRIPTION "My C++ Hello World"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =============================================================================
include_directories(third_party/cpp-httplib)

# =============================================================================
add_subdirectory(src)
