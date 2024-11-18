#ifndef C_LOGGER_H
#define C_LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

void c_logger_init(const char* log_file, int level); // 初始化日志
void c_logger_info(const char* format, ...);         // 打印 INFO 日志（带格式化支持）

#ifdef __cplusplus
}
#endif

#endif // C_LOGGER_H
