cmake_minimum_required(VERSION 3.10)

project(app)
find_package(fmt REQUIRED)


set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()
include(FetchContent)
FetchContent_Declare(
  raygui
  GIT_REPOSITORY https://github.com/raysan5/raygui.git
  GIT_TAG 4.0
)
FetchContent_GetProperties(raygui)
if(NOT raygui_POPULATED)
  FetchContent_Populate(raygui)
  add_library(raygui INTERFACE)
  target_include_directories(raygui INTERFACE ${raygui_SOURCE_DIR}/src)
endif()


add_executable(app main.cpp)
target_link_libraries(app PRIVATE
                    fmt::fmt 
                     raylib
                     raygui
                    )