
find_package(GTest) # Required by gmock
find_package(GMock REQUIRED)
find_package(QtTestUtil)

find_package(Qt4 4.7.1 COMPONENTS QtTest QtSql REQUIRED)
include(${QT_USE_FILE})

# Configure db test
set(DATABASEDRIVER QSQLITE)
set(DATABASE dorfverw.dat)
set(SQLTESTFILE "${PROJECT_SOURCE_DIR}/testdaten.sql")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/testconfig.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/testconfig.h"
  )

include_directories(
    ../src
    ${CMAKE_CURRENT_BINARY_DIR}/../src
    ${QT_TEST_UTIL_INCLUDE_DIR}
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)

set(test_additional_lib
    fooLib
    ${QT_TEST_UTIL_LIBRARIES}
    ${GMOCK_BOTH_LIBRARIES}
    ${GTEST_BOTH_LIBRARIES}
)

set(test_additional
    foomock.cpp
)

qt4_add_test(foo exampletest.cpp)

