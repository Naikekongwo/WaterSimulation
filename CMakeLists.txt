cmake_minimum_required(VERSION 3.12)
project(Waterwaves CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/project/*.cpp"
)

include_directories(
    "${CMAKE_SOURCE_DIR}/include"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set(SDL2_LIBRARIES mingw32 SDL2main SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE ${SDL2_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build
)

