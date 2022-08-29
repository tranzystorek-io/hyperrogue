add_executable(makeh makeh.cpp)

add_executable(mymake EXCLUDE_FROM_ALL mymake.cpp)
find_package(Threads REQUIRED)
target_link_libraries(mymake PRIVATE Threads::Threads)

add_executable(langen langen.cpp)
target_include_directories(langen PRIVATE lang)
