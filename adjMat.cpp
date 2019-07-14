#include <iostream>

using namespace std;

int main ()
{
    int nd, ed, i , j ,k, m, n ;
    i =0; j =0; m=0; n=0; k =0;
    int ar[5][5] = {0};


    cout<<"Input:     "<<endl;
    cout<<"-----------"<<endl;
    cout<<"No of Nodes:  ";
    cin>>nd;cout<<endl;
    cout<<"No of Edges:  ";
    cin>>ed;cout<<endl;

    cout<<"Now input your Adjacent Nodes: "<<endl;

    for (i=0; i<ed; i++)
    {
       cin>>m;
       cout<<"  ";
       cin>>n;
       ar[m][n] = 1;

    }

    cout<<endl<<endl<<"Output:  "<<endl;

    for (k=0; k<nd; k++)
        {
            for (j=0; j<nd; j++)
            {
                cout<<ar[k][j];

            }
            cout<<endl;
        }

    cout<<"Neighbours:  "<<endl;

    for (k=0; k<nd; k++)
        {
            for (j=0; j<nd; j++)
            {
                if( ar[k][j] == 1)
                {
                    cout<<k<<"->"<<j;
                }
                cout<<endl;
                else
                {

                }

            }
            cout<<endl;
        }



}
