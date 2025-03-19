#include "Logger.h"
#include <spdlog/async.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <mutex>

#define LOGGER_QUEUE_SIZE 8192

std::shared_ptr<spdlog::details::thread_pool> thread_pool;

Logger& Logger::instance() {
    static Logger instance;
    return instance;
}

void Logger::init(const std::string& log_file, spdlog::level::level_enum level) {
    static std::once_flag init_flag;
    std::call_once(init_flag, [&]() {
        if (!logger_) {
            thread_pool = std::make_shared<spdlog::details::thread_pool>(LOGGER_QUEUE_SIZE, 1);
            auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(log_file, true);

            logger_ = std::make_shared<spdlog::async_logger>(
                "async_logger", spdlog::sinks_init_list{console_sink, file_sink},
                thread_pool, spdlog::async_overflow_policy::block);

            logger_->set_level(level);
            logger_->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");
            spdlog::set_default_logger(logger_);
        }
    });
}

std::shared_ptr<spdlog::logger> Logger::getLogger() {
    return logger_;
}
