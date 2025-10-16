#include <iostream>
using namespace std;

// q for quantity, p for price
void receipt (string customerName, string items[], 
              char discount, int oq[], float price[], 
              int totItem, float subtotal, float discountAmt, 
              float taxAmt, float finalTotal)
{
    cout << "\n--- Receipt ---\n";
    cout << "Customer: " << customerName << "\n\n";

    for (int i = 0; i < totItem; i++)
    {
        if (oq[i] > 0)
        {
            cout << items[i] << " x " << oq[i] << " = " << oq[i] * price[i] << "\n";
        }
    }

    cout << "\nSubtotal: " << subtotal << "\n";

    if (discount == 'Y' || discount == 'y')
    {
        cout << "Discount: -" << discountAmt << "\n";
    }

    else if (discount == 'N' || discount == 'n')
    {
        cout << "VAT (12%): +" << taxAmt << "\n";
        cout << "FINAL TOTAL: " << finalTotal << "\n";
    }

    cout << "Thank you! Visit C++offee again! :)\n";
} // end of void function

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
            "RAM-en Noodles"
        };

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

    int mainLoop = 1, user, crctPass = 1234, entered, attempts = 0, empLoop = 1, choice, add, ns, np, ordering = 1, mChoice, qty;
    float subtotal = 0, paid;
    
    // for discount
    float discountAmt = subtotal * 0.20, afterDiscount = subtotal - discountAmt;
   
    // for without discount
    float taxAmt = subtotal * 0.12, finalTotal = subtotal + taxAmt;
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
                cin.clear();
                cin.ignore(1000, '\n');
            }

        // employee loop (CRUD)
        if (user == 1)
        {
            system("clear");
            while (attempts < 3)
            {
                cout << "Enter Password: ";
                cin >> entered;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << attempts << endl;
                    }

                if (entered == crctPass)
                {
                    passOK = true;
                    system("clear");
                    break;
                }
                else
                {
                    attempts++;
                    cout << "Wrong password. Attempts left: " << 3 - attempts << "\n";
                } // end of if-else
            } // end of while loop for attempts

            if (passOK == false)
            {
                cout << "Too many wrong attempts.\n";
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
                            cin.clear();
                            cin.ignore(1000, '\n');
                        }

                    switch (choice)
                    {
                    case 1:
                        for (int i = 0; i < totItem; i++)
                        {
                            bool crctInput = false;
                            while(crctInput == false)
                            {
                                cout << "Add to " << items[i] << ": ";
                                cin >> add;

                                if (cin.fail())
                                {
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    cout << "Invalid input. Try again." << endl;
                                }
                                else
                                {
                                    crctInput = true;
                                    stocks[i] += add;
                                };
                            };
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
                            while(crctInput == false)
                            {
                                cout << "Set new stock for " << items[i] << ": ";
                                cin >> ns;

                                    if (cin.fail())
                                    {
                                        cin.clear();
                                        cin.ignore(1000, '\n');
                                        cout << "Invalid input. Try again." << endl;
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
                        cout << "Change Password to (Numbers only): ";
                        cin >> np;
                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                            }
                        crctPass = np;
                        break;
                    case 6:
                        empLoop = 0;
                        break;
                    default:
                        cout << "Invalid choice.\n";
                        break;
                    } // end of switch
                } // end of while
            } // end of else
        } // end of if user == 1
        else if (user == 2)
        {
            system("clear");
            cin.ignore(); // clear newline before getline
            cout << "Enter Customer Name: ";
            getline(cin, customerName);

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
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input. Try again." << endl;
                    }

                if (mChoice >= 1 && mChoice <= 12)
                {
                    cout << "How many? ";
                    cin >> qty;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Invalid input. Try again." << endl;
                        }
                    if (qty <= 0)
                    {
                        cout << "Enter a positive quantity.\n";
                    }
                    else
                    {
                        switch (mChoice)
                        {
                        case 1:
                            if (qty <= stocks[0])
                            {
                                stocks[0] -= qty;
                                oq[0] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 2:
                            if (qty <= stocks[1])
                            {
                                stocks[1] -= qty;
                                oq[1] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 3:
                            if (qty <= stocks[2])
                            {
                                stocks[2] -= qty;
                                oq[2] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 4:
                            if (qty <= stocks[3])
                            {
                                stocks[3] -= qty;
                                oq[3] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 5:
                            if (qty <= stocks[4])
                            {
                                stocks[4] -= qty;
                                oq[4] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 6:
                            if (qty <= stocks[5])
                            {
                                stocks[5] -= qty;
                                oq[5] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 7:
                            if (qty <= stocks[6])
                            {
                                stocks[6] -= qty;
                                oq[6] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 8:
                            if (qty <= stocks[7])
                            {
                                stocks[7] -= qty;
                                oq[7] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 9:
                            if (qty <= stocks[8])
                            {
                                stocks[8] -= qty;
                                oq[8] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 10:
                            if (qty <= stocks[9])
                            {
                                stocks[9] -= qty;
                                oq[9] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 11:
                            if (qty <= stocks[10])
                            {
                                stocks[10] -= qty;
                                oq[10] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        case 12:
                            if (qty <= stocks[11])
                            {
                                stocks[11] -= qty;
                                oq[11] += qty;
                                cout << "Added.\n";
                            }
                            else
                            {
                                cout << "Not enough stock.\n";
                            }
                            break;
                        } // end of switch
                    } // end of if else
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
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input. Try again." << endl;
                    }

                receipt(customerName, items, discount, oq, price, totItem, subtotal, discountAmt, taxAmt, finalTotal);

                cout << "Enter payment amount (PHP): ";
                cin >> paid;
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input. Try again." << endl;
                    }

                while (paid < finalTotal || paid < discountAmt)
                {
                    cout << "Insufficient payment. Enter again: ";
                    cin >> paid;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Invalid input. Try again." << endl;
                        }
                }

                cout << "Change: PHP " << (paid - finalTotal || paid - discountAmt) << "\n";
            }
            else
            {
                cout << "No items ordered.\n";
            }
        } // end of else if
        else
        {
            cout << "Invalid choice.\n";
        }
        cout << "\nDo you want to return to main menu? (1-Yes / 0-No): ";
        cin >> mainLoop;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            // cout << "Invalid input. Try again." << endl;
            // mainLoop = 0;
            continue;
        }
    } // end of do
    while (mainLoop == 1);
    system("clear");
    cout << "Thank you for using C++offee!\n";
} // end of int main