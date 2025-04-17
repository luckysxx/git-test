#include <stdio.h>
#include <iostream>
#include <mysql/mysql.h>

using namespace std;

int main() {
    MYSQL conn;
    mysql_init(&conn);

    // 从安全途径获取密码（此处仅为示例）
    const char* password = "lhj20060818"; 

    if (mysql_real_connect(&conn, "localhost", "root", password, "test", 0, NULL, CLIENT_FOUND_ROWS)) {
        cout << "connect success" << endl;

        // 执行 INSERT 语句
        int res = mysql_query(&conn, "INSERT INTO user (id, name) VALUES ('2', 'lucky')");
        if (res) {
            cerr << "执行失败: " << mysql_error(&conn) << endl;
        } else {
            cout << "数据插入成功" << endl;
        }

        mysql_close(&conn);
    } else {
        cerr << "连接失败: " << mysql_error(&conn) << endl;
    }

    return 0;
}