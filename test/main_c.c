#include "c_logger.h"

int main() {
    c_logger_init("c_test.log", 2); // 2 对应 spdlog::level::info

    int value = 42;
    const char* text = "example";

    // 打印包含变量的日志
    c_logger_info("Logging an integer: %d", value);
    c_logger_info("Logging a string: %s", text);
    c_logger_info("Combined: value=%d, text=%s", value, text);

    return 0;
}
