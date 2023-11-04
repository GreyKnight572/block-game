add_executable(Physio WIN32 src/main.c)
target_include_directories(Physio PRIVATE include)
target_sources(Physio PRIVATE src/log.c)
