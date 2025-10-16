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

        // validate input for main menu
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Try again.\n";
            continue; // go back to start of loop
        }

        // --- ADMIN MODE ---
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
                    cout << "Invalid input. Try again.\n";
                    continue; // stay in password loop
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
                }
            }

            if (!passOK)
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

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input. Try again.\n";
                        continue;
                    }

                    switch (choice)
                    {
                    case 1:
                        for (int i = 0; i < totItem; i++)
                        {
                            cout << "Add to " << items[i] << ": ";
                            cin >> add;
                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Invalid input. Try again.\n";
                                continue;
                            }
                            stocks[i] += add;
                        }
                        break;

                    case 2:
                        cout << "\n--- Current Inventory ---\n";
                        for (int i = 0; i < totItem; i++)
                            cout << items[i] << ": " << stocks[i] << endl;
                        break;

                    case 3:
                        for (int i = 0; i < totItem; i++)
                        {
                            cout << "Set new stock for " << items[i] << ": ";
                            cin >> ns;
                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Invalid input. Try again.\n";
                                continue;
                            }
                            stocks[i] = ns;
                        }
                        break;

                    case 4:
                        for (int i = 0; i < totItem; i++)
                            stocks[i] = 0;
                        cout << "All stock cleared!\n";
                        break;

                    case 5:
                        cout << "Change Password to (Numbers only): ";
                        cin >> np;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Invalid input. Try again.\n";
                            continue;
                        }
                        crctPass = np;
                        break;

                    case 6:
                        empLoop = 0;
                        break;

                    default:
                        cout << "Invalid choice.\n";
                        break;
                    }
                } // end empLoop
            } // end admin section
        }

        // --- CASHIER MODE ---
        else if (user == 2)
        {
            system("clear");
            cin.ignore(); // clear newline before getline
            cout << "Enter Customer Name: ";
            getline(cin, customerName);
            // (your existing cashier logic here — no need to touch unless we fix it later)
        }

        else
        {
            cout << "Invalid choice.\n";
        }

        // ask to repeat main menu
        cout << "\nDo you want to return to main menu? (1-Yes / 0-No): ";
        cin >> mainLoop;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Returning to main menu.\n";
            mainLoop = 1; // stays in loop safely
        }

    } while (mainLoop == 1);

    cout << "Thank you for using C++offee!\n";
}