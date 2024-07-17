cmake_minimum_required(VERSION 3.10)

project(app VERSION 1.0)

set(SOURCE main.cpp)
set(HEADERS headers/graph.h headers/BFS.h headers/DFS.h headers/graph.cpp headers/BFS.cpp headers/DFS.cpp headers/solver.h headers/solver.cpp headers/menu.cpp headers/menu.h)

set(MAZE_DATA 
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/maze1.txt 
        )
file(COPY ${MAZE_DATA}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(app ${SOURCE} ${HEADERS})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
install(TARGETS app RUNTIME DESTINATION .)
install(DIRECTORY resources DESTINATION resouces)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_NAME "MyApp")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyApp Installer")
set(CPACK_PACKAGE_VENDOR "MyCompany")
set(CPACK_NSIS_DISPLAY_NAME "MyApp")
set(CPACK_NSIS_PACKAGE_NAME "MyApp")
set(CPACK_NSIS_CONTACT "support@mycompany.com")
set(CPACK_NSIS_MODIFY_PATH ON)
include(CPack)