## This file is a quick tutorial on writing CMakeLists for targeting the Vita
cmake_minimum_required(VERSION 2.8)

## This includes the Vita toolchain, must go before project definition
# It is a convenience so you do not have to type
# -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake for cmake. It is
# highly recommended that you include this block for all projects.
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

## Define project parameters here
# Name of the project
project(Hex-A-Hop)
# This line adds Vita helper macros, must go after project definition in order
# to build Vita specific artifacts (self/vpk).
include("${VITASDK}/share/vita.cmake" REQUIRED)

## Configuration options for this app
# Display name (under bubble in LiveArea)
set(VITA_APP_NAME "hex-a-hop")
# Unique ID must be exactly 9 characters. Recommended: XXXXYYYYY where X =
# unique string of developer and Y = a unique number for this app
set(VITA_TITLEID  "WLOGICHAH")
set(VITA_VERSION  "01.00")

add_compile_definitions(DATADIR="ux0:data/hex-a-hop/")
add_compile_definitions(VERSION=1.0)
add_compile_definitions(REVISION=0)

# Moving SCREEN_HEIGHT and SCREEN_WIDTH to the CMake script
# This will let us specify different hardware screensizes.
add_compile_definitions(GAMENAME="Hex-A-Hop")
add_compile_definitions(SCREEN_WIDTH=960)
add_compile_definitions(SCREEN_HEIGHT=544)
add_compile_definitions(FONT_PATH="font.ttf")
add_compile_definitions(ENABLE_NLS)
add_compile_definitions(LOCALEDIR="ux0:data/hex-a-hop/po/")

## Flags and includes for building
# Note that we make sure not to overwrite previous flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# Optional. You can specify more param.sfo flags this way.
set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")

# Add any additional include paths here
include_directories(
)

# Add any additional library paths here
# ${CMAKE_CURRENT_BINARY_DIR} lets you use any library currently being built
link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

set(SOURCE_FILES 
  src/system-directory.c
  src/system-relative.c
  src/gfx.cpp
  src/hex_puzzzle.cpp
  src/i18n.cpp
  src/sfx.cpp
  src/joy.cpp
  src/text.cpp
)

## Build and link
# Add all the files needed to compile here
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(${PROJECT_NAME}
  SDL2_image
  SDL2_mixer
  SDL2_ttf
  SDL2_gfx
  SDL2
  freetype
  vorbisfile
  vorbis
  opusfile
  opus
  xmp
  bz2
  ogg
  mpg123
  modplug
  webpdemux
  webp
  jpeg
  png
  mikmod
  FLAC
  vita2d
  intl
  pthread
  SceAppUtil_stub
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceSysmodule_stub
  SceMotion_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceTouch_stub
  SceHid_stub
  SceAudioIn_stub
  m
  z
  stdc++
)

## Create Vita files
vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
# The FILE directive lets you add additional files to the VPK, the syntax is
# FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE psp2/sce_sys/icon0.png sce_sys/icon0.png
  FILE psp2/sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE psp2/sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE psp2/sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)