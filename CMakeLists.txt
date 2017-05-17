cmake_minimum_required(VERSION 2.8.6)
project(Hashing)

enable_testing()


#
# Add Google Test
#

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest")
set(LIBRARY_DEPS "gtest")


# Declare variables for binaries' names
get_filename_component(DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
set(MODULE      "${DIR_NAME}")
set(LIBRARY     "lib_${MODULE}")
set(TESTS       "test_${MODULE}")
set(APPLICATION "perf_cuckoo_${MODULE}")
set(APPLICATION2 "perf_chain_${MODULE}")

# Include directory with public headers
include_directories("./")

# Add all submodules
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(performance_cuckoo)
add_subdirectory(performance_chain)



