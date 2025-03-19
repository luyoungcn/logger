#include "Logger.h"

int main() {
    // 初始化日志，将日志信息存储在 app.log 文件中，初始日志级别为 debug
    Logger::getInstance().init("app.log", spdlog::level::debug);

    int value = 6;
    // 使用 {:#06x} 格式化输出十六进制数
    LogInfo("The hex value is: {:#06x}", value);
    // 使用 % 格式符输出十六进制数
    LogInfoPrintf("The hex value using %% format is: 0x%04x", value);

    // 使用简洁接口记录不同等级的日志
    LogTrace("This is a trace message in function {} at line {}", __func__, __LINE__);
    LogDebug("This is a debug message in function {} at line {}", __func__, __LINE__);
    LogInfo("This is an info message in function {} at line {}", __func__, __LINE__);
    LogWarn("This is a warning message in function {} at line {}", __func__, __LINE__);
    LogError("This is an error message in function {} at line {}", __func__, __LINE__);
    LogCritical("This is a critical message in function {} at line {}", __func__, __LINE__);

    // 使用 % 格式符记录不同等级的日志
    LogTracePrintf("This is a printf trace message in function %s at line %d", __func__, __LINE__);
    LogDebugPrintf("This is a printf debug message in function %s at line %d", __func__, __LINE__);
    LogInfoPrintf("This is a printf info message in function %s at line %d", __func__, __LINE__);
    LogWarnPrintf("This is a printf warning message in function %s at line %d", __func__, __LINE__);
    LogErrorPrintf("This is a printf error message in function %s at line %d", __func__, __LINE__);
    LogCriticalPrintf("This is a printf critical message in function %s at line %d", __func__, __LINE__);

    // 设置日志级别为 info，此时 trace 和 debug 级别的日志将不会输出
    Logger::getInstance().setLevel(spdlog::level::info);

    LogTrace("This trace message should not be printed after setting level to info");
    LogDebug("This debug message should not be printed after setting level to info");
    LogInfo("This info message should be printed after setting level to info");
    LogWarn("This warning message should be printed after setting level to info");
    LogError("This error message should be printed after setting level to info");
    LogCritical("This critical message should be printed after setting level to info");

    return 0;
}    
