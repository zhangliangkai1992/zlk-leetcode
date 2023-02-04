cmake_minimum_required(VERSION 3.10)

project(leetcode)
add_compile_options(-g -Werror -fsanitize=address)
add_subdirectory(third_party/gtest EXCLUDE_FROM_ALL)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_EXE_LINKER_FLAGS "-fsanitize=address")

function(leetcode_test test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)
    add_executable("${test_target_name}" "")
    target_sources("${test_target_name}"
            PRIVATE
            "${test_file}"
            )
    target_link_libraries("${test_target_name}" gtest_main)
endfunction(leetcode_test)
file(GLOB src_files
        "src/*.cpp"
        )
foreach(leetcode_source ${src_files})
    leetcode_test(${leetcode_source})
endforeach(leetcode_source)
