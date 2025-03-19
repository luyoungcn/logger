#include "Logger.h"
#include <iostream>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::init(const std::string& logFileName, spdlog::level::level_enum level) {
    try {
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFileName, true);

        std::vector<spdlog::sink_ptr> sinks{consoleSink, fileSink};
        logger_ = std::make_shared<spdlog::logger>(logFileName, begin(sinks), end(sinks));
        spdlog::register_logger(logger_);
        logger_->set_level(level);

        // logger_->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v%$");
	consoleSink->set_pattern("%^[%Y-%m-%d %H:%M:%S:%e] [%n] [tid: %t] [%l] %v%$");
	fileSink->set_pattern("[%Y-%m-%d %H:%M:%S:%e] [%n] [tid: %t] [%l] %v");

        logger_->flush_on(level);
    } catch (const spdlog::spdlog_ex& ex) {
        std::cerr << "Log initialization failed: " << ex.what() << std::endl;
    }
}

void Logger::setLevel(spdlog::level::level_enum level) {
    if (logger_) {
        logger_->set_level(level);
        logger_->flush_on(level);
    }
}    
