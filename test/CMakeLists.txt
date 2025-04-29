cmake_minimum_required(VERSION 3.14)

project(basedTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

function(add_test NAME)
  add_executable("${NAME}" "source/${NAME}.cpp")
  target_link_libraries("${NAME}" PRIVATE based::based)
  target_link_libraries("${NAME}" PRIVATE Catch2::Catch2WithMain)
  target_compile_features("${NAME}" PRIVATE cxx_std_20)
  catch_discover_tests("${NAME}")
endfunction()

# ----- Algorithm -----

## ----- Min and Max -----

add_test(min_test)
add_test(max_test)

## ----- Bounded Range -----

add_test(min_element_test)
add_test(max_element_test)
add_test(minmax_element_test)

add_test(for_each_test)
add_test(find_test)
add_test(find_if_test)
add_test(count_test)
add_test(count_if_test)
add_test(reduce_test)
add_test(find_mismatch_test)
add_test(partition_test)

## ----- Counted Range -----

add_test(for_each_n_test)
add_test(find_n_test)
add_test(find_if_n_test)
add_test(count_n_test)
add_test(count_if_n_test)
add_test(find_mismatch_n_test)

## ----- Unguarded Range -----

add_test(find_if_unguarded_test)

# ---- List ----

add_test(list_test)

# ---- String ----

add_test(string_literal_test)

# ---- Template ----

add_test(signature_test)
add_test(buffer_test)
add_test(function_test)
add_test(scopeguard_test)

# ---- End-of-file commands ----

add_folders(Test)
