include(xTestUtil)

INIT_QGTEST()

SET(CMAKE_AUTOMOC OFF)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}/../src
)


add_qg_test(qtest_tutorial 
  MOCS testqstring.cpp
  AUTORUN)

add_qg_test(qtest_gui
  MOCS testgui.cpp
  LIBS Qt5::Widgets
  AUTORUN)

add_qg_test(qtest_gui2
  MOCS testgui2.cpp
  LIBS Qt5::Widgets
  AUTORUN)

add_qg_test(qtest_benchmarking
  MOCS benchmarking.cpp
  LIBS Qt5::Widgets)

add_qg_test(qtest_containers
  MOCS containers.cpp
  LIBS Qt5::Widgets)
