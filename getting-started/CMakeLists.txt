cmake_minimum_required(VERSION 3.8)
project(my_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# Change path from /src if needed, or add more directories
file(GLOB_RECURSE triSources
        "${CMAKE_SOURCE_DIR}/glad/*.c"
        "${CMAKE_SOURCE_DIR}/src/triangle.cpp"
        )

# Change path from /src if needed, or add more directories
file(GLOB_RECURSE rectSources
        "${CMAKE_SOURCE_DIR}/glad/*.c"
        "${CMAKE_SOURCE_DIR}/src/rectangle.cpp"
        )

add_executable(triangle_app ${triSources})
add_executable(rectangle_app ${rectSources})

# Add more include directories if needed
target_include_directories(triangle_app PUBLIC "${CMAKE_SOURCE_DIR}/glad/include")
target_include_directories(rectangle_app PUBLIC "${CMAKE_SOURCE_DIR}/glad/include")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(triangle_app PUBLIC glfw )
target_link_libraries(rectangle_app PUBLIC glfw)

