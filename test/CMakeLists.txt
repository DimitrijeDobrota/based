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


add_test(trait invoke_result_test)
add_test(trait is_array_test)
add_test(trait is_base_of_test)
add_test(trait is_class_test)
add_test(trait is_const_test)
add_test(trait is_enum_test)
add_test(trait is_lvalue_reference_test)
add_test(trait is_null_pointer_test)
add_test(trait is_rvalue_reference_test)
add_test(trait is_void_test)
add_test(trait remove_const_test)
add_test(trait remove_cvref_test)
add_test(trait remove_cv_test)
add_test(trait remove_pointer_test)
add_test(trait remove_reference_test)
add_test(trait remove_volatile_test)
add_test(trait signature_test_test)

## ----- Concepts -----

add_test(concepts callable_test)

## ----- Algorithm -----

add_test(algorithms max_test)
add_test(algorithms min_test)

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
