set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/)

add_subdirectory(public public)

add_subdirectory(mycat mycat)
add_subdirectory(mycp mycp)
add_subdirectory(myecho myecho)
add_subdirectory(pi1 pi1)
add_subdirectory(pi2 pi2)
add_subdirectory(pc1 pc1)
add_subdirectory(pc2 pc2)
add_subdirectory(ring ring)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/)
add_subdirectory(ShellSimulation ShellSimulationApp)