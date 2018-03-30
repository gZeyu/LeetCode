cmake_minimum_required(VERSION 3.0.0)
project(LongestPalindromicSubstring VERSION 0.0.0)

include(CTest)
include(CMakeToolsHelpers OPTIONAL)
enable_testing()

include_directories(../googletest/include)
link_directories(../googletest/lib)

aux_source_directory(. DIR_5_SRCS)
add_executable(${PROJECT_NAME} ${DIR_5_SRCS})
target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)


set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME}_unittest.out)
add_test(${PROJECT_NAME}_unittest ${PROJECT_NAME}_unittest.out)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
