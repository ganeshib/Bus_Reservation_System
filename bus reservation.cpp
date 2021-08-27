#include<bits/stdc++.h>
using namespace std;
int p=0;
class bus_details
{
    char bus_no[5];
    char driver[10];
    char arrival[5];
    char departure[5];
    char src[20];
    char dest[20];
    char seat[8][4][10];

public:

    void install();
    void reservation();
    void empty();
    void Show();
    void reserved_seats(int i);
    void avaliable_buses();

}
bus[25];

void vline(char ch)
{
    for(int i=80;i>0;i--)
    {
        cout<<ch;
    }
    cout<<"\n";
}

void bus_details:: install()
{
    cout<<"Enter the bus number: \n";
    cin>>bus[p].bus_no;
    cout<<"Enter the Driver name: \n";
    cin>>bus[p].driver;
    cout<<"Arrival Time: ";
    cin>>bus[p].arrival;
    cout<<"\t\tDeparture Time: \n";
    cin>>bus[p].departure;
    cout<<"Source: ";
    cin>>bus[p].src;
    cout<<"\t\tdestination: \n\n";
    cin>>bus[p].dest;
    bus[p].empty();
    p++;
}

void bus_details::reservation()
{
    int seat;
    char bus_num[5];
    int i;
      top:
    cout<<"Enter the Bus Number: ";
    cin>>bus_num;
    int n;

    for(i=0;i<=p;i++)
    {
        if(!strcmp(bus[n].bus_no,bus_num))
        {
            break;
        }
    }

    while(i<=p)
    {
        cout<<"Enter the Seat Number: ";
        cin>>seat;

        if(seat>32)
        {
            cout<<"There are only 32 seats available ";
        }

        else
        {
            if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0)
            {
                cout<<"Enter the passengers name: ";
                cin>>bus[p].seat[seat/4][(seat%4)-1];
                break;
            }
            else
            {
                cout<<"The seat number is already reserved. ";
            }
        }
    }

        if(n>p)
        {
            cout<<"Enter the correct Bus number \n";
            goto top;
        }
    }



void bus_details::empty()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<4;j++)
        {
            strcpy(bus[p].seat[i][j],"Empty");
        }
    }
}

void bus_details::Show()
{
    int i;
    char bus_num[5];
    cout<<"Enter the Bus Number: ";
    cin>>bus_num;

    for(i=0;i<=p;i++)
    {
        if(!strcmp(bus[i].bus_no,bus_num))
        {
            break;
        }
    }

    while(i<=p)
    {
        vline('*');

        cout<<"\nBus Number: \t"<<bus[i].bus_no<<"\nDriver Name: \t"<<bus[i].driver<<"\t\tArrival Time: \t"
        <<bus[i].arrival<<"\nDeparture Time: "<<bus[i].departure<<"\nSource: \t\t"<<bus[i].src<<"\nDestination: \t\t"<<bus[i].dest<<"\n";

        int a=1;

        for(int j=0;i<8;i++)
        {
            for(int k=0;j<4;j++)
            {
                a++;
                if(strcmp(bus[i].seat[j][k],"Empty"))
                {
                    cout<<"\nThe seat number"<<bus[i].seat<<"is reserved for"<<bus[i].seat[j][k];
                }
            }
        }
        break;
        }
        if(i>p)
        {
            cout<<"Enter the correct Bus Number: ";
        }
    }

void bus_details::reserved_seats(int l)
{
    int s=0,h=0;
    for(int i=0;i<8;i++)
    {
        cout<<"\n";
        for(int j=0;j<4;j++)
        {
            s++;
            if(!strcmp(bus[i].seat[i][j],"Empty"))
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[i].seat[i][j];
                h++;
            }else{
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[i].seat[i][j];
            }
        }
    }

    cout<<"\n\n There are "<<h<<" seats empty in Bus number : "<<bus[l].bus_no;
}

void bus_details::avaliable_buses()
{
    vline('*');
    for(int n=0;n<p;n++)
    {
        cout<<"Bus Number: \t"<<bus[n].bus_no<<"\n Driver:\t"<<bus[n].driver<<"\t\tArrival Time: \t"
        <<bus[n].arrival<<"\tDeparture Time: "<<bus[n].departure<<"\nSource:\t\t"<<bus[n].src<<"\t\tDestination:\t\t\t"<<bus[n].departure<<"\n";
        vline('*');
        vline('_');
    }

}

int main()
{
    int choice;
    vline('_');
    cout<<"\t\t\t Travel Agency\t\t\t"<<endl<<endl;
    vline('-');
    while(1)
  {
    cout<<"1.Install\n"<<"2.Reservation\n"<<"3.Show\n"<<"4.Buses Available\n"<<"5.Exit\n";
    vline('*');
    cout<<"Enter The Choice: \n";
    cin>>choice;
    switch(choice)
    {
        case 1:bus[p].install();
                break;
        case 2:bus[p].reservation();
                break;
        case 3:bus[0].Show();
                break;
        case 4:bus[0].avaliable_buses();
                break;
        case 5:{
            cout<<"Successfully logged out";
            exit(0);
        }
    };
  }
}
