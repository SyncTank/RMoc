cmake_minimum_required(VERSION 3.10)
project(RMoc C)
set(PROJECT_VERSION 1.0.0)

# Compiler settings
set(CMAKE_C_STANDARD 23)
#set(CMAKE_C_COMPILER "gcc")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files
file(GLOB LIB_SOURCES src/*.c)
list(REMOVE_ITEM LIB_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)

# Create a library with your core functionality
add_library(${PROJECT_NAME}_lib ${LIB_SOURCES})

# Create the main executable
add_executable(${PROJECT_NAME} src/main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

# Include directories for both library and executable
target_include_directories(${PROJECT_NAME}_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    #${CMAKE_CURRENT_SOURCE_DIR}/include/math
    #${CMAKE_CURRENT_SOURCE_DIR}/include/utils
)

# Compile options for both
target_compile_options(${PROJECT_NAME}_lib PRIVATE -Wall -Wextra -pedantic -Werror)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)

# Preprocessor defines
if(WIN32)
    target_compile_definitions(${PROJECT_NAME}_lib PRIVATE OS_WINDOWS)
elseif(UNIX)
    target_compile_definitions(${PROJECT_NAME}_lib PRIVATE OS_LINUX)
endif()

# Output directories
set_target_properties(${PROJECT_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Enable testing
if(BUILD_TESTING)
enable_testing()
    add_subdirectory(tests)
endif()

# Install step (optional)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)
