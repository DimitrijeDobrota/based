cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    based
    VERSION 0.1.0
    DESCRIPTION "Opinionated utility library"
    HOMEPAGE_URL "https://git.dimitrijedobrota.com/based.git"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    based_based
    source/instrumentation.cpp
)
add_library(based::based ALIAS based_based)

include(GenerateExportHeader)
generate_export_header(
    based_based
    BASE_NAME based
    EXPORT_FILE_NAME export/based/based_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(based_based PUBLIC BASED_STATIC_DEFINE)
endif()

set_target_properties(
    based_based PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME based
    OUTPUT_NAME based
)

target_include_directories(
    based_based ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    based_based SYSTEM
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(based_based PUBLIC cxx_std_20)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${based_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT based_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of based"
  )
endif()

include(cmake/dev-mode.cmake)
