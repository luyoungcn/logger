cmake_minimum_required(VERSION 3.14)
project(LoggingSystem LANGUAGES C CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 配置构建选项
option(BUILD_SHARED_LIBS "Build shared libraries instead of static ones" ON)  # 开启动态库构建
option(USE_EXTERNAL_SPDLOG "Use external spdlog submodule" ON)  # 使用本地 spdlog 子模块

# 引入 spdlog 子模块
if(USE_EXTERNAL_SPDLOG)
    add_subdirectory(external/spdlog)
    include_directories(${CMAKE_SOURCE_DIR}/external/spdlog/include)
endif()

# 添加头文件路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 设置源文件和库
set(SOURCES
    src/Logger.cpp
    src/c_logger.cpp
)

# 创建库（根据 BUILD_SHARED_LIBS 构建动态或静态库）
add_library(LoggerLib ${SOURCES})

# 链接 spdlog 到 LoggerLib
target_link_libraries(LoggerLib PRIVATE spdlog)

# 设置安装路径
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

# 安装头文件
install(DIRECTORY include/ DESTINATION include)

# 安装库文件
install(TARGETS LoggerLib
    ARCHIVE DESTINATION lib             # 静态库路径
    LIBRARY DESTINATION lib             # 动态库路径
    RUNTIME DESTINATION bin             # Windows 的动态库路径 (.dll)
)

# 包含测试目录
add_subdirectory(test)