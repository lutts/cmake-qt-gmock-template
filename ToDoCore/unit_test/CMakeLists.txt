include(xTestUtil)

INIT_QGTEST()

add_gmock_test(ToDoTest ToDoTest.cc 
               LIBS toDoCore
	       AUTORUN)
