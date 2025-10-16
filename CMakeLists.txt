cmake_minimum_required(VERSION 3.16)
project(CLIENT VERSION 1.0 LANGUAGES C)

find_package(PkgConfig REQUIRED)

# Find SDL3 from package
pkg_check_modules(SDL3 REQUIRED sdl3)

# Manually find SDL3_image and SDL3_ttf since they were compiled from source
find_path(SDL3_IMAGE_INCLUDE_DIRS
    NAMES SDL3_image/SDL_image.h
    PATHS /usr/local/include /usr/include
    DOC "SDL3_image include directory"
)

find_library(SDL3_IMAGE_LIBRARIES
    NAMES SDL3_image
    PATHS /usr/local/lib /usr/lib
    DOC "SDL3_image library"
)

find_path(SDL3_TTF_INCLUDE_DIRS
    NAMES SDL3_ttf/SDL_ttf.h
    PATHS /usr/local/include /usr/include
    DOC "SDL3_ttf include directory"
)

find_library(SDL3_TTF_LIBRARIES
    NAMES SDL3_ttf
    PATHS /usr/local/lib /usr/lib
    DOC "SDL3_ttf library"
)

# Check if we found the manually compiled libraries
if(NOT SDL3_IMAGE_LIBRARIES)
    message(FATAL_ERROR "SDL3_image not found! Try: sudo make install in your SDL3_image build directory")
endif()

if(NOT SDL3_TTF_LIBRARIES)
    message(FATAL_ERROR "SDL3_ttf not found! Try: sudo make install in your SDL3_ttf build directory")
endif()

set(SOURCES
    src/main.c
    libs/renderer.c
    libs/sockets.c
    libs/data.c
    libs/stringType.c
    libs/drawScreen.c
    libs/profileManager.c
    libs/serverManager.c
    libs/panelInfo.c
    libs/GPUManager.c
)

add_executable(client ${SOURCES})

target_include_directories(client PRIVATE
    include
    ${SDL3_INCLUDE_DIRS}
    ${SDL3_IMAGE_INCLUDE_DIRS}
    ${SDL3_TTF_INCLUDE_DIRS}
)

target_link_libraries(client PRIVATE
    ${SDL3_LIBRARIES}
    ${SDL3_IMAGE_LIBRARIES}
    ${SDL3_TTF_LIBRARIES}
    m
)

# Print debug info
message(STATUS "SDL3 Include Dirs: ${SDL3_INCLUDE_DIRS}")
message(STATUS "SDL3 Libraries: ${SDL3_LIBRARIES}")
message(STATUS "SDL3_image Include: ${SDL3_IMAGE_INCLUDE_DIRS}")
message(STATUS "SDL3_image Library: ${SDL3_IMAGE_LIBRARIES}")
message(STATUS "SDL3_ttf Include: ${SDL3_TTF_INCLUDE_DIRS}")
message(STATUS "SDL3_ttf Library: ${SDL3_TTF_LIBRARIES}")