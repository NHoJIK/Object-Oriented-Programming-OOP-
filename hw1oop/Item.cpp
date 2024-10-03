
/**
 * @file    Item.cpp
 * @brief   This files contains the method implementation for Item 
 *          class.
 *          
 *         This file defined the name, price, and quantity for the item and get
 *          the name, price and quantity and finally print.
 *          
 * @author  Amit Singh Kathayat
 * @date    9/8/2020
 */

#include "Item.h"
#include <iomanip>
    using std::fixed;
    using std::setprecision;
#include <iostream>
    using std::cout;
//Default Constructor
// Item::Item()
// {
//     price = 0.0;
//     quantity = 0;
// }
//Constructor
Item::Item(std::string n, double p, int q)
{
    this-> name = n; // 'this->' means "self"
    this-> price = p;
    this-> quantity = q;
}
 
std::string Item::get_name() const
{
    return name;
}

double Item::get_price() const
{
    return price;
}

int Item::get_quantity() const
{
    return quantity;
}

void Item::set_price(double p)
{
price = p;
}
    
void Item::set_quantity(int q)
{
    quantity = q;
}

void Item::print( ) const 
{
    cout << fixed << setprecision( 2 );
    cout << name << '\n';
    cout << "\tPrice: $  " << price << '\n';
    cout << "\tQuantity: " << quantity << '\n';
}
