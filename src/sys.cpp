#include <iostream>
#include <vector>
using namespace std;

// For clearing inputs
void clearInput()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

// For clearing display
void sysClear()
{
    cout << "\nPress ENTER to continue...\n";
    cin.ignore(1000, '\n');
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
    cout << "Customer: " << customerName << endl
         << endl;

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
    else
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

struct OrderHistory
{
    string customerName;
    float total;
    string summary;
};

int main()
{
    // menu
    string items[16] =
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
            "RAM-en Noodles",
            "Carbonara",
            "Creamy Pesto",
            "Pizza Boxed",
            "Pizza Per Piece"
        }; // end of array

    // price of menu
    float price[16] =
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
            95,  // RAM-en Noodles
            150, // Carbonara
            140, // Creamy Pesto
            500, // Pizza Boxed
            65   // Pizza Per Piece
        }; // end of array

    // initial stocks for menu
    int stocks[16] =
        {
            10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10
        }; // end of array

    int oq[16] =
        {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        }; // end of array

    int totItem = sizeof(items) / sizeof(items[0]); // 16

    int mainLoop = 1, user, crctPass = 1234, entered, attempts = 0, empLoop = 1, choice, add, ns, np, ordering = 1, catChoice, mChoice, qty, rem, remQty;
    float paid, subtotal = 0, discountAmt = 0, taxAmt = 0, finalTotal = 0;
    char discount;
    bool passOK = false;
    string customerName, summary = " ";
    vector<OrderHistory> orderHistory;

    do
    {
        system("clear");
        cout << "\n===== Welcome to C++offee =====\n";
        cout << "\n1. Admin\n2. Cashier\n\nChoice: ";
        cin >> user;

        if (cin.fail())
        {
            clearInput();
            continue;
        }

        if (user == 1)
        {
            system("clear");

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
                    sysClear();
                    continue;
                }

                if (entered < 1000 || entered > 9999)
                {
                    cout << "Password must be exactly 4 Digits.\n";
                    attempts++;
                    cout << "Attempts left: " << 3 - attempts << endl;
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
                    sysClear();
                }
            }

            if (!passOK)
            {
                cout << "Access denied. Returning to main menu.\n";
                sysClear();
                continue;
            }
            else
            {
                empLoop = 1;
                while (empLoop == 1)
                {
                    cout << "\n--- Inventory Management ---\n";
                    cout << "1. Add Stock\n2. View Stock\n3. Update Stock\n4. Delete All Stock\n5. Change Password\n6. View Order History\n7. Exit\nChoice: ";
                    cin >> choice;

                    if (cin.fail())
                    {
                        clearInput();
                        cout << "Invalid input.\n";
                        sysClear();
                        continue;
                    }
                    system("clear");

                    switch (choice)
                    {
                    case 1:
                        for (int i = 0; i < totItem; i++)
                        {
                            cout << "Add to " << items[i] << ": ";
                            cin >> add;

                            if (cin.fail() || add < 0)
                            {
                                clearInput();
                                cout << "Invalid input. Try again." << endl;
                                sysClear();
                                continue;
                            }
                            stocks[i] += add;
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
                            cout << "Set new stock for " << items[i] << ": ";
                            cin >> ns;

                            if (cin.fail() || ns < 0)
                            {
                                clearInput();
                                cout << "Invalid input. Try again." << endl;
                                sysClear();
                                continue;
                            }
                            stocks[i] = ns;
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
                            sysClear();
                            continue;
                        }
                        break;
                    case 6:
                        if (orderHistory.empty())
                        {
                            cout << "No order history yet.\n";
                        }
                        else
                        {
                            cout << "\n=== ORDER HISTORY ===\n";
                            for (int i = 0; i < (int)orderHistory.size(); i++)
                            {
                                cout << "\nCustomer: " << orderHistory[i].customerName;
                                cout << "\nItems:\n"
                                     << orderHistory[i].summary;
                                cout << "Total Paid: PHP " << orderHistory[i].total;
                                cout << "\n-----------------------------\n";
                            }
                        }
                        break;
                    case 7:
                        empLoop = 0;
                        continue;
                    default:
                        cout << "Invalid input.\n";
                        break;
                    }
                    sysClear();
                }
            }
        }
        else if (user == 2)
        {
            system("clear");
            cin.ignore();
            cout << "Enter Customer Name: ";
            getline(cin, customerName);

            ordering = 1;
            while (ordering == 1)
            {
                system("clear");
                cout << "\n--- Menu Categories ---\n";
                cout << "1) Drinks\n2) Dessert\n3) Food\n4) Remove Item\n5) View Cart\n6) Proceed Payment\n7) Back/Exit\nChoice: ";
                cin >> catChoice;

                if (cin.fail())
                {
                    clearInput();
                    cout << "Invalid input\n";
                    sysClear();
                    continue;
                }

                int start = 0, end = 0;

                switch (catChoice)
                {
                case 1:
                    sysClear();
                    start = 0;
                    end = 5;
                    break; // Drinks
                case 2:
                    sysClear();
                    start = 5;
                    end = 12;
                    break; // Food
                case 3:
                    sysClear();
                    start = 12;
                    end = 14;
                    break; // Desserts
                case 4:
                    break; // Remove Item
                case 5:
                    break; // View Cart
                case 6:
                    break; // Proceed Payment
                case 7:
                    ordering = 0;
                    continue;
                default:
                    cout << "Invalid input\n";
                    sysClear();
                    continue;
                }

                if (catChoice >= 1 && catChoice <= 3)
                {
                    while (1)
                    {
                        system("clear");
                        for (int i = start; i < end; i++)
                        {
                            cout << i + 1 << ") " << items[i] << " = PHP " << price[i] << " [" << stocks[i] << " left] (In Cart: " << oq[i] << ")\n";
                        }
                        cout << end + 1 << ") Back to Categories\nChoice: ";
                        int itemChoice;
                        cin >> itemChoice;

                        if (cin.fail())
                        {
                            clearInput();
                            cout << "Invalid input\n";
                            sysClear();
                            continue;
                        }

                        if (itemChoice == end + 1)
                        {
                            break;
                        }
                        else if (itemChoice >= start + 1 && itemChoice <= end)
                        {
                            cout << "Quantity: ";
                            cin >> qty;

                            if (cin.fail() || qty <= 0)
                            {
                                clearInput();
                                cout << "Invalid quantity\n";
                                sysClear();
                                continue;
                            }

                            if (qty > stocks[itemChoice - 1])
                            {
                                cout << "Not enough stock\n";
                                sysClear();
                                continue;
                            }
                            else
                            {
                                stocks[itemChoice - 1] -= qty;
                                oq[itemChoice - 1] += qty;
                            }
                        }
                        else
                        {
                            cout << "Invalid choice\n";
                            sysClear();
                            continue;
                        }
                    }
                }
                else if (catChoice == 4) // Remove Item
                {
                    system("clear");
                    cout << "\n--- Remove Item ---\n";
                    for (int i = 0; i < totItem; i++)
                    {
                        cout << i + 1 << ") " << items[i] << " In Cart: " << oq[i] << "\n";
                    }
                    cout << totItem + 1 << ") Back\nChoice: ";
                    int remChoice;
                    cin >> remChoice;

                    if (cin.fail())
                    {
                        clearInput();
                        cout << "Invalid input\n";
                        sysClear();
                        continue;
                    }

                    if (remChoice >= 1 && remChoice <= totItem)
                    {
                        cout << "Quantity to remove: ";
                        cin >> remQty;

                        if (cin.fail() || remQty <= 0)
                        {
                            clearInput();
                            cout << "Invalid quantity\n";
                            sysClear();
                            continue;
                        }

                        if (remQty > oq[remChoice - 1])
                        {
                            cout << "You don't have that many in cart\n";
                            sysClear();
                            continue;
                        }
                        else
                        {
                            oq[remChoice - 1] -= remQty;
                            stocks[remChoice - 1] += remQty;
                        }
                    }
                }
                else if (catChoice == 5) // View Cart
                {
                    system("clear");
                    cout << "\n--- Your Cart ---\n";
                    bool cartIsEmpty = true;
                    for (int i = 0; i < totItem; i++)
                    {
                        if (oq[i] > 0)
                        {
                            cout << items[i] << " x " << oq[i] << " = " << oq[i] * price[i] << "\n";
                            cartIsEmpty = false;
                        }
                    }

                    if (cartIsEmpty)
                    {
                        cout << "No items in cart.\n";
                    }

                    sysClear();
                }
                else if (catChoice == 6) // Proceed Payment
                {
                    subtotal = 0;
                    for (int i = 0; i < totItem; i++)
                    {
                        subtotal += oq[i] * price[i];
                    }

                    if (subtotal == 0)
                    {
                        cout << "No items in cart.\n";
                        sysClear();
                        continue;
                    }

                    cout << "Discount? (Y/N): ";
                    cin >> discount;

                    discountAmt = 0;
                    taxAmt = 0;

                    if (discount == 'Y' || discount == 'y')
                    {
                        discountAmt = subtotal * 0.1;
                    }
                    else
                    {
                        taxAmt = subtotal * 0.12;
                    }

                    finalTotal = subtotal - discountAmt + taxAmt;

                    receipt(customerName, items, discount, oq, price, totItem, subtotal, discountAmt, taxAmt, finalTotal);

                    cout << "Total: PHP " << finalTotal << "\n";
                    cout << "Amount Paid: ";
                    cin >> paid;

                    double change = paid - finalTotal;
                    cout << "Change: " << change << "\n";
                    
                    if (cin.fail())
                    {
                        clearInput();
                        cout << "Invalid amount\n";
                        sysClear();
                        continue;
                    }

                    if (paid < finalTotal)
                    {
                        cout << "Insufficient amount\n";
                        sysClear();
                        continue;
                    }

                    
                    message();

                    // Store order history
                    summary = "";
                    for (int i = 0; i < totItem; i++)
                    {
                        if (oq[i] > 0)
                        {
                            summary += items[i] + " x " + to_string(oq[i]) + "\n";
                        }
                    }

                    orderHistory.push_back({customerName, finalTotal, summary});

                    // Clear cart
                    for (int i = 0; i < totItem; i++)
                    {
                        oq[i] = 0;
                    }

                    sysClear();
                }
            }
        }
    } while (mainLoop == 1);

    return 0;
} // end of main
