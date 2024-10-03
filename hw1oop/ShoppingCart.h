/**
 * @file    ShoppingCart.h
 * @brief   This is the header file for the shopping cart. Class definition 
 *          for class ShoppingCart.
 *
 *          This file contains the class ShoppingCart definition to add, 
 *          update, remove, total price and display the virtual shopping cart.
 *
 * @author  Amit Singh Kathayat
 * @date    9/8/2020
 */

//include guards
#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Item.h"
#include <vector>
#include <string>
// Class declaration of ShoppingCart
class ShoppingCart
{
    public:
        void add(Item item); //add the item in the cart.
        bool update_quantity(std::string n, int q);//updates quantity of item
        bool remove(std::string n);//removes an item
        double total_value();//returns total price of shopping cart
        void write();//writes all items in shopping cart
        
    private:
        std::vector<Item> data; 
};

#endif


