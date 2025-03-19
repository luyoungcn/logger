#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <cstdarg>
#include <cstdio>
#include <string>

class Logger {
public:
    static Logger& getInstance();

    void init(const std::string& logFileName, spdlog::level::level_enum level = spdlog::level::info);

    void setLevel(spdlog::level::level_enum level);

    template<typename... Args>
    void trace(const char* fmt, const Args&... args) {
        if (logger_) {
            logger_->trace(fmt, args...);
        }
    }

    template<typename... Args>
    void debug(const char* fmt, const Args&... args) {
        if (logger_) {
            logger_->debug(fmt, args...);
        }
    }

    template<typename... Args>
    void info(const char* fmt, const Args&... args) {
        if (logger_) {
            logger_->info(fmt, args...);
        }
    }

    template<typename... Args>
    void warn(const char* fmt, const Args&... args) {
        if (logger_) {
            logger_->warn(fmt, args...);
        }
    }

    template<typename... Args>
    void error(const char* fmt, const Args&... args) {
        if (logger_) {
            logger_->error(fmt, args...);
        }
    }

    template<typename... Args>
    void critical(const char* fmt, const Args&... args) {
        if (logger_) {
            logger_->critical(fmt, args...);
        }
    }

    // 添加 printf 风格的日志记录方法
    void trace_printf(const char* fmt, ...) {
        if (logger_) {
            va_list args;
            va_start(args, fmt);
            std::string message = vformat_string(fmt, args);
            va_end(args);
            logger_->trace(message);
        }
    }

    void debug_printf(const char* fmt, ...) {
        if (logger_) {
            va_list args;
            va_start(args, fmt);
            std::string message = vformat_string(fmt, args);
            va_end(args);
            logger_->debug(message);
        }
    }

    void info_printf(const char* fmt, ...) {
        if (logger_) {
            va_list args;
            va_start(args, fmt);
            std::string message = vformat_string(fmt, args);
            va_end(args);
            logger_->info(message);
        }
    }

    void warn_printf(const char* fmt, ...) {
        if (logger_) {
            va_list args;
            va_start(args, fmt);
            std::string message = vformat_string(fmt, args);
            va_end(args);
            logger_->warn(message);
        }
    }

    void error_printf(const char* fmt, ...) {
        if (logger_) {
            va_list args;
            va_start(args, fmt);
            std::string message = vformat_string(fmt, args);
            va_end(args);
            logger_->error(message);
        }
    }

    void critical_printf(const char* fmt, ...) {
        if (logger_) {
            va_list args;
            va_start(args, fmt);
            std::string message = vformat_string(fmt, args);
            va_end(args);
            logger_->critical(message);
        }
    }

private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::shared_ptr<spdlog::logger> logger_;

    std::string vformat_string(const char* fmt, va_list args) {
        va_list args_copy;
        va_copy(args_copy, args);
        int len = std::vsnprintf(nullptr, 0, fmt, args_copy);
        va_end(args_copy);

        std::string result(len + 1, '\0');
        va_copy(args_copy, args);
        std::vsnprintf(&result[0], len + 1, fmt, args_copy);
        va_end(args_copy);

        result.resize(len);
        return result;
    }
};

// 提供简洁的日志调用接口
#define LogTrace(...) Logger::getInstance().trace(__VA_ARGS__)
#define LogDebug(...) Logger::getInstance().debug(__VA_ARGS__)
#define LogInfo(...) Logger::getInstance().info(__VA_ARGS__)
#define LogWarn(...) Logger::getInstance().warn(__VA_ARGS__)
#define LogError(...) Logger::getInstance().error(__VA_ARGS__)
#define LogCritical(...) Logger::getInstance().critical(__VA_ARGS__)

// 提供简洁的 printf 风格日志调用接口
#define LogTracePrintf(...) Logger::getInstance().trace_printf(__VA_ARGS__)
#define LogDebugPrintf(...) Logger::getInstance().debug_printf(__VA_ARGS__)
#define LogInfoPrintf(...) Logger::getInstance().info_printf(__VA_ARGS__)
#define LogWarnPrintf(...) Logger::getInstance().warn_printf(__VA_ARGS__)
#define LogErrorPrintf(...) Logger::getInstance().error_printf(__VA_ARGS__)
#define LogCriticalPrintf(...) Logger::getInstance().critical_printf(__VA_ARGS__)

#endif // LOGGER_H    
