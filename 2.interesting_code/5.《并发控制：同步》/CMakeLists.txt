add_executable(pc pc.c)
target_link_libraries(pc pthread)

add_executable(pc-cv pc-cv.c)
target_link_libraries(pc-cv pthread)

add_executable(pc-sem pc-sem.c)
target_link_libraries(pc-sem pthread)

add_executable(philosopher philosopher.c)
target_link_libraries(philosopher pthread)