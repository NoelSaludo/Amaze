cmake_minimum_required(VERSION 3.10)

project(app VERSION 1.0)

set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if(NOT raylib_FOUND)
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

set(SOURCE main.cpp graph.h graph.cpp DFS.h DFS.cpp
        BFS.h
        BFS.cpp)
set(MAZE_DATA )
file(COPY ${MAZE_DATA}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(app ${SOURCE})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(app PRIVATE raylib)

install(TARGETS app RUNTIME DESTINATION .)
install(DIRECTORY resources DESTINATION resouces)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)
set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_NAME "MyApp")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyApp Installer")
set(CPACK_PACKAGE_VENDOR "MyCompany")
set(CPACK_NSIS_DISPLAY_NAME "MyApp")
set(CPACK_NSIS_PACKAGE_NAME "MyApp")
set(CPACK_NSIS_CONTACT "support@mycompany.com")
set(CPACK_NSIS_MODIFY_PATH ON)