#ifndef DISHMANAGER_H
#define DISHMANAGER_H
#include <vector>
#include "dish.h"
//菜品项管理类
class DishManager
{
    DishManager();
public:
    static DishManager* getInstance();
    std::vector<Dish> getAll();
    int add(const char* name,const char* describe,const char* pic);
};

#endif // DISHMANAGER_H
