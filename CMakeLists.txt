cmake_minimum_required(VERSION 3.14)
project(MathTemplate LANGUAGES CXX)

# Build all examples (e.g. cmake -DBUILD_ALL=ON .. or pass --all if your script sets this)
option(BUILD_ALL "Build main app and all examples" OFF)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# -------------------------------
# Warning flags (GCC/Clang)
# -------------------------------
add_library(project_warnings INTERFACE)

target_compile_options(project_warnings INTERFACE
  -Wall
  -Wextra
  -Wpedantic
  -Wconversion
  -Wshadow
  -Wsign-conversion
  -Wswitch-enum
  -Wnull-dereference
  -Wno-gnu-zero-variadic-macro-arguments
  -Wno-c2y-extensions
)

# -------------------------------
# Source variables
# -------------------------------

# Sources shared by library and executable
set(COMMON_SOURCES
  common/src/common/math/add.cpp
)

# Library-only sources
set(LIB_SOURCES
  lib/src/math_lib.cpp
)

# Executable-only sources
set(APP_SOURCES
  app/main.cpp
)

# -------------------------------
# Library: math_lib
# -------------------------------
add_library(math_lib STATIC) # For static library (i.e. for .lib or .a)
# add_library(math_lib SHARED) # For shared library (i.e. for .dll or .so)

# Library sources
target_sources(math_lib
  PRIVATE
  ${LIB_SOURCES}
  ${COMMON_SOURCES}
)

# Library include directories
target_include_directories(math_lib
  PUBLIC
  lib/include
  common/include
)

# Link library to warning flags
target_link_libraries(math_lib PRIVATE project_warnings)

# -------------------------------
# Executable: MathTemplate
# -------------------------------
add_executable(MathTemplate)
set_target_properties(MathTemplate PROPERTIES OUTPUT_NAME math)

# Executable sources
target_sources(MathTemplate
  PRIVATE
  ${APP_SOURCES}
  ${COMMON_SOURCES}
)

# Executable include directories
target_include_directories(MathTemplate
  PUBLIC
  common/include
  app
)

# Link executable to warning flags
target_link_libraries(MathTemplate PRIVATE project_warnings)

# -------------------------------
# Examples
# -------------------------------
if(BUILD_ALL)
  add_subdirectory(examples)
endif()

# -------------------------------
# Installation
# -------------------------------

# Install binary
install(TARGETS MathTemplate
  RUNTIME DESTINATION bin
)

# Install library
install(TARGETS math_lib
  ARCHIVE DESTINATION lib
)

# Install headers
install(DIRECTORY common/include/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY lib/include/ DESTINATION include FILES_MATCHING PATTERN "*.hpp")
