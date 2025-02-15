cmake_minimum_required(VERSION 3.10.0)
project(RTWeekend VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h")


# set(SOURCES "src/math/vec.cpp")
# set(HAEDERS "src/math/vec.h")


add_executable(RTWeekend main.cpp ${SOURCES} ${HEADERS})

include(CTest)
enable_testing()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
