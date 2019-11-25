#ifndef DISH_H
#define DISH_H
#include <string>
//菜品项
class Dish
{
public:
    Dish();
    void print();
private:
    std::string m_name;
    std::string m_describe;
    std::string m_pic;
};

#endif // DISH_H
