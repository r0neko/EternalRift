message("Compiling for Linux!")

list(APPEND ENGINE_COMPILE_FLAGS ENGINE_TARGET_LINUX)
list(APPEND ENGINE_LIBS X11 ${CMAKE_DL_LIBS})

set(ENGINE_BACKEND_OPENGL ON)
set(ENGINE_FEATURE_EGL ON)