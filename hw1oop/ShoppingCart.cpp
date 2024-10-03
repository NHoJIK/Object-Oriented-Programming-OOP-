/**
 * @file    ShoppingCart.cpp
 * @brief   This files contains the method implementation for ShoppingCart 
 *          class.
 *          
 *          This file contains different methods: add(), update_quantity(),
 *          remove(),total_value, and write() to implements different function
 *          to present a virtual shopping cart.
 *          
 * @author  Amit Singh Kathayat
 * @date    9/8/2020
 */
#include<iostream>
    using std::cout;
#include <vector>   
    using std::vector;
#include <iomanip>
    using std::setw;
    using std::right;
    using std::left;
#include "ShoppingCart.h"

/**
 * @brief       This function contains the item to add to the shopping cart.
 *
 * @detailed    Check different conditions to add the item in the shopping cart.
 *              If the item quantity is less than 1, it should not added to the
 *              cart, and then check for the item if it is already exist and 
 *              then  update the quantity of the item and at last add the item.
 *
 * @return  no return.
**/

void ShoppingCart::add(Item item)
{
    // Check quantity is less than 1
    if(item.get_quantity() < 1)
    {
        // do nothing
    }

    else // the quantity is larger than or equals 1
    {
        // search the existuing items in cart
        bool alreadyItem = false; // assume no same item
        for(vector<Item>::size_type i = 0; i < data.size(); i++)
        {
            if( data[i].get_name() == item.get_name() && 
                data[i].get_price() == item.get_price()) // Check the item 
                                                            //if already exists
            {
                alreadyItem = true;
                // Update the quantity
                data[i].set_quantity(data[i].get_quantity() 
                + item.get_quantity());
            }

        }

        if (!alreadyItem) // in case that no same item in the cart
        {
            data.push_back(item); //add the item at the end in the cart.
        }
    }

}

/**
 * @brief       This function check for the update of the item.
 *
 * @detailed    check with the name and then check for the negative quantity 
 *              and then earase the date.
 * @return      return true if the quantity is negative and also return true
 *              when add new item otherwise return false 
**/

bool ShoppingCart::update_quantity(std::string n, int q)

{
    for(vector<Item>::size_type i=0; i < data.size(); i++)
    {
// Check the item with name
        if(data[i].get_name() == n)
            {
                if( q <= 0) // If quantity is negative
                {
                    data.erase(data.begin() + i); // Remove the item
                    return true;
                }

                else
                {
                    data[i].set_quantity(q); // Otherwise set new value
                    return true;
                }   
            }
    }

return false; // Otherwise return false if data not found

}

/**
 * @brief       This function remove the item form the cart using different 
 *              conditions.
 *
 * @detailed    First search for the item and check item with the name and then
 *              remove the item.
 *
 *  @return      return true when the item is removed otherwise return false.
 * 
**/

bool ShoppingCart::remove(std::string n)
{

for(vector<Item>::size_type i=0; i < data.size(); i++) /// Search for item
{

    if(data[i].get_name() == n) // Check the item with name

    {
        data.erase(data.begin() + i); // Remove item
        return true;
    }

}

return false; // Otherwise return false

}

/**
 * @brief       This function displays the data of the shopping cart.
 *
 * @detailed    This functions get all the data and then get the total price of
 *               the cart with its name, price and quantity.
 *  
 * @return      return total_price of the data.   
**/

void ShoppingCart::write() 
{

cout << setw(5) << left << "Name" << setw(18) << right << "Price " 
     <<  setw(14) << "Quantity"; // Display shopping cart details
                                                    
for(vector<Item>::size_type i = 0; i < data.size(); i++)

    {
        cout << "\n" << setw(9) << left << data[i].get_name() 
        << setw(12) << right<< data[i].get_price() << setw(12) 
        << right << data[i].get_quantity(); // Display each item name 
                      //with its price and quantity.
    }

cout << "\n\nTotal Value: " << total_value()<<"\n\n";

}

double ShoppingCart::total_value()

{
    double total_value = 0;

    for(vector<Item>::size_type i=0; i < data.size(); i++)

        {
            total_value += data[i].get_price() * data[i].get_quantity(); 
        //total price and quantity of each item and assigned to total_value.
        }

return total_value; // Return total price

}