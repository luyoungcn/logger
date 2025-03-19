# 测试项目
add_executable(test_cpp main.cpp)
add_executable(test_c main_c.c)

# 链接 LoggerLib 和线程库
find_package(Threads REQUIRED)
target_link_libraries(test_cpp LoggerLib Threads::Threads)
target_link_libraries(test_c LoggerLib Threads::Threads)


# 安装可执行文件
install(TARGETS test_cpp test_c
    RUNTIME DESTINATION bin)