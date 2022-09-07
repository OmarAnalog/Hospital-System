#include <bits/stdc++.h>

using namespace std;
string data[21][6];
bool urgent[21][6];
int NumberOfPatients[21];
void Adding_new_patient()
{
cout<<"Enter specialization, name, status: ";
int specialization;
string name;
bool status;
cin>>specialization>>name>>status;

bool emptyplace=0;
if(status)
{
for(int i=5;i>=2;i--)
{
    if (data[specialization][i]=="empty")
        emptyplace=1;
    if (data[specialization][i-1]!="empty" and emptyplace)
    {
        data[specialization][i]=data[specialization][i-1];
        urgent[specialization][i]=urgent[specialization][i-1];
    }
}
if (NumberOfPatients[specialization]!=5)
{
    NumberOfPatients[specialization]++;
   data[specialization][1]=name;
   urgent[specialization][1]=1;
}

else
{
    cout<<"Sorry we can't add more patients for this specialization"<<endl;
}

}
else
{
 for(int i=1;i<=5;i++)
 {
     if (data[specialization][i]=="empty")
     {
         emptyplace=1;
         data[specialization][i]=name;
         urgent[specialization][i]=0;
         NumberOfPatients[specialization]++;
         return;
     }
 }
 if (NumberOfPatients[specialization]==5)
 {
    cout<<"Sorry we can't add more patients for this specialization"<<endl;
 }

}


}

void  Print_all_patient()
{
bool foundany=0;
for(int i=1;i<=20;i++)
{
    if (NumberOfPatients[i])
    {
        cout<<"There are "<<NumberOfPatients[i]<<" in specialization "<<i<<endl;
        foundany=1;
    }
    else
        continue;
    for(int places=1;places<=NumberOfPatients[i];places++)
    {
        cout<<data[i][places]<<" ";
        if (urgent[i][places])
        {
            cout<<"urgent"<<endl;
        }
        else
            cout<<"regular"<<endl;
    }
    cout<<endl;
}
if (!foundany)
{
    cout<<"There are no patients in any specialization"<<endl;
}

}

void Get_next_patient() // based on Shifting left idea
{
    cout<<"Enter specialization: ";
    int specialization;
    cin>>specialization;

    if (!NumberOfPatients[specialization])
    {
        cout<<"No patients at the moment. Have rest, Dr"<<endl;
    }
    else
    {
        cout<<data[specialization][1]<<" please go with the Dr"<<endl;
        for(int i=2;i<=5;i++)
        {
            data[specialization][i-1]=data[specialization][i];
            urgent[specialization][i-1]=urgent[specialization][i];
        }
        NumberOfPatients[specialization]--;
    }
}
void hospitalsystem()
{
    cout<<"\t\t\t\t Welcome to my hospital system"<<endl;
     while(1)
    {
        cout<<"Enter your choice:"<<endl;
        cout<<"1) Add new patient"<<endl;
        //------------------------------------------

        cout<<"2) Print all patients"<<endl;

        //------------------------------------------
        cout<<"3) Get next patient"<<endl;
        //------------------------------------------
        cout<<"4) Exit"<<endl;
        int choice;
        cin>>choice;

        if (choice==1)
        {
            Adding_new_patient();
        }
        else if (choice==2)
        {
            Print_all_patient();
        }
        else if (choice==3)
        {
            Get_next_patient();
        }
        else
        {
            break;
        }
        cout<<endl;
        cout<<"***********************************************"<<endl;

    }
}
void memeeset()
{
     for(int i=0;i<21;i++)
    {
        for(int j=0;j<6;j++)
        {
           data[i][j]="empty";
        }
    }

}
int main()
{
    memeeset();
    hospitalsystem();
    return 0;
}
