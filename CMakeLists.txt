cmake_minimum_required(VERSION 3.19)

project(HyperRogue)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-W -Wall -Wextra)
add_compile_options(-Wno-unused-parameter -Wno-implicit-fallthrough -Wno-maybe-uninitialized -Wno-invalid-offsetof)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  add_compile_definitions(WINDOWS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  add_compile_definitions(MAC)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  add_compile_definitions(LINUX)
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  add_compile_options(-pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
  add_compile_options(-Wsuggest-override -pedantic)
endif()

option(WITH_ROGUEVIZ "Enable building Rogueviz" OFF)
option(WITH_GLEW "Build with GLEW support" OFF)
option(WITH_PNG "Build with libpng features" OFF)

find_package(OpenGL REQUIRED)
find_package(SDL 1 REQUIRED)
find_package(SDL_mixer REQUIRED)
find_package(SDL_ttf REQUIRED)
find_package(ZLIB REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL_GFX REQUIRED SDL_gfx)

if(WITH_GLEW)
  find_package(GLEW REQUIRED)
  add_compile_definitions(CAP_GLEW=1)
else()
  add_compile_definitions(CAP_GLEW=0)
endif()

if(WITH_PNG)
  find_package(PNG REQUIRED)
  add_compile_definitions(CAP_PNG=1)
else()
  add_compile_definitions(CAP_PNG=0)
endif()

file(GLOB SRCS src/*.cpp)

add_subdirectory(utils)

add_custom_command(
  OUTPUT language-data.cpp
  COMMAND langen > ${CMAKE_BINARY_DIR}/language-data.cpp
)
add_custom_target(language-data DEPENDS language-data.cpp)

set(ORDERED_SRCS classes.cpp locations.cpp colors.cpp hyperpoint.cpp geometry.cpp goldberg.cpp init.cpp floorshapes.cpp cell.cpp multi.cpp shmup.cpp pattern2.cpp mapeditor.cpp graph.cpp textures.cpp hprint.cpp language.cpp util.cpp complex.cpp multigame.cpp arbitrile.cpp rulegen.cpp)
list(TRANSFORM ORDERED_SRCS PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/src/)

add_custom_command(
  OUTPUT autohdr.h
  COMMAND makeh ${ORDERED_SRCS} ${SRCS} ${CMAKE_BINARY_DIR}/language-data.cpp > ${CMAKE_BINARY_DIR}/autohdr.h
  DEPENDS language-data
)
add_custom_target(autohdr DEPENDS autohdr.h)

add_executable(hyperrogue src/hyper.cpp)
add_dependencies(hyperrogue language-data autohdr)
target_include_directories(hyperrogue PRIVATE include src external ${CMAKE_BINARY_DIR})
target_link_libraries(hyperrogue PRIVATE OpenGL::GL SDL::SDL ZLIB::ZLIB ${SDL_MIXER_LIBRARIES} ${SDL_TTF_LIBRARIES} ${SDL_GFX_LIBRARIES})

if(WITH_GLEW)
  target_link_libraries(hyperrogue PRIVATE GLEW::GLEW)
endif()

if(WITH_PNG)
  add_subdirectory(savepng)
  target_link_libraries(hyperrogue PRIVATE PNG::PNG savepng)
endif()

install(TARGETS hyperrogue)
install(FILES hyperrogue-music.txt DESTINATION share/hyperrogue)
install(DIRECTORY music DESTINATION share/hyperrogue)
install(DIRECTORY sounds DESTINATION share/hyperrogue)
