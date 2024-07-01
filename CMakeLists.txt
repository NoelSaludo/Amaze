cmake_minimum_required(VERSION 3.10)

project(app VERSION 1.0)


set(SOURCE main.cpp graph.h graph.cpp Solver.h Solver.cpp)
set(MAZE_DATA )
file(COPY ${MAZE_DATA}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(app ${SOURCE})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/resources)
target_link_libraries(app PRIVATE)

set(CPACK_GENERATOR "NSIS")
set(CPACK_PACKAGE_NAME "MyApp")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "MyApp Installer")
set(CPACK_PACKAGE_VENDOR "MyCompany")
set(CPACK_NSIS_DISPLAY_NAME "MyApp")
set(CPACK_NSIS_PACKAGE_NAME "MyApp")
set(CPACK_NSIS_CONTACT "support@mycompany.com")
set(CPACK_NSIS_MODIFY_PATH ON)

install(TARGETS app RUNTIME DESTINATION .)
install(DIRECTORY resources DESTINATION resouces)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include(CPack)