project(CMakeGMockTemplate)
cmake_minimum_required(VERSION 2.8)

include(QtBuildUtil)

# The version number.
set (QTemplate_VERSION_MAJOR 0)
set (QTemplate_VERSION_MINOR 1)
set (QTemplate_VERSION_PATCH 0)

find_package(Qt4 4.7.2 COMPONENTS QtCore REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


include(${QT_USE_FILE})

find_doxygen()

add_subdirectory(src)

# The following are required to uses Dart and the Cdash dashboard
enable_testing(true)
#include(CTest)

add_subdirectory(test)
