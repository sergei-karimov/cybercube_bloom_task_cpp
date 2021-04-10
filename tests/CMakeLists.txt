cmake_minimum_required(VERSION 3.19)
project(tests)

enable_testing()

find_package(Catch2 REQUIRED)
add_executable(
        tests
        BitsTest.cpp
        BloomFilterTest.cpp
        HashTest.cpp
        BloomFilterIntegrationTest.cpp
        ../src/Bits.cpp
        ../src/Bits.h
        ../src/BloomFilter.cpp
        ../src/BloomFilter.h
        ../src/Hash.cpp
        ../src/Hash.h
)

target_link_libraries(tests PRIVATE Catch2::Catch2)
target_compile_definitions(tests PUBLIC CATCH_CONFIG_NOSTDOUT)
