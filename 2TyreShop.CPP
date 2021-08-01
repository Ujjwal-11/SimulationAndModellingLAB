#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int generate_demand()
{

    srand(time(NULL));
    return rand() % 100;
}
int main()
{
    int P, Q, stock, today, dueDate, unitsDue, startDate, demand, reorderCost;
    float total_cost,temp=0;
    cout<<"Enter P And Q: "<<"\n\n";
    demand = generate_demand();
    for(int i=0;i<5;i++)
    {
        cin>>P>>Q;
        startDate = 1;
        dueDate = 0;
        today = startDate;
        unitsDue = 0;
        reorderCost = 10;
        stock = 115;
        total_cost=0;

        while(today<=180)
        {
            if(today==dueDate)
            {
                stock+= Q;
                unitsDue=0;
            }

            if(demand<=stock)
            {
                stock-= demand;
                total_cost+= stock*0.75;
            }
            else
            {
                total_cost+= (demand - stock)*18;
                stock = 0;
            }
            if(stock + unitsDue <= P)
            {
                unitsDue = Q;
                total_cost+= reorderCost*unitsDue;
                dueDate = today+3;
            }
            today++;
        }
        if(i==0)
        {
            temp=total_cost;
        }
        else if (total_cost<temp)
        {
            temp=total_cost;
        }
        cout<<"Total Cost for P= "<<P<<" and Q= "<<Q<<" is "<<total_cost<<"\n\n";
    }
    cout<<"Lowest Cost= "<<temp<<"\n";
    return 0;
}
