if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/based-${PROJECT_VERSION}"
      CACHE STRING ""
  )
  set_property(CACHE CMAKE_INSTALL_INCLUDEDIR PROPERTY TYPE PATH)
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package based)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT based_Development
)

install(
    TARGETS based_based
    EXPORT basedTargets
    RUNTIME #
    COMPONENT based_Runtime
    LIBRARY #
    COMPONENT based_Runtime
    NAMELINK_COMPONENT based_Development
    ARCHIVE #
    COMPONENT based_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    based_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE STRING "CMake package config location relative to the install prefix"
)
set_property(CACHE based_INSTALL_CMAKEDIR PROPERTY TYPE PATH)
mark_as_advanced(based_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${based_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT based_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${based_INSTALL_CMAKEDIR}"
    COMPONENT based_Development
)

install(
    EXPORT basedTargets
    NAMESPACE based::
    DESTINATION "${based_INSTALL_CMAKEDIR}"
    COMPONENT based_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
