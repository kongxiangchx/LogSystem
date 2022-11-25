cmake_minimum_required(VERSION 2.8)
project(chx)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O3 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function")

# include_directories(.)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# find_library(YAMLCPP libyaml-cpp.a)

set(LIB_SRC
    chx/log.cc
    chx/util.cc
    chx/config.cc
    )

add_library(chx SHARED ${LIB_SRC})
# add_library(chx_static STATIC ${LIB_SRC})
# SET_TARGET_PROPERTIES (chx_static PROPERTIES OUTPUT_NAME "chx")

# add_executable(test tests/test.cc)
# add_dependencies(test chx)
# target_link_libraries(test chx)

add_executable(test_config tests/test_config.cc)
add_dependencies(test_config chx)
target_link_libraries(test_config chx -L/usr/local/lib -lyaml-cpp)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)