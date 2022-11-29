cmake_minimum_required(VERSION 2.8)
project(chx)

include (cmake/utils.cmake)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined")

include_directories(.)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_library(YAMLCPP libyaml-cpp.a)

set(LIB_SRC
    chx/log.cc
    chx/util.cc
    chx/config.cc
    chx/lock.cc
    )

add_library(chx SHARED ${LIB_SRC})
force_redefine_file_macro_for_sources(chx) #__FILE__
# add_library(chx_static STATIC ${LIB_SRC})
# SET_TARGET_PROPERTIES (chx_static PROPERTIES OUTPUT_NAME "chx")

set(LIB_LIB
    chx
    pthread
    ${YAMLCPP})

add_executable(test tests/test.cc)
add_dependencies(test chx)
force_redefine_file_macro_for_sources(test) #__FILE__
target_link_libraries(test ${LIB_LIB})

add_executable(test_config tests/test_config.cc)
add_dependencies(test_config chx)
force_redefine_file_macro_for_sources(test_config) #__FILE__
target_link_libraries(test_config chx ${LIB_LIB})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)