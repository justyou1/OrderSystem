#include "dishmanager.h"

DishManager::DishManager()
{

}
DishManager* DishManager::getInstance()
{
    static DishManager* instance = new DishManager;
    return instance;
}
std::vector<Dish> DishManager::getAll()
{
    return std::vector<Dish>();
}
