#include <iostream>
using namespace std;

// for clearing inputs
void clearInput()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

void sysClear()
{
    cout << "\n Press ENTER to continue...\n";
    cin.get();
    system("clear");
}

// q for quantity, p for price
void receipt(string customerName, string items[],
             char discount, int oq[], float price[],
             int totItem, float subtotal, float discountAmt,
             float taxAmt, float finalTotal)
{
    cout << "\n================================================\n";
    cout << "\t\t      RECEIPT\n";
    cout << "================================================\n";
    cout << "Customer: " << customerName << "\n\n";

    for (int i = 0; i < totItem; i++)
    {
        if (oq[i] > 0)
        {
            cout << "\t" << items[i] << " x " << oq[i] << "\t= " << oq[i] * price[i] << "\n";
        }
    }

    cout << "------------------------------------------------\n";
    cout << "\tSubtotal\t: " << subtotal << "\n";

    if (discount == 'Y' || discount == 'y')
    {
        cout << "\tDiscount\t: -" << discountAmt << "\n";
    }

    else if (discount == 'N' || discount == 'n')
    {
        cout << "\tVAT (12%)\t: +" << taxAmt << "\n";
    }
    cout << "\tFINAL TOTAL\t: " << finalTotal << "\n";
} // end of void function

// thank you message
void message()
{
    cout << "------------------------------------------------\n";
    cout << "\tThank you! Visit C++offee again! :)\n";
    cout << "================================================\n";
}

