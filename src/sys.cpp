#include <iostream>
using namespace std;

// For receipt
void printReceipt(string custName, int q1, int q2, int q3, int q4, int q5, int q6,
                  int q7, int q8, int q9, int q10, int q11, int q12,
                  int p1, int p2, int p3, int p4, int p5, int p6,
                  int p7, int p8, int p9, int p10, int p11, int p12,
                  double subtotal, double discountAmt, double taxAmt, double finalTotal)
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
    cout << "Discount: " << discountAmt << "\n";
    cout << "VAT (12%): " << taxAmt << "\n";
    cout << "FINAL TOTAL: " << finalTotal << "\n";
    cout << "Thank you! Visit C++offee again! :)\n";
} // end of void function

int main()
{
    // Stock
    int stock_javachip = 10, stock_capuccino = 10, stock_latte = 10, stock_strawberry = 10;
    int stock_darkroast = 10, stock_espresso = 10;
    int stock_brownies = 10, stock_blueberry = 10, stock_peach = 10, stock_apple = 10;
    int stock_cookie = 10, stock_ramen = 10;

    // Price
    int price_javachip = 100, price_capuccino = 120, price_latte = 110, price_strawberry = 115;
    int price_darkroast = 105, price_espresso = 90;
    int price_brownies = 70, price_blueberry = 80, price_peach = 75, price_apple = 75;
    int price_cookie = 50, price_ramen = 95;

    int mainLoop = 1;
    do
    {
        system("clear");
        cout << "\n===== Welcome to C++offee =====\n";
        cout << "Are you:\n1. Employee\n2. Customer\nChoice: ";
        int userType;
        cin >> userType;

        // For employee loop (CRUD)
        if (userType == 1)
        {
            system("clear");
            int correctPassword = 1234;
            int entered, attempts = 0;
            bool passOK = false;

            // Attempts for password
            while (attempts < 3)
            {
                cout << "Enter Password: ";
                cin >> entered;
                if (entered == correctPassword)
                {
                    passOK = true;
                    system("clear");
                    break;
                }
                else
                {
                    attempts++;
                    cout << "Wrong password. Attempts left: " << (3 - attempts) << "\n";
                }
            }

            if (passOK == false)
            {
                cout << "Too many wrong attempts.\n";
            }
            else
            {
                int empLoop = 1;
                while (empLoop == 1)
                {
                    cout << "\n--- Inventory Management ---\n";
                    cout << "1. Add Stock\n2. View Stock\n3. Update Stock\n4. Delete All Stock\n5. Exit\nChoice: ";
                    int choice;
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                    {
                        int add;
                        cout << "Add to Javascript (Javachip): ";
                        cin >> add;
                        stock_javachip += add;
                        cout << "Add to C#appuccino: ";
                        cin >> add;
                        stock_capuccino += add;
                        cout << "Add to Cout Latte: ";
                        cin >> add;
                        stock_latte += add;
                        cout << "Add to C-trawberry Latte: ";
                        cin >> add;
                        stock_strawberry += add;
                        cout << "Add to Double Dark Roast: ";
                        cin >> add;
                        stock_darkroast += add;
                        cout << "Add to Compilepresso: ";
                        cin >> add;
                        stock_espresso += add;
                        cout << "Add to Brownies: ";
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
                        cout << "Add to Cookie: ";
                        cin >> add;
                        stock_cookie += add;
                        cout << "Add to RAM-en Noodles: ";
                        cin >> add;
                        stock_ramen += add;
                        break;
                    }
                    case 2:
                        cout << "\n--- Current Inventory ---\n";
                        cout << "Javachip: " << stock_javachip << "\n";
                        cout << "Capuccino: " << stock_capuccino << "\n";
                        cout << "Latte: " << stock_latte << "\n";
                        cout << "Strawberry Latte: " << stock_strawberry << "\n";
                        cout << "Dark Roast: " << stock_darkroast << "\n";
                        cout << "Espresso: " << stock_espresso << "\n";
                        cout << "Brownies: " << stock_brownies << "\n";
                        cout << "Blueberry Py: " << stock_blueberry << "\n";
                        cout << "Peach Mango Py: " << stock_peach << "\n";
                        cout << "Apple Py: " << stock_apple << "\n";
                        cout << "Cookie: " << stock_cookie << "\n";
                        cout << "Ramen: " << stock_ramen << "\n";
                        break;
                    case 3:
                    {
                        int ns;
                        cout << "Set new stock for Javachip: ";
                        cin >> ns;
                        stock_javachip = ns;
                        cout << "Set new stock for Capuccino: ";
                        cin >> ns;
                        stock_capuccino = ns;
                        cout << "Set new stock for Latte: ";
                        cin >> ns;
                        stock_latte = ns;
                        cout << "Set new stock for Strawberry Latte: ";
                        cin >> ns;
                        stock_strawberry = ns;
                        cout << "Set new stock for Dark Roast: ";
                        cin >> ns;
                        stock_darkroast = ns;
                        cout << "Set new stock for Espresso: ";
                        cin >> ns;
                        stock_espresso = ns;
                        cout << "Set new stock for Brownies: ";
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
                        cout << "Set new stock for Cookie: ";
                        cin >> ns;
                        stock_cookie = ns;
                        cout << "Set new stock for Ramen: ";
                        cin >> ns;
                        stock_ramen = ns;
                        break;
                    }
                    case 4:
                        stock_javachip = stock_capuccino = stock_latte = stock_strawberry = 0;
                        stock_darkroast = stock_espresso = 0;
                        stock_brownies = stock_blueberry = stock_peach = stock_apple = 0;
                        stock_cookie = stock_ramen = 0;
                        cout << "All stock cleared!\n";
                        break;
                    case 5:
                        empLoop = 0;
                        break;
                    default:
                        cout << "Invalid choice.\n";
                        break;
                    } // end of switch cases
                } // end of while loop
            } // end of if-else statements
        } // end of if statement for employee

        // for customer loop
        else if (userType == 2)
        {
            system("clear");
            cin.ignore(); // clear newline before getline
            string customerName;
            cout << "Enter Customer Name: ";
            getline(cin, customerName);

            int oq1 = 0, oq2 = 0, oq3 = 0, oq4 = 0, oq5 = 0, oq6 = 0, oq7 = 0, oq8 = 0, oq9 = 0, oq10 = 0, oq11 = 0, oq12 = 0;

            int ordering = 1;
            while (ordering == 1)
            {
                system("clear");
                cout << "\n--- MENU ---\n";
                cout << "1) Javascript (Javachip) - " << price_javachip << " [" << stock_javachip << " left]\n";
                cout << "2) Capuccino - " << price_capuccino << " [" << stock_capuccino << " left]\n";
                cout << "3) Latte - " << price_latte << " [" << stock_latte << " left]\n";
                cout << "4) Strawberry Latte - " << price_strawberry << " [" << stock_strawberry << " left]\n";
                cout << "5) Dark Roast - " << price_darkroast << " [" << stock_darkroast << " left]\n";
                cout << "6) Espresso - " << price_espresso << " [" << stock_espresso << " left]\n";
                cout << "7) Brownies - " << price_brownies << " [" << stock_brownies << " left]\n";
                cout << "8) Blueberry Py - " << price_blueberry << " [" << stock_blueberry << " left]\n";
                cout << "9) Peach Mango Py - " << price_peach << " [" << stock_peach << " left]\n";
                cout << "10) Apple Py - " << price_apple << " [" << stock_apple << " left]\n";
                cout << "11) Cookie - " << price_cookie << " [" << stock_cookie << " left]\n";
                cout << "12) Ramen - " << price_ramen << " [" << stock_ramen << " left]\n";
                cout << "13) Proceed to Payment\nChoice: ";
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
                        switch (menuChoice)
                        {
                        case 1:
                            if (qty <= stock_javachip)
                            {
                                stock_javachip -= qty;
                                oq1 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 2:
                            if (qty <= stock_capuccino)
                            {
                                stock_capuccino -= qty;
                                oq2 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 3:
                            if (qty <= stock_latte)
                            {
                                stock_latte -= qty;
                                oq3 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 4:
                            if (qty <= stock_strawberry)
                            {
                                stock_strawberry -= qty;
                                oq4 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 5:
                            if (qty <= stock_darkroast)
                            {
                                stock_darkroast -= qty;
                                oq5 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 6:
                            if (qty <= stock_espresso)
                            {
                                stock_espresso -= qty;
                                oq6 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 7:
                            if (qty <= stock_brownies)
                            {
                                stock_brownies -= qty;
                                oq7 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 8:
                            if (qty <= stock_blueberry)
                            {
                                stock_blueberry -= qty;
                                oq8 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 9:
                            if (qty <= stock_peach)
                            {
                                stock_peach -= qty;
                                oq9 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 10:
                            if (qty <= stock_apple)
                            {
                                stock_apple -= qty;
                                oq10 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 11:
                            if (qty <= stock_cookie)
                            {
                                stock_cookie -= qty;
                                oq11 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        case 12:
                            if (qty <= stock_ramen)
                            {
                                stock_ramen -= qty;
                                oq12 += qty;
                                cout << "Added.\n";
                            }
                            else
                                cout << "Not enough.\n";
                            break;
                        }
                    }
                    system("clear");
                }
                else if (menuChoice == 13)
                {
                    ordering = 0;
                }
                else
                {
                    cout << "Invalid menu choice.\n";
                }
            } // end of while loop for order

            // computation for price
            double subtotal = oq1 * price_javachip + oq2 * price_capuccino + oq3 * price_latte + oq4 * price_strawberry +
                              oq5 * price_darkroast + oq6 * price_espresso + oq7 * price_brownies + oq8 * price_blueberry +
                              oq9 * price_peach + oq10 * price_apple + oq11 * price_cookie + oq12 * price_ramen;

            if (subtotal > 0)
            {
                cout << "Are you Senior/PWD? (Y/N): ";
                char discount;
                cin >> discount;

                // Computation for final price
                double discountAmt = (discount == 'Y' || discount == 'y') ? subtotal * 0.20 : 0.0;
                double afterDiscount = subtotal - discountAmt;
                double taxAmt = afterDiscount * 0.12;
                double finalTotal = afterDiscount + taxAmt;

                system("clear");
                printReceipt(customerName, oq1, oq2, oq3, oq4, oq5, oq6, oq7, oq8, oq9, oq10, oq11, oq12,
                             price_javachip, price_capuccino, price_latte, price_strawberry, price_darkroast, price_espresso,
                             price_brownies, price_blueberry, price_peach, price_apple, price_cookie, price_ramen,
                             subtotal, discountAmt, taxAmt, finalTotal);

                cout << "Enter payment amount (PHP): ";
                double paid;
                cin >> paid;
                while (paid < finalTotal)
                {
                    cout << "Insufficient payment. Enter again: ";
                    cin >> paid;
                }
                cout << "Change: PHP " << paid - finalTotal << "\n";
            }
            else
            {
                cout << "No items ordered.\n";
            }
        } // end of customer loop

        // ================= INVALID =================
        else
        {
            cout << "Invalid choice.\n";
        }

        cout << "\nDo you want to return to main menu? (1-Yes / 0-No): ";
        cin >> mainLoop;
    } while (mainLoop == 1);
    // end of do-while loop
    cout << "Thank you for using C++offee!\n";
    return 0;
}