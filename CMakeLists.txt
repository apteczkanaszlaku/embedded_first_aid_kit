cmake_minimum_required(VERSION 3.11)

# add local components
set(EXTRA_COMPONENT_DIRS "components/DFRobotDFPlayerMini")

# download esp-idf-lib
include(FetchContent)
FetchContent_Declare(
  espidflib
  GIT_REPOSITORY https://github.com/UncleRus/esp-idf-lib.git
)
FetchContent_MakeAvailable(espidflib)

# add components
list(APPEND EXTRA_COMPONENT_DIRS ${espidflib_SOURCE_DIR}/components)

# setup project
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(lora)
