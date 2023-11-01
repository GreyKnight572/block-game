if (WIN32)

add_library(WindowsBase STATIC src/windows/window.c src/windows/message.c)
target_include_directories(WindowsBase PRIVATE include/windows)

endif (WIN32)

if (UNIX)

# Build POSIX base libraries

endif (UNIX)

# Build game libraries

if (WIN32)

add_executable(Physio WIN32 src/main.c)
target_include_directories(Physio PRIVATE include/windows)
target_link_libraries(Physio WindowsBase)

endif (WIN32)

if (UNIX)

# Build executable for POSIX

endif (UNIX)
