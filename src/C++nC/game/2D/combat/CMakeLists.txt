cmake_minimum_required(VERSION 4.4)
project(combat, CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES OFF)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(combat src/main.cpp)

if(WIN32)
  #NOTE: IF WANNA USE THIS ADD libs FOLDER ON THIS SUB FOLDER
    target_include_directories(combat PRIVATE libs/raylib/include)
    target_link_libraries(combat PRIVATE
        ${CMAKE_SOURCE_DIR}/libs/raylib/lib/libraylib.a
        winmm gdi32 opengl32
    )
else()
    find_package(raylib REQUIRED)
    target_link_libraries(combat PRIVATE raylib)
endif()

