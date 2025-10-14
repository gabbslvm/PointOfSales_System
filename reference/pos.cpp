#include <iostream>
using namespace std;

int main()
{
    // EMPLOYEE DATA
    string empNames[5] = {"JIREH","FRANK","JABEZ","MIGUEL","HILLAREY"};
    string empIDs[5]   = {"2514791","2514773","2511435","2510396","2513911"};
    string empPass[5]  = {"pass791","pass773","pass435","pass396","pass911"};

    // Inventory Stocks
    int coffeeStocks[5] = {10,10,10,10,10};
    int pastryStocks[6] = {5,5,5,5,5,5};

    // Coffee & Pastry Menus
    string coffeeMenu[5] = {"Caramel Macchiato","Barista's Drink","Cafe Mocha","Spanish Latte","Iced Americano"};
    string pastryMenu[6] = {"Cinnamon Roll","Blueberry Cheesecake","Ensaymada","Belgian Waffle","Brownies","Banana Bread"};

    // --- LOGIN ---
    string inputName;
    cout<<"Enter Name: ";
    getline(cin, inputName);

    // To accept employee name whether all caps/small/mixed letters
    int i = 0;
    while(i < inputName.length())
    {
        if(inputName[i]>='a' && inputName[i]<='z')
        {
            inputName[i] = inputName[i] - 32; // make uppercase
        }
        i++;
    }

    // find employee
    int foundName = -1;
    int x = 0;
    while(x < 5)
    {
        if(inputName == empNames[x])
        {
            foundName = x;
        }
        x++;
    }

    if(foundName != -1)
    {
        // EMPLOYEE LOGIN
        string enteredID, enteredPass;
        cout<<"Enter Employee ID: ";
        getline(cin, enteredID);
        cout<<"Enter Password: ";
        getline(cin, enteredPass);

        if(enteredID == empIDs[foundName] && enteredPass == empPass[foundName])
        {
            cout<<"Welcome, "<<empNames[foundName]<<" (Employee)\n";
            int choice;
            cout<<"Choose:\n2. Inventory\n3. Monitoring\n";
            cin>>choice;

            if(choice==2)
            {
                cout<<"Inventory Selected\n";
                cout<<"\tCoffee Stocks\n";
                int c=0;
                while(c<5)
                {
                    cout<<coffeeMenu[c]<<": "<<coffeeStocks[c]<<endl;
                    c++;
                }
                    cout<<"\tPastry Stocks\n";
                    int p=0;
                    while(p<6)
                {
                    cout<<pastryMenu[p]<<": "<<pastryStocks[p]<<endl;
                    p++;
                }
            }
            else if(choice==3)
            {
            cout<<"Monitoring Selected\n";
            }
            else
            {
                cout<<"Invalid Choice!\n";
            }
        }
        else
        {
            cout<<"Invalid ID or Password!\n";
        }
    }
    else
    {
        // CUSTOMER PART
        cout<<"Hello, Customer "<<inputName<<"!\n";
        cout<<"\t============================="<<endl;
        cout<<"\t  W   E   L   C   O   M   E  "<<endl; 
        cout<<"\t============================="<<endl;
        cout<<"\t----Coffee & Pastry Menu----\n";

        cout<<"\tCoffee & Drinks\n";
        int c=0;
        while(c<5)
        {
            cout<<(c+1)<<". "<<coffeeMenu[c]<<endl;
            c++;
        }

        cout<<"\tPastry\n";
        int p=0;
        while(p<6)
        {
            cout<<(p+1)<<". "<<pastryMenu[p]<<endl;
            p++;
        }
    }
    return 0;
}