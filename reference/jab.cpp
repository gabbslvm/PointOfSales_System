#include <iostream>
using namespace std;

// Print receipt function (fancy box)
// We pass customer name, quantities for each item, prices, subtotal, discount, tax, final total.
void printReceipt(char custName[], int q1, int q2, int q3, int q4, int q5, int q6,
                  int q7, int q8, int q9, int q10, int q11, int q12,
                  int p1, int p2, int p3, int p4, int p5, int p6,
                  int p7, int p8, int p9, int p10, int p11, int p12,
                  double subtotal, double discountAmt, double taxAmt, double finalTotal)
{
    cout << "+-------------------------------------------------+\n";
    cout << "|                 C++offee Receipt                |\n";
    cout << "+-------------------------------------------------+\n";
    cout << "| Customer: ";
    cout << custName;
    // pad remaining to keep box look (simple)
    cout << "\n+-------------------------------------------------+\n";
    cout << "| Item                      Qty    Total (PHP)    |\n";
    cout << "+-------------------------------------------------+\n";

    if (q1 > 0)
    {
        cout << "| Javascript (Javachip)     ";
        if (q1 < 10)
            cout << " "; // crude alignment
        cout << q1 << "     ";
        cout << (q1 * p1);
        cout << "               |\n";
    }
    if (q2 > 0)
    {
        cout << "| C#appuccino (Capuccino)   ";
        if (q2 < 10)
            cout << " ";
        cout << q2 << "     ";
        cout << (q2 * p2);
        cout << "               |\n";
    }
    if (q3 > 0)
    {
        cout << "| Cout Latte (Caramel)      ";
        if (q3 < 10)
            cout << " ";
        cout << q3 << "     ";
        cout << (q3 * p3);
        cout << "               |\n";
    }
    if (q4 > 0)
    {
        cout << "| C-trawberry Latte         ";
        if (q4 < 10)
            cout << " ";
        cout << q4 << "     ";
        cout << (q4 * p4);
        cout << "               |\n";
    }
    if (q5 > 0)
    {
        cout << "| Double Dark Roast         ";
        if (q5 < 10)
            cout << " ";
        cout << q5 << "     ";
        cout << (q5 * p5);
        cout << "               |\n";
    }
    if (q6 > 0)
    {
        cout << "| Compilepresso (Espresso)  ";
        if (q6 < 10)
            cout << " ";
        cout << q6 << "     ";
        cout << (q6 * p6);
        cout << "               |\n";
    }

    if (q7 > 0)
    {
        cout << "| JavaBeans Brownies        ";
        if (q7 < 10)
            cout << " ";
        cout << q7 << "     ";
        cout << (q7 * p7);
        cout << "               |\n";
    }
    if (q8 > 0)
    {
        cout << "| Blueberry Py              ";
        if (q8 < 10)
            cout << " ";
        cout << q8 << "     ";
        cout << (q8 * p8);
        cout << "               |\n";
    }
    if (q9 > 0)
    {
        cout << "| Peach Mango Py            ";
        if (q9 < 10)
            cout << " ";
        cout << q9 << "     ";
        cout << (q9 * p9);
        cout << "               |\n";
    }
    if (q10 > 0)
    {
        cout << "| Apple Py                  ";
        if (q10 < 10)
            cout << " ";
        cout << q10 << "     ";
        cout << (q10 * p10);
        cout << "               |\n";
    }
    if (q11 > 0)
    {
        cout << "| Byte-sized Cookie         ";
        if (q11 < 10)
            cout << " ";
        cout << q11 << "     ";
        cout << (q11 * p11);
        cout << "               |\n";
    }
    if (q12 > 0)
    {
        cout << "| RAM-en Noodles            ";
        if (q12 < 10)
            cout << " ";
        cout << q12 << "     ";
        cout << (q12 * p12);
        cout << "               |\n";
    }

    cout << "+-------------------------------------------------+\n";
    // Print financial summary with spacing that roughly fits the box
    cout << "| Subtotal:               ";
    if (subtotal < 1000)
        cout << " ";
    cout << subtotal << "           |\n";
    cout << "| Discount (if any):     -";
    if (discountAmt < 100)
        cout << " ";
    cout << discountAmt << "           |\n";
    cout << "| VAT (12%):              +";
    if (taxAmt < 100)
        cout << " ";
    cout << taxAmt << "           |\n";
    cout << "+-------------------------------------------------+\n";
    cout << "| FINAL TOTAL:            ";
    if (finalTotal < 1000)
        cout << " ";
    cout << finalTotal << "           |\n";
    cout << "+-------------------------------------------------+\n";
    cout << "|       Thank you! Visit again :)                 |\n";
    cout << "+-------------------------------------------------+\n";
}

