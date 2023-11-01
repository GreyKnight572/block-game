### ====================  WINDOWS OS LIBRARY  ==================== ###

if (WIN32)

add_library(WindowsBase STATIC src/windows/window.c)
target_include_directories(WindowsBase PRIVATE include/windows)

endif (WIN32)

### =====================  POSIX OS LIBRARY  ===================== ###

if (UNIX)

endif (UNIX)

### ======================  ENGINE LIBRARY  ====================== ###

### ====================  WINDOWS EXECUTABLE  ==================== ###

if (WIN32)

add_executable(Physio WIN32 src/main.c)
target_include_directories(Physio PRIVATE include/windows)
target_link_libraries(Physio WindowsBase)

endif (WIN32)

### =====================  POSIX EXECUTABLE  ===================== ###

if (UNIX)

endif (UNIX)
