cmake_minimum_required(VERSION 3.25.1)

project(CPP_playground)
set(CMAKE_CXX_STANDARD 11)

# TODO: Add tests and install targets if needed.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(BIN_DIR ${SDL_cmake_template_SOURCE_DIR}/bin)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES "src/main.cpp")

add_executable(CPP_playground ${SOURCE_FILES})

target_link_libraries(CPP_playground ${SDL2_LIBRARY})

install(TARGETS CPP_playground RUNTIME DESTINATION ${BIN_DIR}/)
set_target_properties(
  CPP_playground
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${BIN_DIR}/debug/
             RUNTIME_OUTPUT_DIRECTORY_RELEASE ${BIN_DIR}/release/)
