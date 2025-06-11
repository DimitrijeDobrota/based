cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    based
    VERSION 0.2.1
    DESCRIPTION "Opinionated utility library"
    HOMEPAGE_URL "https://git.dimitrijedobrota.com/based.git"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(based_based INTERFACE)
add_library(based::based ALIAS based_based)

set_property(
    TARGET based_based PROPERTY
    EXPORT_NAME based
)

target_include_directories(
    based_based ${warning_guard}
    INTERFACE
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_compile_features(based_based INTERFACE cxx_std_20)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
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
