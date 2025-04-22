#include <sw/redis++/redis++.h>
#include <iostream>

int main() {
    try {
        // 连接到本地 Redis 服务器（默认端口 6379）
        sw::redis::Redis redis("tcp://127.0.0.1:6379");

        // 设置键值对
        redis.set("name", "Andy");

        // 获取键的值（返回类型为 OptionalString，需检查是否存在）
        auto value = redis.get("name");
        if (value) {
            std::cout << "Name: " << *value << std::endl;  // 输出 "Andy"
        }

        // 其他操作：如列表、哈希等
        redis.lpush("tasks", {"task1", "task2"});
    } catch (const sw::redis::Error &e) {
        std::cerr << "Redis error: " << e.what() << std::endl;
    }
    return 0;
}