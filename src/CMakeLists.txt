
set(QT_MOC_HEADERS
#    MainWindow.h
)

set(QT_UI
#    MainWindow.ui
)

set(QT_SRCS
#    MainWindow.cpp
    foo.cpp
)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/config.h"
  )

qt5_wrap_cpp(MOC_OUTFILES ${QT_MOC_HEADERS})

# Die ui_xxxx.h files werden im CMAKE_CURRENT_BINARY_DIR erzeugt.
qt5_wrap_ui(UI_OUTFILES ${QT_UI})

add_library(fooLib STATIC ${QT_SRCS} ${UI_OUTFILES} ${MOC_OUTFILES})
target_link_libraries(fooLib Qt5::Widgets)

add_executable(foo main.cpp)
target_link_libraries(foo fooLib Qt5::Widgets)
