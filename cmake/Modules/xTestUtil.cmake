# i would to see more projects using these defaults
#ADD_DEFINITIONS( "-Wall" )
# ADD_DEFINITIONS( "-Wall -ansi -pedantic" )

MACRO(INIT_QGTEST)
  find_package(GTest REQUIRED)
  find_package(GMock REQUIRED)
  find_package(Qt5Test REQUIRED)
  SET(USE_GMOCK TRUE)
  #find_package(CMakeParseArguments)
  include_directories(SYSTEM
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS})
ENDMACRO(INIT_QGTEST)

# 
# Qt-Google Test helper function
# 
# Prerequist:
#   users must add `find_package(CMakeParseArguments)` before use this macro
#   one can use INIT_QGTEST to do this
# 
# parameters:
#   MOCS: files need moc
#   SRCS: other files which do not need moc
#   LIBS: libs to link with, Qt5::Test, GTest, GMock modules
#         automatically added, so do not need to list in LIBS
#
function(add_qg_test testname)
  set(options AUTORUN)
  set(multiValueArgs MOCS SRCS LIBS)
  cmake_parse_arguments(QGTEST "${options}" "" "${multiValueArgs}" ${ARGN})
  
  # message("ARGN = ${ARGN}")
  # message("QGTEST_MOCS = ${QGTEST_MOCS}")
  # message("QGTEST_SRCS = ${QGTEST_SRCS}")
  # message("QGTEST_LIBS = ${QGTEST_LIBS}")

  qt5_wrap_cpp(test_${testname}_MOC ${QGTEST_MOCS})
  
  add_custom_target(moc_${testname}_target DEPENDS ${test_${testname}_MOC})
  add_executable(test_${testname} ${QGTEST_MOCS} ${QGTEST_SRCS})
  add_dependencies(test_${testname} moc_${testname}_target)
  
  if (${USE_GMOCK})
    target_link_libraries(test_${testname} ${QGTEST_LIBS} ${GMOCK_LIBRARIES} Qt5::Test pthread)
  else(${USE_GMOCK})
    target_link_libraries(test_${testname} ${QGTEST_LIBS} ${GTEST_LIBRARIES} Qt5::Test pthread)
  endif(${USE_GMOCK})
  
  #add_test(test${testname} ${EXECUTABLE_OUTPUT_PATH}/test_${testname})
  add_test(${testname} test_${testname})
  
  if (${QGTEST_AUTORUN})
    add_custom_command(TARGET test_${testname}
      POST_BUILD
      COMMAND test_${testname}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Running ${target}" VERBATIM)
  endif(${QGTEST_AUTORUN})
endfunction(add_qg_test)

function(add_gmock_test target)
  set(options AUTORUN)
  set(multiValueArgs LIBS)
  cmake_parse_arguments(QGTEST "${options}" "" "${multiValueArgs}" ${ARGN})

  # message("LIBS = ${QGTEST_LIBS}")
  # message("UNPARSED_ARGUMENTS = ${QGTEST_UNPARSED_ARGUMENTS}")

  set(QGTEST_SRCS ${QGTEST_UNPARSED_ARGUMENTS})

  add_executable(${target} ${QGTEST_SRCS})
  target_link_libraries(${target} ${QGTEST_LIBS} ${GMOCK_BOTH_LIBRARIES} pthread)

  add_test(${target} ${target})

  if (${QGTEST_AUTORUN})
    add_custom_command(TARGET ${target}
      POST_BUILD
      COMMAND ${target}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Running ${target}" VERBATIM)
  endif(${QGTEST_AUTORUN})
endfunction(add_gmock_test)

# http://snikt.net/index.php/2010/04/01/howto-use-cmake-with-cc-projects
MACRO(find_doxygen)
  # check if doxygen is even installed
  find_package(Doxygen) # REQUIRED)

  if(EXISTS ${DOXYGEN_EXECUTABLE})
    # prepare doxygen configuration file
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

    # add doxygen as target
    add_custom_target(doxygen ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxyfile)

    # cleanup $build/api-doc on "make clean"
    set_property(DIRECTORY APPEND PROPERTY
      ADDITIONAL_MAKE_CLEAN_FILES api-doc)

    # add doxygen as dependency to doc-target
    get_target_property(DOC_TARGET doc TYPE)
    if(NOT DOC_TARGET)
      add_custom_target(doc)
    endif()
    add_dependencies(doc doxygen)

    # install HTML API documentation and manual pages
    set(DOC_PATH "share/doc/${CPACK_PACKAGE_NAME}-${VERSION}")
    #
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/api-doc/html
      DESTINATION ${DOC_PATH}
      )
    #
    # install man pages into packages, scope is now project root..
    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/api-doc/man/man3
      DESTINATION share/man/man3/
      )
  endif()
ENDMACRO()

FUNCTION(add_assembler_output _target)
  ADD_DEFINITIONS( "-g -save-temps" )
  add_custom_target(lss COMMAND objdump -h -S ${_target} >${_target}.lss DEPENDS ${_target})
  #add_custom_command(TARGET ${_target} COMMAND objdump -h -S ${_target} >${_target}.lss)
ENDFUNCTION()
