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

## ----- Integral -----

add_test(integral strong_type_test)
add_test(integral type_test)
add_test(integral limits_test)
add_test(integral literals_test)

## ----- Trait -----

add_test(trait invoke_result_test)
add_test(trait remove_const_test)
add_test(trait remove_cvref_test)
add_test(trait remove_cv_test)
add_test(trait remove_pointer_test)
add_test(trait remove_reference_test)
add_test(trait remove_volatile_test)
add_test(trait signature_test)

## ----- Concept -----

add_test(concept callable_test)
add_test(concept is_array_test)
add_test(concept is_base_of_test)
add_test(concept is_class_test)
add_test(concept is_const_test)
add_test(concept is_enum_test)
add_test(concept is_lvalue_reference_test)
add_test(concept is_null_pointer_test)
add_test(concept is_rvalue_reference_test)
add_test(concept is_void_test)

## ----- Algorithm -----

add_test(algorithm max_test)
add_test(algorithm min_test)

## ----- Utility -----

add_test(utility buffer_test)
add_test(utility scopeguard_test)
add_test(utility static_view_test)

## ----- Functional -----

add_test(functional curry_test)
add_test(functional function_test)

## ------ Enum -----

add_test(enum standard_test)
add_test(enum bitmask_test)

## ----- String -----

add_test(string literal_test)
add_test(string format_test)

## ----- Char -----

add_test(character mapper_test)

## ----- Container -----

add_test(container list_test)
add_test(container array_test)

# ---- End-of-file commands ----

add_folders(Test)
