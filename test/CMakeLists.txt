cmake_minimum_required(VERSION 3.14)

project(basedTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(based REQUIRED)
  enable_testing()
endif()

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

function(add_test DIR NAME)
  add_executable("${NAME}" "source/${DIR}/${NAME}.cpp")
  target_link_libraries("${NAME}" PRIVATE based::based)
  target_link_libraries("${NAME}" PRIVATE Catch2::Catch2WithMain)
  target_compile_features("${NAME}" PRIVATE cxx_std_20)
  catch_discover_tests("${NAME}")
endfunction()


## ----- Type Traits -----

add_test(type_traits remove_const)
add_test(type_traits remove_cv)
add_test(type_traits remove_cvref)
add_test(type_traits remove_pointer)
add_test(type_traits remove_reference)
add_test(type_traits remove_volatile)
add_test(type_traits signature_test)

## ----- Concepts -----

add_test(concepts callable_test)

## ----- Algorithm -----

add_test(algorithms all_test)
add_test(algorithms count_if_not_test)
add_test(algorithms count_if_test)
add_test(algorithms count_not_test)
add_test(algorithms count_test)
add_test(algorithms find_adjacent_mismatch_test)
add_test(algorithms find_if_not_test)
add_test(algorithms find_if_test)
add_test(algorithms find_mismatch_test)
add_test(algorithms find_not_test)
add_test(algorithms find_test)
add_test(algorithms foreach_test)
add_test(algorithms lower_bound_test)
add_test(algorithms max_element_test)
add_test(algorithms max_test)
add_test(algorithms min_element_test)
add_test(algorithms minmax_element_test)
add_test(algorithms min_test)
add_test(algorithms none_test)
add_test(algorithms not_all_test)
add_test(algorithms partitioned_test)
add_test(algorithms partition_point_test)
add_test(algorithms reduce_test)
add_test(algorithms some_test)
add_test(algorithms upper_bound_test)

## ----- Utility -----

add_test(utility buffer_test)
add_test(utility scopeguard_test)

## ----- Functional -----

add_test(functional curry_test)
add_test(functional function_test)

## ------ Enum -----

add_test(. enum_test)

## ----- List -----

add_test(. list_test)

## ----- String -----

add_test(. string_literal_test)

# ---- End-of-file commands ----

add_folders(Test)
