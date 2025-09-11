cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(Ejercicio2)

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})


include_directories(${PROJECT_SOURCE_DIR}/include 
                    ${Geant4_INCLUDE_DIR})
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(Ejercicio2 Ej2.cc ${sources} ${headers})
target_link_libraries(Ejercicio2 ${Geant4_LIBRARIES})

# Para tener macros en el build
# set(CMAKE_INSTALL_PREFIX init.mac)
file(COPY ${PROJECT_SOURCE_DIR}/macros DESTINATION ${PROJECT_BINARY_DIR})
