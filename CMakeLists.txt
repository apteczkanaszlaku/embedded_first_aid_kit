cmake_minimum_required(VERSION 3.11)

# Dodanie lokalnych komponentów
set(EXTRA_COMPONENT_DIRS "components/DFRobotDFPlayerMini")

# Pobranie esp-idf-lib
include(FetchContent)
FetchContent_Declare(
  espidflib
  GIT_REPOSITORY https://github.com/UncleRus/esp-idf-lib.git
)
FetchContent_MakeAvailable(espidflib)

# Dodanie komponentów z esp-idf-lib
list(APPEND EXTRA_COMPONENT_DIRS ${espidflib_SOURCE_DIR}/components)

# Ustawienie projektu
include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(lora)
