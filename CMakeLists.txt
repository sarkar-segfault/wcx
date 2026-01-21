cmake_minimum_required(VERSION 3.10..4.2)
project(
  wcx
  LANGUAGES C
  VERSION 1.0.0
  DESCRIPTION "a rewrite of wc in pure c99"
)

add_executable(wcx sources/main.c sources/options.c sources/count.c)
target_include_directories(wcx PRIVATE headers)

target_compile_definitions(wcx PRIVATE WCX_VERSION="${PROJECT_VERSION}")
target_compile_definitions(wcx PRIVATE WCX_DESCRIPTION="${PROJECT_DESCRIPTION}")

set_target_properties(
  wcx PROPERTIES
  C_STANDARD 99
  C_EXTENSIONS OFF
  C_STANDARD_REQUIRED ON
)

include(GNUInstallDirs)
install(
  TARGETS wcx
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
