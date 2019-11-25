#ifndef ZSQLCONN_H
#define ZSQLCONN_H
#include <string>
class ZResultSet{

};
class ZSqlVariant{

public:
    enum Type{INTEGER,TEXT};
    Type m_type;
    void* m_val;
    ZSqlVariant(Type type):m_type(type),m_val(nullptr){

    }
    ZSqlVariant(int val):ZSqlVariant(INTEGER){
        m_val = new int;
        *(int*)m_val = val;
    }
    ZSqlVariant(const char* val):ZSqlVariant(TEXT){
        m_val = new std::string(val);
    }
    int asInt(){
        return *(int*)m_val;
    }
    std::string asString(){
        return *(std::string*)m_val;
    }
    Type type(){
        return m_type;
    }

};

class ZSqlConn
{
protected:
    ZSqlConn();
public:

};

#endif // ZSQLCONN_H
