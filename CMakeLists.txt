cmake_minimum_required(VERSION 3.12..4.3)
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

target_compile_features(wcx PRIVATE c_std_99)

include(GNUInstallDirs)
install(
  TARGETS wcx
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
