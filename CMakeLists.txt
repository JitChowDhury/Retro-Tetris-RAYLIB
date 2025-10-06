# Minimum version required
cmake_minimum_required(VERSION 3.28)

# Project name and language
project(Tetris LANGUAGES CXX)

# Where to put the final program
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Get raylib from GitHub
include(FetchContent)
FetchContent_Declare(raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(raylib)

# Collect sources
file(GLOB SRC_FILES src/*.cpp)
file(GLOB HEADER_FILES include/*.h)

# Define the executable
add_executable(Tetris ${SRC_FILES} ${HEADER_FILES})

# Include and C++ standard
target_include_directories(Tetris PRIVATE include)
target_compile_features(Tetris PRIVATE cxx_std_17)

# Link raylib
target_link_libraries(Tetris PRIVATE raylib)

# Copy raylib DLLs after build (Windows only)
if(WIN32)
    add_custom_command(TARGET Tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        $<TARGET_FILE_DIR:raylib> $<TARGET_FILE_DIR:Tetris>
    )

    # set(APP_ICON_RESOURCE "${CMAKE_CURRENT_SOURCE_DIR}/resources.rc")
    # target_sources(Tetris PRIVATE ${APP_ICON_RESOURCE})
endif()

# Compiler warnings
if(MSVC)
    target_compile_options(Tetris PRIVATE /W4)
else()
    target_compile_options(Tetris PRIVATE -Wall -Wextra -Wpedantic)
endif()
