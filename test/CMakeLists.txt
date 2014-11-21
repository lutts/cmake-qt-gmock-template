include(xTestUtil)

INIT_QGTEST()

SET(CMAKE_AUTOMOC OFF)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/testconfig.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/testconfig.h"
  )


include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}/../src
)


add_qg_test(foo 
  MOCS exampletest.h
  SRCS exampletest.cpp foomock.cpp
  LIBS fooLib
  AUTORUN)
