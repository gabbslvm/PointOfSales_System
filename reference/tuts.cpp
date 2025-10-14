#include <iostream>
using namespace std;

int main()
{
    string username, password;
    int counter=1;
    while(counter<=3)
    {
        cout<<"username: ";
        getline(cin, username);
        cout<<"password: ";
        getline(cin, password);
    
        if((username=="jireh"  || username =="jabez") && password=="group6")
        {
            int meal;
            cout<<"\t============================="<<endl;
            cout<<"\t  W   E   L   C   O   M   E  "<<endl; 
            cout<<"\t============================="<<endl;
            cout<<" "<<endl;
            cout<<"1 - Breakfast"<<endl;
            cout<<"2 - Bunch"<<endl;
            cout<<"3 - Lunch"<<endl;
            cout<<"4 - Merienda"<<endl;
            cout<<"5 - Dinner"<<endl;
            cout<<" "<<endl;
            cout<<"CHOOSE YOUR MEAL: "<<endl;
            cin>>meal;
    
            switch(meal)
            {
                case 1:
                    cout<<" BREAKFAST "<<endl;
                    cout<<"1 egg sandwich"<<endl;
                    cout<<"2 ham and egg sandwich"<<endl;
                    cout<<"3 peanut butter sanwich"<<endl;
                    break;
            
                case 2:
                    cout<<" BRUNCH "<<endl;
                    cout<<"1 vegetable salad"<<endl;
                    cout<<"2 club house"<<endl;
                    cout<<"3 seafoods"<<endl;
                    break;
            
                case 3:
                    cout<<" LUNCH "<<endl;
                    cout<<"1 TAPSILOG"<<endl;
                    cout<<"2 HAMSILOG"<<endl;
                    cout<<"3 BANGSILOG"<<endl;
                    break;
            
                case 4:
                    cout<<" MERIENDA "<<endl;
                    cout<<"1 pizza"<<endl;
                    cout<<"2 hamburger"<<endl;
                    cout<<"3 chicken wings"<<endl;
                    break;
            
                case 5:
                    cout<<" DINNER "<<endl;
                    cout<<"1 egg salad"<<endl;
                    cout<<"2 overload pizza"<<endl;
                    cout<<"3 pares"<<endl;
                    break;
            }
        }
    counter++;
    }
    if(counter >3)
    {
        cout<<"Too many failed attempts"<<endl;
    }
    return 0;
}