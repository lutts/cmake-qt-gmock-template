include(xTestUtil)

INIT_QGTEST()

add_gmock_test(dummy dummy_test.cc 
               LIBS dummyLib
	       AUTORUN)
