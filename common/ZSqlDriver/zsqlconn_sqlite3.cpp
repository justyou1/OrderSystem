#ifndef ZSQLCONN_SQLITE3_H
#define ZSQLCONN_SQLITE3_H
#include <sqlite3.h>
#include "zsqlconn.h"
#include "zsqldriver.h"
#include "Util.h"
#include <vector>
#include <map>
class ZSqlConn_sqlite3 :ZSqlConn
{
    sqlite3  * m_db;
    ZSqlConn_sqlite3(sqlite3* db = nullptr):m_db(db) {

    }
    ~ZSqlConn_sqlite3(){
        sqlite3_close(m_db);
        m_db = nullptr;
    }


public:
    static ZSqlConn* open(const char* conn_str){
        ZSqlConn_sqlite3* conn = nullptr;
        sqlite3  *db = nullptr;
        if(sqlite3_open(conn_str, &db) == 0)
        {
            conn = new ZSqlConn_sqlite3(db);
        }
        return conn;
    }
    ZResultSet * query(const char *  query_str){
        ZResultSet *  set = new ZResultSet;
        sqlite3_stmt *stmt = nullptr;    // stmt语句句柄
        int result = sqlite3_prepare_v2(m_db, query_str, -1, &stmt, nullptr);

        if (result == SQLITE_OK) {
            std::vector<std::map<std::string,ZSqlVariant>>& arr = *(new std::vector<std::map<std::string,ZSqlVariant>>);

            // 每调一次sqlite3_step()函数，stmt语句句柄就会指向下一条记录
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                int nColumn = sqlite3_column_count(stmt);
                for(int i=0;i<nColumn;i++){
                    const char* k = sqlite3_column_name(stmt,i );
                    ZSqlVariant zvalue;
                    int type= sqlite3_column_type(stmt,i );// arr[k];
                    sqlite3_column_text(stmt,2);
                    switch (type) {

                        int:
                            ;
                    }
                        = sqlite3_column_value(stmt,i );
                }
            }
        }
        else {
            PR_ERR("%s\n","query fail.");
        }

        sqlite3_finalize(stmt);
        return set;
    }
};
static struct ZSqlDriverDesc desc{
    "sqlite3",ZSqlConn_sqlite3::open
};

static __attribute((constructor)) void init(){

    ZSqlDriver::registerDatabaseDriver(&desc);
}

#endif // ZSQLCONN_SQLITE3_H
