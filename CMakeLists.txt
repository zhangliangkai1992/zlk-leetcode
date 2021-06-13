cmake_minimum_required(VERSION 3.10)

project(leetcode)
add_compile_options(-g -Werror)
add_subdirectory(third_party/gtest EXCLUDE_FROM_ALL)

function(leetcode_test test_file)
	get_filename_component(test_target_name "${test_file}" NAME_WE)
	add_executable("${test_target_name}" "")
	target_sources("${test_target_name}" 
			PRIVATE
			"${test_file}"
			)
	target_link_libraries("${test_target_name}" gtest_main)
endfunction(leetcode_test)

leetcode_test("src/leetcode_1.cpp")
leetcode_test("src/leetcode_2.cpp")
leetcode_test("src/leetcode_3.cpp")
leetcode_test("src/leetcode_11.cpp")
leetcode_test("src/leetcode_15.cpp")
leetcode_test("src/leetcode_17.cpp")
leetcode_test("src/leetcode_20.cpp")
leetcode_test("src/leetcode_21.cpp")
leetcode_test("src/leetcode_41.cpp")
leetcode_test("src/leetcode_79.cpp")
leetcode_test("src/leetcode_146.cpp")
leetcode_test("src/leetcode_239.cpp")
leetcode_test("src/leetcode_264.cpp")
leetcode_test("src/leetcode_739.cpp")
leetcode_test("src/leetcode_1206.cpp")
