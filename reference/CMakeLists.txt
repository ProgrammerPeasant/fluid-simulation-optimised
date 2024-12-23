add_library(ThreadPool STATIC
        ThreadPool.cpp
)

target_include_directories(ThreadPool PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
