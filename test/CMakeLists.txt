cmake_minimum_required(VERSION 3.14)

project(basedTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(based REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

add_executable(based_test source/based_test.cpp)
target_link_libraries(
    based_test PRIVATE
    based::based
)
target_compile_features(based_test PRIVATE cxx_std_20)

# ---- End-of-file commands ----

add_folders(Test)
