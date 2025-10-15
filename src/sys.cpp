#include <iostream>
using namespace std;

// q for quantity, p for price
void receipt (string custName, 
              int q1, int q2, int q3, int q4, int q5, int q6, int q7, int q8, int q9, int q10, int q11, int q12, 
              int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12,
              float subtotal, float discountAmt, float taxAmt, float finalTotal)
{
    cout << "\n--- Receipt ---\n";
    cout << "Customer: " << custName << "\n\n";

    if (q1 > 0) 
    {
        cout << "Javascript (Javachip) x" << q1 << " = " << q1 * p1 << "\n";
    }
    if (q2 > 0) 
    {    
        cout << "C#appuccino (Capuccino) x" << q2 << " = " << q2 * p2 << "\n";
    }
    if (q3 > 0)
    {    
        cout << "Cout Latte (Caramel) x" << q3 << " = " << q3 * p3 << "\n";
    }
    if (q4 > 0) 
    {    
        cout << "C-trawberry Latte x" << q4 << " = " << q4 * p4 << "\n";
    }
    if (q5 > 0) 
    {   
        cout << "Double Dark Roast x" << q5 << " = " << q5 * p5 << "\n";
    }
    if (q6 > 0) 
    {    
        cout << "Compilepresso (Espresso) x" << q6 << " = " << q6 * p6 << "\n";
    }
    if (q7 > 0) 
    {    
        cout << "JavaBeans Brownies x" << q7 << " = " << q7 * p7 << "\n";
    }
    if (q8 > 0) 
    {    
        cout << "Blueberry Py x" << q8 << " = " << q8 * p8 << "\n";
    }
    if (q9 > 0) 
    {    
        cout << "Peach Mango Py x" << q9 << " = " << q9 * p9 << "\n";
    }
    if (q10 > 0) 
    {    
        cout << "Apple Py x" << q10 << " = " << q10 * p10 << "\n";
    }
    if (q11 > 0)
    {    
        cout << "Byte-sized Cookie x" << q11 << " = " << q11 * p11 << "\n";
    }
    if (q12 > 0)
    {    
        cout << "RAM-en Noodles x" << q12 << " = " << q12 * p12 << "\n";
    }
    
    cout << "\nSubtotal: " << subtotal << "\n";
    cout << "Discount: -" << discountAmt << "\n";
    cout << "VAT (12%): +" << taxAmt << "\n";
    cout << "FINAL TOTAL: " << finalTotal << "\n";
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
        10 // RAM-en Noodles
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

    int mainLoop=1, user, crctPass=1234, entered, attempts=0, empLoop=1, choice, add, ns, np, ordering=1, mChoice, qty;
    bool passOK = false;
    string customerName;

    do
    {
        system("clear");
        cout << "\n===== Welcome to C++offee =====\n";
        cout << "\n1. Admin\n2. Cashier\nChoice: ";
        cin >> user;

        // employee loop (CRUD)
        if (user == 1) 
        {
            system("clear");
            while (attempts < 3) 
            {
                cout << "Enter Password: ";
                cin >> entered;
                
                if (entered == crctPass) 
                { 
                    passOK = true; 
                    system("clear"); 
                    break; 
                }
                else 
                { 
                    attempts++; cout << "Wrong password. Attempts left: " << 3-attempts << "\n";
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

                    switch (choice) 
                    {
                        case 1:
                            for (int i = 0; i < totItem; i++)
                            {
                                cout << "Add to " << items[i] << ": "; 
                                cin >> add; stocks[i] += add;
                            };
                            break;
                        case 2:
                            for (int i = 0; i < totItem; i++)
                            {
                                cout << "\n--- Current Inventory ---\n" << items[i] << ": " << stocks[i] << endl;
                            };
                            break;
                        case 3:
                            for (int i = 0; i < totItem; i++)
                            {
                                cout << "Set new stock for " << items[i] << ": ";
                                cin >> ns; stocks[i] = ns;
                            };
                            break;
                        case 4:
                            for (int i = 0; i < totItem; i++)
                            {
                                stocks[i] = 0;
                            };
                            cout << "All stock cleared!\n";
                            break;
                        case 5:
                            cout << "Change Password to (Numbers only): ";
                            cin >> np; crctPass = np;
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

            while(ordering==1)
            {
                system("clear");
                cout << "\n--- MENU ---\n";
    
                for (int i = 0; i < totItem; i++)
                {
                    cout << i + 1 << ") " << items[i] << " = PHP " << price[i] << " [" << stocks[i] << " left]\n";
                };
                cout << "13) Proceed to Payment\nChoice: ";
                cin >> mChoice;

                if (mChoice >= 1 && mChoice <= 12) 
                {
                    cout << "How many? ";
                    cin >> qty;
                    if (qty <= 0) 
                    {
                        cout << "Enter a positive quantity.\n";
                    } 
                    else 
                    {
                        switch(mChoice)
                        {
                        case 1:
                            if (qty <= stocks[0])
                            {
                                stocks[0] -= qty;
                                oq[0] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 2:
                            if (qty <= stocks[1])
                            {
                                stocks[1] -= qty;
                                oq[1] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 3:
                            if (qty <= stocks[2])
                            {
                                stocks[2] -= qty;
                                oq[2] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 4:
                            if (qty <= stocks[3])
                            {
                                stocks[3] -= qty;
                                oq[3] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 5:
                            if (qty <= stocks[4])
                            {
                                stocks[4] -= qty;
                                oq[4] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 6:
                            if (qty <= stocks[5])
                            {
                                stocks[5] -= qty;
                                oq[5] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 7:
                            if (qty <= stocks[6])
                            {
                                stocks[6] -= qty;
                                oq[6] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 8:
                            if (qty <= stocks[7])
                            {
                                stocks[7] -= qty;
                                oq[7] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 9:
                            if (qty <= stocks[8])
                            {
                                stocks[8] -= qty;
                                oq[8] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 10:
                            if (qty <= stocks[9])
                            {
                                stocks[9] -= qty;
                                oq[9] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 11:
                            if (qty <= stocks[10])
                            {
                                stocks[10] -= qty;
                                oq[10] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 12:
                            if (qty <= stocks[11])
                            {
                                stocks[11] -= qty;
                                oq[11] += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        }
                    }
 
                }           

            } // end of while
        } // end of else if
    } // end of do
    while(mainLoop == 1);
}