
/**
 * @file    Item.h
 * @brief   Header file for the item. Class definition for class 'Item'.
 *
 *           The file contains the include guards and class Item in which 
 *           accessors and mutators are defined.
 *
 * @author  Amit Singh Kathayat
 * @date    9/8/2020
 */

//include guards
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
    public:
        //constructor
        Item(std::string n, double p, int q);
        //Accessors
        std::string get_name() const; // get name of the item from cart.
        double get_price() const; //get the price of the item from cart.
        int get_quantity() const; //get the quantity of the item from cart.
        //Mutators
        void set_price(double p);
        void set_quantity(int q);
        //other method
        void print() const;

    private:
        std::string name; // name of the item
        double price;  // price for one item
        int quantity;  // how many item you buying.
};

#endif