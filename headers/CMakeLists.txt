set(GLOBAL_HEADERS global.h)
set(ALGO_HEADERS DFS.h BFS.h solver.h)
set(ALGO_SOURCES DFS.cpp BFS.cpp solver.cpp)
set(MENU_HEADERS menu.h)
set(MENU_SOURCES menu.cpp)
set(GRAPH graph.h graph.cpp)

# Create libraries for headers and sources separately if needed
add_library(globalHeaders INTERFACE ${GLOBAL_HEADERS})
add_library(algo STATIC ${ALGO_HEADERS} ${ALGO_SOURCES})
Sadd_library(menu STATIC ${MENU_HEADERS} ${MENU_SOURCES})
add_library(graph STATIC ${GRAPH})

# Link libraries correctly
target_link_libraries(globalHeaders INTERFACE menu graph)
target_link_libraries(menu PRIVATE algo design)