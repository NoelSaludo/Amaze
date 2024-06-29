cmake_minimum_required(VERSION 3.10)

project(app)


set(SOURCE main.cpp graph.h graph.cpp Solver.h Solver.cpp)

add_executable(app ${SOURCE})
target_link_libraries(app PRIVATE)
include(CPack)