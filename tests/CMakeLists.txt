cmake_minimum_required(VERSION 3.10)
	project(tests)
	
	add_executable(test_runner test_main.c)
	target_link_libraries(test_runner PRIVATE BUILDC)
	add_test(NAME main_tests COMMAND test_runner)
	# include(GoogleTest)
	# gtest_discover_tests(test_runner)
	
