#include "c_logger.h"
#include "Logger.h"
#include <cstdarg>
#include <vector>
#include <cstdio>

void c_logger_init(const char* log_file, int level) {
    Logger::instance().init(log_file, static_cast<spdlog::level::level_enum>(level));
}

void c_logger_info(const char* format, ...) {
    constexpr size_t BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    // 格式化日志内容
    va_list args;
    va_start(args, format);
    std::vsnprintf(buffer, BUFFER_SIZE, format, args);
    va_end(args);

    // 打印日志
    auto logger = Logger::instance().getLogger();
    logger->info(buffer);
}
