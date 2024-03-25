# Request the minimum version of CMake, in case of lower version throws error.
# See: https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# Define your proeject:
# See: https://cmake.org/cmake/help/latest/command/project.html

project(
    "FirstProjectInCMake" ##nombre del projecto
    VERSION 1.0.0 ## la version
    DESCRIPTION "CMake C Project Template for Operation Systems II"
    LANGUAGES C ##es importante ablita los lenguajes con los que cmake va a ir trabajando
) ## soporta varios lengujes, como c, c++, c#, cuda objc, objcxx, fortant...

# Define the C standard, we are going to use std17
# See: https://cmake.org/cmake/help/latest/variable/CMAKE_CXX_STANDARD.html
set(CMAKE_C_STANDARD 17)

# Include the 'include' directory, where the headers are located, buscaria todos los include en mi carpeta con ese nombre
# See: https://cmake.org/cmake/help/latest/command/inlcude_directories.html
include_directories(include)

## Hay que tener en cuenta que cmake sigue una estructura jerarquica en forma de arbol, en donde 
## CMakeLists.txt es el top que va a comandar y traspasar las variables definidas en este hacia abajo de la 
## jerarquia en diferentes cmake que puedo definir

# Add the 'src' directory, where the source files are located
# See: https://cmake.org/cmake/help/latest/command/file.html#glob
file(GLOB_RECURSE SOURCES "src/*.c")
## ventaja: no tengo que escribir archivo por archivo, esta las busca. Desventaja al agregar un arhcivo
## nuevo luego de ejecutar 'cmake', tendria que ejecutarlo nuevamente para que lo tenga en cuenta

# Create the executable
# See: https://cmake.org/cmake/help/latest/command/add_exectuable.html
add_executable(${PROJECT_NAME} ${SOURCES})
## similar a bash puedo leer variables, en donde "SOURCES" percenece al comando file() y
## "PROJECT_NAME" es del comando project()

# Compile the libraries
# See: https://cmake.org/cmake/help/latest/command/add_subdirectory.html
add_subdirectory(lib/libdyn)
add_subdirectory(lib/libsta)

# Include headers in lib
# See: https://cmake.org/cmake/help/latest/command/target_include_directories.html
target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libsta/include)

# Link the libraries
# See: https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(${PROJECT_NAME} StatiCLib DynamiCLib)