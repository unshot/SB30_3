cmake_minimum_required (VERSION 1.14)
project (SB_30_3)

set (CMAKE_CXX_STANDARD 14)

set (BUILD_CPR_TESTS OFF)
set (CMAKE_USE_OPENSSL OFF)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 67e12da316754ff3c6c91b50aafb2658438f3c1e) # the commit hash for 1.7.0
FetchContent_MakeAvailable(cpr)

add_executable (${PROJECT_NAME} main.cpp)
target_link_libraries (${PROJECT_NAME} PRIVATE cpr::cpr)
