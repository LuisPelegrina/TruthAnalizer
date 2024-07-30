

cmake_minimum_required(VERSION 3.27)
project(Truth_test CXX)

# Establecer la versión mínima de macOS

# Establecer la versión mínima de macOS
set(CMAKE_OSX_DEPLOYMENT_TARGET "13.5" CACHE STRING "Minimum macOS version")

# Configurar las opciones de compilación y enlace
set(CMAKE_CXX_STANDARD 11)  # Establecer el estándar de C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mmacosx-version-min=13.5")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mmacosx-version-min=13.5")


#find_package(ROOT REQUIRED COMPONENTS Hist)
find_package(ROOT REQUIRED COMPONENTS Core RIO Tree Hist MathCore Physics)

add_executable(Truth_test
        main.cpp
        read_tree.C
)

target_link_libraries(Truth_test PUBLIC  ROOT::Core ROOT::RIO ROOT::Tree ROOT::Hist ROOT::MathCore ROOT::Physics)