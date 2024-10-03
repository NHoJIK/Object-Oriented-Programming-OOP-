
/**
 *******************************************************************************
 * @file    cart_test.cpp
 * @brief   Program to create a virtual shopping cart with different item in it.
 *          This program contain the class Shoppingcart to display the virtual
 *          shopping cart with different items items: chocolates, cookies,
 *          veggies, pen, mask and pencil. There is lot of changes made in the 
 *          cart so that we can see the code can run in everyway. There is 
 *          change in the qunatity of the item, there is negative quantity 
 *          of the item.
 *
 * @remarks
 *      Course:        Computer Science , Fall 2020
 *      Due Date:      Thursday, September 10
 *      Instructor:    Jason L Causey
 *
 * @author  Amit Singh Kathayat
 * @date    9/8/2020
 *******************************************************************************
**/
#include "Item.h"
#include<iostream>
    using std::cout;
#include "ShoppingCart.h"

int main()
{
    //create 5 items and item with negative quantity.
    Item item1 {"chocolate", 5.99,5};
    Item item2 {"cookies", 5.99, 7};
    Item item3 {"veggies", 3.99, 10};
    Item item4 {"mask", 1.99, 5};
    Item item5 {"mask", 2.99, 10};
    Item item6 {"pencil", 2.00, -2};
    Item item7 {"shoes", 13.99, 4}; 

    ShoppingCart walmart; // class ShoppingCart with cart name walmart.
    //add 3 items
    cout << "\nCart without any item.\n\n";
    walmart.write(); //display the shopping cart without any item in it.
    
    walmart.add(item1);
    walmart.add(item2);
    walmart.add(item3);
    walmart.add(item4);
    
    cout <<"\nAdding first 4 items to the Cart.\n\n";
    walmart.write();//display the shopping cart
    //add item not present in shopping cart
    walmart.add(item5);
    
    cout << "\n";
    cout << "Adding item5 which is not in the cart." << "\n\n";

    walmart.write();//display the shopping cart
    walmart.update_quantity("mask", 100);//update quantity of mask.
    
    cout << "\n";
    cout << "Update quantity of mask(item4) to 100." << "\n\n";

    walmart.write();//display the shopping cart
    //add item already present in the shopping cart
    walmart.add(item2);
    
    cout << "\n";
    cout << "Add the item2(cookies) which is already in the cart." << "\n\n";

    walmart.write();//display the shopping cart
    //add item with negative quantity
    walmart.add(item6);

    cout <<"\n";
    cout << "Add the item with negative quantity (item6)." << "\n\n";

    walmart.write();//display the shopping cart
    walmart.add(item7);
    
    cout << "Add the item7(shoes) which is not in the cart.\n\n";
    
    walmart.write();
    walmart.update_quantity("shoes", 0);//quantity 0, will remove pencil item
    
    cout << "Update the quantity of shoes(item7) to zero." << "\n\n";

    walmart.write();//display the shopping cart
    walmart.add(item5);//add mask item again
    
    cout << "\n";
    cout << "Add the item mask again in the cart" << "\n\n";

    walmart.write();//display the shopping cart
    walmart.remove("chocolates");//remove chocolate item
    
    cout << "\n";
    cout << "Remove the item 1(chocolate) from the cart" << "\n\n";

    walmart.write();//display the shopping cart
    walmart.update_quantity("veggies", 30);
    
    cout << "\n";
    cout << "Update the quantity of item 3(veggies) in the cart\n\n";
    
    walmart.write(); //display the shopping cart.
    
    return 0;
}