int main()
{
    // menu
    string items[12] =
        {
            "Javascript (Javachip)",
            "C#appuccino (Capuccino)",
            "Cout Latte (Caramel)",
            "C-trawberry Latte",
            "Double Dark Roast",
            "Compilepresso (Espresso)",
            "JavaBeans Brownies",
            "Blueberry Py",
            "Peach Mango Py",
            "Apple Py",
            "Byte-sized Cookie",
            "RAM-en Noodles"};

    // price of menu
    float price[12] =
        {
            100, // Javascript (Javachip)
            120, // C#appuccino (Capuccino)
            110, // Cout Latte (Caramel)
            115, // C-trawberry Latte
            105, // Double Dark Roast
            90,  // Compilepresso (Espresso)
            70,  // JavaBeans Brownies
            80,  // Blueberry Py
            75,  // Peach Mango Py
            75,  // Apple Py
            50,  // Byte-sized Cookie
            95   // RAM-en Noodles
        };

    // initial stocks for menu
    int stocks[12] =
        {
            10, // Javascript (Javachip)
            10, // C#appuccino (Capuccino)
            10, // Cout Latte (Caramel)
            10, // C-trawberry Latte
            10, // Double Dark Roast
            10, // Compilepresso (Espresso)
            10, // JavaBeans Brownies
            10, // Blueberry Py
            10, // Peach Mango Py
            10, // Apple Py
            10, // Byte-sized Cookie
            10  // RAM-en Noodles
        };

    int oq[12] =
        {
            0, // Javascript (Javachip)
            0, // C#appuccino (Capuccino)
            0, // Cout Latte (Caramel)
            0, // C-trawberry Latte
            0, // Double Dark Roast
            0, // Compilepresso (Espresso)
            0, // JavaBeans Brownies
            0, // Blueberry Py
            0, // Peach Mango Py
            0, // Apple Py
            0, // Byte-sized Cookie
            0, // RAM-en Noodles
        };

    int totItem = sizeof(items) / sizeof(items[0]); // 12

    int mainLoop = 1, user, crctPass = 1234, entered, attempts = 0, empLoop = 1, choice, add, ns, np, ordering = 1, mChoice, qty,
        paid;

    float subtotal = 0, discountAmt = 0, taxAmt = 0, finalTotal = 0;
    char discount;
    bool passOK = false;
    string customerName;

    do
    {
        system("clear");
        cout << "\n===== Welcome to C++offee =====\n";
        cout << "\n1. Admin\n2. Cashier\nChoice: ";
        cin >> user;
        if (cin.fail())
        {
            clearInput();
            continue;
        }

        // employee loop (CRUD)
        if (user == 1)
        {
            system("clear");

            empLoop = 1;
            bool passOK = false;
            attempts = 0;
            while (attempts < 3)
            {
                cout << "Enter 4-digit Password: ";
                cin >> entered;
                if (cin.fail())
                {
                    clearInput();
                    cout << "Invalid. Password must be 4 digits only.\n";
                    attempts++;
                    cout << "Attempts left: " << 3 - attempts << endl;
                    clearInput();
                    sysClear();
                    continue;
                }

                if (entered < 1000 || entered > 9999)
                {
                    cout << "Password must be exactly 4 Digits.\n";
                    attempts++;
                    clearInput();
                    cin.ignore();
                    sysClear();
                    continue;
                }
                if (entered == crctPass)
                {
                    passOK = true;
                    cout << "Access granted!\n";
                    sysClear();
                    break;
                }
                else
                {
                    attempts++;
                    cout << "Wrong password. Attempts left: " << 3 - attempts << "\n";
                    cin.ignore();
                    cin.get();
                    sysClear();
                } // end of if-else
            } // end of while loop for attempts

            if (!passOK)
            {
                if (attempts >= 3)
                {
                    cout << "Too many wrong attempts. Returning to main menu...\n";
                }
                else
                {
                    cout << "Access denied. Returning to main menu...\n";
                }
                clearInput();
                sysClear();
                continue;
            }
            else
            {
                while (empLoop == 1)
                {
                    cout << "\n--- Inventory Management ---\n";
                    cout << "1. Add Stock\n2. View Stock\n3. Update Stock\n4. Delete All Stock\n5. Change Password\n6. Exit\nChoice: ";
                    cin >> choice;
                    system("clear");
                    if (cin.fail())
                    {
                        clearInput();
                        continue;
                    }
                    system("clear");

                    switch (choice)
                    {
                    case 1:
                        for (int i = 0; i < totItem; i++)
                        {
                            bool crctInput = false;
                            while (crctInput == false)
                            {
                                cout << "Add to " << items[i] << ": ";
                                cin >> add;

                                if (cin.fail())
                                {
                                    clearInput();
                                    cout << "Invalid input. Try again." << endl;
                                }
                                else if (add < 0)
                                {
                                    cout << "Cannot add negative stock.\n";
                                }
                                else
                                {
                                    crctInput = true;
                                    stocks[i] += add;
                                }
                            }
                        }
                        break;
                    case 2:
                        cout << "\n--- Current Inventory ---\n";
                        for (int i = 0; i < totItem; i++)
                        {
                            cout << items[i] << ": " << stocks[i] << endl;
                        }
                        break;
                    case 3:
                        for (int i = 0; i < totItem; i++)
                        {
                            bool crctInput = false;
                            while (crctInput == false)
                            {
                                cout << "Set new stock for " << items[i] << ": ";
                                cin >> ns;

                                if (cin.fail())
                                {
                                    clearInput();
                                    cout << "Invalid input. Try again." << endl;
                                }
                                else if (ns < 0)
                                {
                                    cout << "Cannot set negative stock.\n";
                                }
                                else
                                {
                                    crctInput = true;
                                    stocks[i] = ns;
                                }
                            }
                        }
                        break;
                    case 4:
                        for (int i = 0; i < totItem; i++)
                        {
                            stocks[i] = 0;
                        }
                        cout << "All stock cleared!\n";
                        break;
                    case 5:
                        cout << "Change Password to (4 DIGIT Numbers only): ";
                        cin >> np;
                        if (cin.fail() || np < 1000 || np > 9999)
                        {
                            clearInput();
                            cout << "Invalid Input.\n";
                            sysClear();
                            break;
                        }
                        else
                        {
                            crctPass = np;
                            cout << "Password change success.\n";
                            clearInput();
                            sysClear();
                            continue;
                        }
                        break;
                    case 6:
                        empLoop = 0;
                        break;
                    default:
                        cout << "Invalid choice.\n";
                        break;
                    } // end of switch
                    continue;
                } // end of while
            } // end of else
        } // end of if user == 1
        else if (user == 2)
        {
            system("clear");
            cin.ignore(); // clear newline before getline
            cout << "Enter Customer Name: ";
            getline(cin, customerName);

            subtotal = 0;
            for (int i = 0; i < totItem; i++)
            {
                oq[i] = 0;
            }

            ordering = 1;

            while (ordering == 1)
            {
                system("clear");
                cout << "\n--- MENU ---\n";

                for (int i = 0; i < totItem; i++)
                {
                    cout << i + 1 << ") " << items[i] << " = PHP " << price[i] << " [" << stocks[i] << " left]\n";
                }
                cout << "13) Proceed to Payment\nChoice: ";
                cin >> mChoice;
                if (cin.fail())
                {
                    clearInput();
                    cout << "Invalid input. Try again." << endl;
                    continue;
                }

                if (mChoice >= 1 && mChoice <= 12)
                {
                    cout << "How many? ";
                    cin >> qty;
                    if (cin.fail())
                    {
                        clearInput();
                        cout << "Invalid input. Try again." << endl;
                        continue;
                    }
                    if (qty <= 0)
                    {
                        cout << "Enter a positive quantity.\n";
                        continue;
                    }
                    if (qty <= stocks[mChoice - 1])
                    {
                        stocks[mChoice - 1] -= qty;
                        oq[mChoice - 1] += qty;
                        cout << "Added.\n";
                    }
                    else
                    {
                        cout << "Not enough stock.\n";
                    }
                } // end of if

                else if (mChoice == 13)
                {
                    ordering = 0;
                }
                else
                {
                    cout << "Invalid menu choice.\n";
                }
            } // end of while

            // computation for price
            for (int i = 0; i < totItem; i++)
            {
                subtotal = subtotal + oq[i] * price[i];
            }
            if (subtotal > 0)
            {
                cout << "Are you Senior/PWD? (Y/N): ";
                cin >> discount;
                if (cin.fail())
                {
                    clearInput();
                    discount = 'N';
                }

                if (discount == 'Y' || discount == 'y')
                {
                    discountAmt = subtotal * 0.20;
                    taxAmt = 0;
                    finalTotal = subtotal - discountAmt;
                }
                else
                {
                    discountAmt = 0;
                    taxAmt = subtotal * 0.12;
                    finalTotal = subtotal + taxAmt;
                }

                receipt(customerName, items, discount, oq, price, totItem, subtotal, discountAmt, taxAmt, finalTotal);

                cout << "Enter payment amount (PHP): ";
                cin >> paid;
                if (cin.fail())
                {
                    clearInput();
                    cout << "Invalid input. Try again." << endl;
                    continue;
                }

                while (paid < finalTotal)
                {
                    cout << "Insufficient payment. Enter again: ";
                    cin >> paid;
                    if (cin.fail())
                    {
                        clearInput();
                        cout << "Invalid input. Try again." << endl;
                    }
                }

                float change = paid - finalTotal;
                cout << "Change: PHP " << change << "\n";
            }
            else
            {
                cout << "No items ordered.\n";
            }
            message();
        } // end of else if

        else
        {
            cout << "Invalid choice.\n";
        }
        cout << "\nDo you want to return to main menu? (1-Yes / 0-No): ";
        cin >> mainLoop;
        if (cin.fail())
        {
            clearInput();
            continue;
        }
    } // end of do-while
    while (mainLoop == 1);
    system("clear");
    cout << "Thank you for using C++offee!\n";
} // end of int main