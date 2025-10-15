#include <iostream>
using namespace std;

int main()
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
            "RAM-en Noodles"};

    double price[12] = {
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

    int stocks[12] = 
    {
        10,
        10,
        10,
        10,
        10,
        10,
        10,
        10,
        10,
        10
    };

    int totItem = sizeof(items) / sizeof(items[0]);

    system("clear");
    cout << "\n--- MENU ---\n";

    for (int i = 0; i < totItem; i++)
    {
        cout << i + 1 << ") " << items[i] << " = " << price[i] << " - " << stocks[i] << " left\n";
    };

    string orders_items[12];
    int order_qty[12];
    double order_price[12];

    int ordering = 1;

    while (ordering == 1)
    {
        int counter = 0;
        int order_choice;

        cout << "Choose an order: ";
        cin >> order_choice;
        orders_items[counter] = items[order_choice];

        int qty;
        cout <<"How many? ";
        cin >> qty;
        order_qty[counter] = qty;

        char choice;
        cout << "Would you like to order again?";
        cin >> choice;

        if(choice == 'N' || choice == 'n')
        {
            ordering = 0;
        }
    };

    for(int i = 0; i < totItem; i++)
    {
        cout << orders_items[i] << " = " << order_qty[i] << "\n";
    };
}