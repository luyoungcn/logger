#include "Logger.h"
#include <thread>
#include <vector>

void logMessages(int thread_id) {
    auto logger = Logger::instance().getLogger();
    for (int i = 0; i < 10; ++i) {
        logger->info("Thread {} logging message {}", thread_id, i);
    }
}

int main() {
    Logger::instance().init("cpp_test.log", spdlog::level::info);

    std::vector<std::thread> threads;
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(logMessages, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    spdlog::shutdown(); // 程序退出时安全关闭日志器
    return 0;
}