int main()
{
    // Inventory stock for each menu item (initial stock)
    int stock_javachip = 10, stock_capuccino = 10, stock_latte = 10, stock_strawberry = 10;
    int stock_darkroast = 10, stock_espresso = 10;
    int stock_brownies = 10, stock_blueberry = 10, stock_peach = 10, stock_apple = 10, stock_cookie = 10, stock_ramen = 10;

    // Prices (as agreed)
    int price_javachip = 100, price_capuccino = 120, price_latte = 110, price_strawberry = 115;
    int price_darkroast = 105, price_espresso = 90;
    int price_brownies = 70, price_blueberry = 80, price_peach = 75, price_apple = 75, price_cookie = 50, price_ramen = 95;

    int mainLoop = 1;
    do
    {
        cout << "\n===== Welcome to C++offee POS System =====\n";
        cout << "Are you:\n1. Employee\n2. Customer\nChoice: ";
        int userType;
        cin >> userType;

        if (userType == 1)
        {
            // Employee mode with password retry (3 attempts)
            int correctPassword = 1234;
            int attempts = 0;
            int passOK = 0;
            while (attempts < 3)
            {
                int entered;
                cout << "Enter Password: ";
                cin >> entered;
                if (entered == correctPassword)
                {
                    passOK = 1;
                    break;
                }
                else
                {
                    attempts = attempts + 1;
                    cout << "Wrong password. Attempts left: " << (3 - attempts) << "\n";
                }
            }
            if (passOK == 0)
            {
                cout << "Too many wrong attempts. Returning to main menu.\n";
            }
            else
            {
                int empLoop = 1;
                while (empLoop == 1)
                {
                    cout << "\n--- Inventory Management ---\n";
                    cout << "1. Create/Add Stock\n2. Retrieve/View Stock\n3. Update Stock (set exact values)\n4. Delete Stock (set to 0)\n5. Exit to Main\nChoice: ";
                    int choice;
                    cin >> choice;
                    if (choice == 1)
                    {
                        int add;
                        cout << "Add to Javascript (Javachip): ";
                        cin >> add;
                        stock_javachip += add;
                        cout << "Add to C#appuccino (Capuccino): ";
                        cin >> add;
                        stock_capuccino += add;
                        cout << "Add to Cout Latte (Caramel Latte): ";
                        cin >> add;
                        stock_latte += add;
                        cout << "Add to C-trawberry Latte: ";
                        cin >> add;
                        stock_strawberry += add;
                        cout << "Add to Double Dark Roast: ";
                        cin >> add;
                        stock_darkroast += add;
                        cout << "Add to Compilepresso (Espresso): ";
                        cin >> add;
                        stock_espresso += add;
                        cout << "Add to JavaBeans Brownies: ";
                        cin >> add;
                        stock_brownies += add;
                        cout << "Add to Blueberry Py: ";
                        cin >> add;
                        stock_blueberry += add;
                        cout << "Add to Peach Mango Py: ";
                        cin >> add;
                        stock_peach += add;
                        cout << "Add to Apple Py: ";
                        cin >> add;
                        stock_apple += add;
                        cout << "Add to Byte-sized Cookie: ";
                        cin >> add;
                        stock_cookie += add;
                        cout << "Add to RAM-en Noodles: ";
                        cin >> add;
                        stock_ramen += add;
                    }
                    else if (choice == 2)
                    {
                        cout << "\n--- Current Inventory ---\n";
                        cout << "Javascript (Javachip): " << stock_javachip << "\n";
                        cout << "C#appuccino (Capuccino): " << stock_capuccino << "\n";
                        cout << "Cout Latte (Caramel Latte): " << stock_latte << "\n";
                        cout << "C-trawberry Latte: " << stock_strawberry << "\n";
                        cout << "Double Dark Roast: " << stock_darkroast << "\n";
                        cout << "Compilepresso (Espresso): " << stock_espresso << "\n";
                        cout << "JavaBeans Brownies: " << stock_brownies << "\n";
                        cout << "Blueberry Py: " << stock_blueberry << "\n";
                        cout << "Peach Mango Py: " << stock_peach << "\n";
                        cout << "Apple Py: " << stock_apple << "\n";
                        cout << "Byte-sized Cookie: " << stock_cookie << "\n";
                        cout << "RAM-en Noodles: " << stock_ramen << "\n";
                    }
                    else if (choice == 3)
                    {
                        int ns;
                        cout << "Set new stock for Javascript (Javachip): ";
                        cin >> ns;
                        stock_javachip = ns;
                        cout << "Set new stock for C#appuccino (Capuccino): ";
                        cin >> ns;
                        stock_capuccino = ns;
                        cout << "Set new stock for Cout Latte (Caramel Latte): ";
                        cin >> ns;
                        stock_latte = ns;
                        cout << "Set new stock for C-trawberry Latte: ";
                        cin >> ns;
                        stock_strawberry = ns;
                        cout << "Set new stock for Double Dark Roast: ";
                        cin >> ns;
                        stock_darkroast = ns;
                        cout << "Set new stock for Compilepresso (Espresso): ";
                        cin >> ns;
                        stock_espresso = ns;
                        cout << "Set new stock for JavaBeans Brownies: ";
                        cin >> ns;
                        stock_brownies = ns;
                        cout << "Set new stock for Blueberry Py: ";
                        cin >> ns;
                        stock_blueberry = ns;
                        cout << "Set new stock for Peach Mango Py: ";
                        cin >> ns;
                        stock_peach = ns;
                        cout << "Set new stock for Apple Py: ";
                        cin >> ns;
                        stock_apple = ns;
                        cout << "Set new stock for Byte-sized Cookie: ";
                        cin >> ns;
                        stock_cookie = ns;
                        cout << "Set new stock for RAM-en Noodles: ";
                        cin >> ns;
                        stock_ramen = ns;
                    }
                    else if (choice == 4)
                    {
                        stock_javachip = 0;
                        stock_capuccino = 0;
                        stock_latte = 0;
                        stock_strawberry = 0;
                        stock_darkroast = 0;
                        stock_espresso = 0;
                        stock_brownies = 0;
                        stock_blueberry = 0;
                        stock_peach = 0;
                        stock_apple = 0;
                        stock_cookie = 0;
                        stock_ramen = 0;
                        cout << "All stock cleared!\n";
                    }
                    else if (choice == 5)
                    {
                        empLoop = 0;
                    }
                    else
                    {
                        cout << "Invalid choice.\n";
                    }
                } // end employee loop
            }
        } // end employee branch

        else if (userType == 2)
        {
            // Customer flow
            char customerName[50];
            cout << "Enter Customer Name (one word): ";
            cin >> customerName;

            // ordered quantities (start at 0)
            int oq1 = 0, oq2 = 0, oq3 = 0, oq4 = 0, oq5 = 0, oq6 = 0, oq7 = 0, oq8 = 0, oq9 = 0, oq10 = 0, oq11 = 0, oq12 = 0;
            int ordering = 1;
            while (ordering == 1)
            {
                cout << "\n--- MENU ---\n";
                cout << "Coffee & Drinks:\n";
                cout << "1) Javascript (Javachip) - PHP " << price_javachip << "   [" << stock_javachip << " left]\n";
                cout << "2) C#appuccino (Capuccino) - PHP " << price_capuccino << "   [" << stock_capuccino << " left]\n";
                cout << "3) Cout Latte (Caramel Latte) - PHP " << price_latte << "   [" << stock_latte << " left]\n";
                cout << "4) C-trawberry Latte - PHP " << price_strawberry << "   [" << stock_strawberry << " left]\n";
                cout << "5) Double Dark Roast - PHP " << price_darkroast << "   [" << stock_darkroast << " left]\n";
                cout << "6) Compilepresso (Espresso) - PHP " << price_espresso << "   [" << stock_espresso << " left]\n";
                cout << "Pastries:\n";
                cout << "7) JavaBeans Brownies - PHP " << price_brownies << "   [" << stock_brownies << " left]\n";
                cout << "8) Blueberry Py - PHP " << price_blueberry << "   [" << stock_blueberry << " left]\n";
                cout << "9) Peach Mango Py - PHP " << price_peach << "   [" << stock_peach << " left]\n";
                cout << "10) Apple Py - PHP " << price_apple << "   [" << stock_apple << " left]\n";
                cout << "11) Byte-sized Cookie - PHP " << price_cookie << "   [" << stock_cookie << " left]\n";
                cout << "12) RAM-en Noodles - PHP " << price_ramen << "   [" << stock_ramen << " left]\n";
                cout << "13) Proceed to Payment\n";
                cout << "Choice: ";
                int menuChoice;
                cin >> menuChoice;

                if (menuChoice >= 1 && menuChoice <= 12)
                {
                    cout << "How many? ";
                    int qty;
                    cin >> qty;
                    if (qty <= 0)
                    {
                        cout << "Enter a positive quantity.\n";
                    }
                    else
                    {
                        // check stock and reduce stock and add to ordered qty
                        if (menuChoice == 1)
                        {
                            if (qty <= stock_javachip)
                            {
                                stock_javachip -= qty;
                                oq1 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 2)
                        {
                            if (qty <= stock_capuccino)
                            {
                                stock_capuccino -= qty;
                                oq2 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 3)
                        {
                            if (qty <= stock_latte)
                            {
                                stock_latte -= qty;
                                oq3 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 4)
                        {
                            if (qty <= stock_strawberry)
                            {
                                stock_strawberry -= qty;
                                oq4 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 5)
                        {
                            if (qty <= stock_darkroast)
                            {
                                stock_darkroast -= qty;
                                oq5 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 6)
                        {
                            if (qty <= stock_espresso)
                            {
                                stock_espresso -= qty;
                                oq6 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 7)
                        {
                            if (qty <= stock_brownies)
                            {
                                stock_brownies -= qty;
                                oq7 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 8)
                        {
                            if (qty <= stock_blueberry)
                            {
                                stock_blueberry -= qty;
                                oq8 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 9)
                        {
                            if (qty <= stock_peach)
                            {
                                stock_peach -= qty;
                                oq9 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 10)
                        {
                            if (qty <= stock_apple)
                            {
                                stock_apple -= qty;
                                oq10 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 11)
                        {
                            if (qty <= stock_cookie)
                            {
                                stock_cookie -= qty;
                                oq11 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                        else if (menuChoice == 12)
                        {
                            if (qty <= stock_ramen)
                            {
                                stock_ramen -= qty;
                                oq12 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough stock.\n";
                        }
                    }
                }
                else if (menuChoice == 13)
                {
                    // proceed to payment
                    // But user may want to come back to ordering after seeing subtotal; however per request we loop ordering until they choose to pay. So break to payment now.
                    ordering = 0;
                }
                else
                {
                    cout << "Invalid menu choice.\n";
                }

                if (ordering == 1)
                {
                    // ask if they want to continue ordering or go to payment
                    cout << "Do you want to order more? (Y/N): ";
                    char cont;
                    cin >> cont;
                    if (cont == 'N' || cont == 'n')
                    {
                        ordering = 0;
                    }
                }
            } // end ordering loop

            // Calculate subtotal
            double subtotal = 0.0;
            subtotal += oq1 * price_javachip;
            subtotal += oq2 * price_capuccino;
            subtotal += oq3 * price_latte;
            subtotal += oq4 * price_strawberry;
            subtotal += oq5 * price_darkroast;
            subtotal += oq6 * price_espresso;
            subtotal += oq7 * price_brownies;
            subtotal += oq8 * price_blueberry;
            subtotal += oq9 * price_peach;
            subtotal += oq10 * price_apple;
            subtotal += oq11 * price_cookie;
            subtotal += oq12 * price_ramen;

            if (subtotal <= 0.0)
            {
                cout << "No items ordered. Returning to main menu.\n";
            }
            else
            {
                // Ask for Senior / PWD discount
                cout << "Are you Senior/PWD? (Y/N): ";
                char discAns;
                cin >> discAns;
                double discountAmt = 0.0;
                if (discAns == 'Y' || discAns == 'y')
                {
                    discountAmt = subtotal * 0.20; // 20% discount
                }

                double afterDiscount = subtotal - discountAmt;
                double taxAmt = afterDiscount * 0.12; // 12% VAT
                double finalTotal = afterDiscount + taxAmt;

                // Print receipt using the void function
                printReceipt(customerName,
                             oq1, oq2, oq3, oq4, oq5, oq6,
                             oq7, oq8, oq9, oq10, oq11, oq12,
                             price_javachip, price_capuccino, price_latte, price_strawberry, price_darkroast, price_espresso,
                             price_brownies, price_blueberry, price_peach, price_apple, price_cookie, price_ramen,
                             subtotal, discountAmt, taxAmt, finalTotal);

                // Payment simulation (simple)
                cout << "Enter payment amount (PHP): ";
                double paid;
                cin >> paid;
                while (paid < finalTotal)
                {
                    cout << "Insufficient payment. Enter amount again: ";
                    cin >> paid;
                }
                double change = paid - finalTotal;
                cout << "Payment accepted. Change: PHP " << change << "\n";
                cout << "Order complete. Returning to main menu.\n";
            }
        } // end customer branch

        else
        {
            cout << "Invalid selection. Returning to main menu.\n";
        }

        cout << "\nDo you want to return to main menu? (1-Yes / 0-No): ";
        cin >> mainLoop;
    } while (mainLoop == 1);

    cout << "Thank you for using C++offee POS. Goodbye!\n";
    return 0;
}
