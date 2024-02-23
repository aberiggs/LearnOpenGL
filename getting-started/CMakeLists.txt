cmake_minimum_required(VERSION 3.8)
project(my_project)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-framework Cocoa -framework IOKit")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# Change path from /src if needed, or add more directories
file(GLOB_RECURSE sources
        "${CMAKE_SOURCE_DIR}/glad/*.c"
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        )
# Add precompiler definitions like that:
add_definitions(-DSOME_DEFINITION)

add_executable(my_app ${sources})

# Add more include directories if needed
target_include_directories(my_app PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(my_app PUBLIC "${CMAKE_SOURCE_DIR}/glad/include")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(my_app PUBLIC glfw )

