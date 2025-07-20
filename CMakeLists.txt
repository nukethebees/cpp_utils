cmake_minimum_required (VERSION 3.25)

project ("cpp_utils" 
    VERSION 0.1.0
    LANGUAGES CXX
)

# Include sub-projects.
add_subdirectory ("cpp_utils")
add_subdirectory ("tests")

# Packaging
##############################################
# Internally the package is just cpp_utils
# When packaged for external use it is ml_cpp_utils

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ml_cpp_utils.pc.in
    ${CMAKE_CURRENT_BINARY_DIR}/ml_cpp_utils.pc
)

install(
    FILES ${CMAKE_CURRENT_BINARY_DIR}/ml_cpp_utils.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ml_cpp_utils-config-version.cmake
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ml_cpp_utils-config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ml_cpp_utils-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_DATADIR}/ml_cpp_utils
)

install(
    TARGETS cpp_utils
    EXPORT ml_cpp_utils_targets
    FILE_SET HEADERS
)

install(
    EXPORT ml_cpp_utils_targets
    NAMESPACE ml_cpp_utils::
    DESTINATION ${CMAKE_INSTALL_DATADIR}/ml_cpp_utils
)