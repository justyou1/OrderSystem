#include "dish.h"
#include "Util.h"
Dish::Dish()
{

}
void Dish::print()
{
    PR_INFO("dish-%s-%s_%s",m_name.c_str(),m_describe.c_str(),m_pic.c_str());
}
