cmake_minimum_required (VERSION 3.25)

project ("cpp_utils" 
    VERSION 0.3.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include sub-projects.
add_subdirectory ("ml_cpp_utils")
add_subdirectory ("tests")

# Packaging
##############################################
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
    TARGETS ml_cpp_utils
    EXPORT ml_cpp_utils_targets
    FILE_SET HEADERS
)

install(
    EXPORT ml_cpp_utils_targets
    NAMESPACE ml_cpp_utils::
    DESTINATION ${CMAKE_INSTALL_DATADIR}/ml_cpp_utils
)