cmake_minimum_required(VERSION 3.10)

project(Amaze VERSION 1.0)

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


set(SOURCE main.cpp)
set(HEADERS 
    headers/global.h
    headers/graph.h 
    headers/BFS.h 
    headers/DFS.h 
    headers/graph.cpp 
    headers/BFS.cpp 
    headers/DFS.cpp 
    headers/solver.h 
    headers/solver.cpp 
    headers/menu.cpp 
    headers/menu.h
)

set(MAZE_DATA 
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/maze1.txt 
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/maze2.txt 
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/maze3.txt 
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/maze4.txt 
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/maze5.txt 
        )
file(COPY ${MAZE_DATA}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(Amaze WIN32 ${SOURCE} ${HEADERS})
target_link_libraries(Amaze PRIVATE raylib)

install(TARGETS Amaze RUNTIME DESTINATION bin)
install(DIRECTORY resources DESTINATION resouces)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_NAME "Amaze")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Amaze Installer")
set(CPACK_NSIS_DISPLAY_NAME "Amaze")
set(CPACK_NSIS_PACKAGE_NAME "Amaze")
set(CPACK_NSIS_MODIFY_PATH ON)
include(CPack)