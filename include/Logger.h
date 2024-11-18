#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>
#include <memory>
#include <string>

class Logger {
public:
    static Logger& instance(); // 获取单例实例

    void init(const std::string& log_file, spdlog::level::level_enum level); // 初始化日志

    std::shared_ptr<spdlog::logger> getLogger(); // 获取日志器

private:
    Logger() = default;
    ~Logger() = default;

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::shared_ptr<spdlog::logger> logger_;
};

#endif // LOGGER_H
