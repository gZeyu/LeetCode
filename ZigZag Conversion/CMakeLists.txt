cmake_minimum_required(VERSION 3.0.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} VERSION 0.0.0)


include(CTest)
include(CMakeToolsHelpers OPTIONAL)

add_definitions(-std=c++11)
aux_source_directory(. DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS})
target_link_libraries(${PROJECT_NAME} gtest gtest_main pthread)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME solution_unittest.out)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
