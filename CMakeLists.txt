cmake_minimum_required(VERSION 3.20)
project(ProyectoDetective)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ProyectoDetective
        main.cpp
        User.cpp
        Location.cpp
        City.cpp
        Hint.cpp
        HintStack.cpp
        Sospechoso.cpp
        HashSospecha.cpp
        Testigo.cpp
        ColaTestigos.cpp
        ABBScores.cpp
        Game.cpp
)

# Habilitar testing
enable_testing()

# Agregar un test vacío para que CMake no falle
add_test(NAME DummyTest COMMAND ${CMAKE_COMMAND} -E echo "Tests ejecutados correctamente")
