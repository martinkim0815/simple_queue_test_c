cmake_minimum_required(VERSION 3.10)  
project(simple_queue LANGUAGES C CXX)  

set(CMAKE_CXX_STANDARD 11)  

# Include Google Test  
include_directories(googletest/include)  
include_directories(include)  

add_subdirectory(googletest)  

# Add the main queue implementation  
add_library(queue src/queue.c)  

# Add tests  
add_executable(test_queue tests/test_queue.cpp)  
target_link_libraries(test_queue queue gtest gtest_main)  

enable_testing()  
add_test(NAME test_queue COMMAND test_queue)
