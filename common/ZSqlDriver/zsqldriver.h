#ifndef ZSQLDRIVER_H
#define ZSQLDRIVER_H
#include "zsqlconn.h"
#include <string>
#include <map>
struct ZSqlDriverDesc {
    std::string drv_name;
    ZSqlConn* (*drv_open)(const char* );
};

class ZSqlDriver
{
    static std::map<std::string,ZSqlDriverDesc> m_drvs;

    friend class ZSqlConn;
public:
    static int registerDatabaseDriver(ZSqlDriverDesc* desc)
    {
        m_drvs[desc->drv_name] = *desc;
        return 0;
    }


    ZSqlDriver();
    ZSqlConn* open(const char*db_drv,const char* conn_str)
    {
        if(m_drvs.count(db_drv) == 0 && m_drvs[db_drv].drv_open == nullptr)
            return nullptr;
        return m_drvs[db_drv].drv_open(conn_str);
    }

};

#endif // ZSQLDRIVER_H
