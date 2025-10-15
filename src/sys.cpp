#include <iostream>
using namespace std;

void printReceipt(string custName, int qty[], int price[], double subtotal, double discountAmt, double taxAmt, double finalTotal)
{
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
    int totItem = sizeof(items) / sizeof(items[0]);
    cout << "\n=============================================\n";
    cout << "              C++OFFEE RECEIPT\n";
    cout << "=============================================\n";
    cout << "Customer Name: " << custName << "\n\n";
    cout << "Item\t\t\tQty\tTotal\n";
    cout << "---------------------------------------------\n";

    for(int i = 0; i <totItem; i++)
    {
        if(qty[i] > 0)
        {
            cout << items[i] << " x" << qty[i] << " = " << qty[i] * price [i] << endl;
        }
    }
    cout << "---------------------------------------------\n";
    cout << "Subtotal:\t\t\t" << subtotal << "\n";
    cout << "Discount:\t\t\t-" << discountAmt << "\n";
    cout << "Tax (12%):\t\t\t" << taxAmt << "\n";
    cout << "---------------------------------------------\n";
    cout << "Final Total:\t\t\t" << finalTotal << "\n";
    cout << "=============================================\n";
}

int main()
{
    string customerName;
    cout << "Enter customer name: ";
    getline(cin, customerName);

    // Prices for each item
    int price[12] = {
        100,  // Javascript (Javachip)
        120,  // C#appuccino (Capuccino)
        110,  // Cout Latte (Caramel)
        115,  // C-trawberry Latte
        105,   // Double Dark Roast
        90,   // Compilepresso (Espresso)
        70,   // JavaBeans Brownies
        80,   // Blueberry Py
        75,   // Peach Mango Py
        75,   // Apple Py
        50,   // Byte-sized Cookie
        95   // RAM-en Noodles
    };
}