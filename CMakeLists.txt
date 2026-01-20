cmake_minimum_required(VERSION 3.28)
project(image-viewer VERSION 0.1.0 LANGUAGES C)
set(APP_NAME imgview)

# SDL build options
set(SDL_SHARED OFF CACHE BOOL "Build SDL3 as shared library" FORCE)
set(SDL_STATIC ON CACHE BOOL "Build SDL3 as static library" FORCE)

# Disable SDL Extras
set(SDL_AUDIO     OFF CACHE BOOL "" FORCE)
set(SDL_JOYSTICK  OFF CACHE BOOL "" FORCE)
set(SDL_HAPTIC    OFF CACHE BOOL "" FORCE)
set(SDL_HIDAPI    OFF CACHE BOOL "" FORCE)
set(SDL_CAMERA    OFF CACHE BOOL "" FORCE)
set(SDL_SENSOR    OFF CACHE BOOL "" FORCE)
set(SDL_DIALOG    OFF CACHE BOOL "" FORCE)
set(SDL_TRAY      OFF CACHE BOOL "" FORCE)
set(SDL_POWER     OFF CACHE BOOL "" FORCE)
set(SDL_GPU       OFF CACHE BOOL "" FORCE)

# Add SDL2
add_subdirectory(external/SDL)

# Add Sources
file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.c")
add_executable(${APP_NAME} ${SOURCES})

# Add header locations
target_include_directories(${APP_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/include
)

# Add libs locations
target_link_libraries(${APP_NAME}
  PRIVATE SDL2::SDL2
)

# For testing
include(CTest)
enable_testing()

add_test(
  NAME load_ppm
  COMMAND $<TARGET_FILE:${APP_NAME}> ${CMAKE_SOURCE_DIR}/assets/image.ppm
)
