cmake_minimum_required(VERSION 3.2.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX20_STANDARD_COMPILE_OPTION "-std:c++latest")
set(CMAKE_CXX20_EXTENSION_COMPILE_OPTION "-std:c++latest")

project(particle_fix)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

set(CMAKE_SIZEOF_VOID_P 4)

target_include_directories(${PROJECT_NAME} PRIVATE
  libraries/minhook/include
  libraries/gd.h/include
  libraries/gd.h/
  libraries/matdash/include
  libraries/matdash
)

add_subdirectory(libraries/minhook)
add_subdirectory(libraries/cocos-headers)

target_link_libraries(${PROJECT_NAME} minhook cocos2d)