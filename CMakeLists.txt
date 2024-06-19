cmake_minimum_required(VERSION 3.10)

project(app)
find_package(fmt REQUIRED)
find_package(wxWidgets REQUIRED COMPONENTS core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

if(NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 3.7.0
    )
    FetchContent_MakeAvailable(raylib)
else()
    find_package(raylib REQUIRED)
endif()

add_executable(app main.cpp)
target_link_libraries(app fmt::fmt ${wxWidgets_LIBRARIES} raylib)