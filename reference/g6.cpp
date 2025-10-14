#include <iostream>
using namespace std;

int main()
{
    cout<<"\t -------------------------------"<<endl;
    cout<<"\t | BUILDING PROGRESS OF A MALL |"<<endl;
    cout<<"\t -------------------------------"<<endl;
    
    //start of FOR loop for floors 1-5 of a Mall
    for(int floor=1; floor<=5; floor++)
    {
        //if-else statements nested in FOR LOOP to display the mall's floor progress
        if(floor<=2)
        {
            cout<<"Floor "<<floor<<": is COMPLETE"<<endl;
        }
        else if(floor<=4)
        {
            cout<<"Floor "<<floor<<": is UNDER CONSTRUCTION"<<endl;
        } else {
            cout<<"Floor "<<floor<<": is NOT YET STARTED"<<endl;
        }
    }

    return 0;
}