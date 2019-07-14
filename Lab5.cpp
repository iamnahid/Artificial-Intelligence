#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int to_dec(string num, int base)
{
    int dec = num[0] - (isupper(num[0]) ? 'A' - 10: '0');
    for(int i = 1; num[i]; i++)
    {
        if(num[i] >= 'A' & num[i] <= 'Z')
            num[i] -= 'A' - 10;
        else num[i] -= '0';
        dec *= base;
        dec += num[i];
    }
    return dec;
}


int counts, sum;
double avg;

class Population
{
public:
    string partner;
    string num;
    int x;
    double fitness;
    //bool crossover;
    int crossoverPoint;
};


int main()
{
    ios::sync_with_stdio(false);

    Population *p;
    int temp, temp2;
    bool flag = false;
    string temp3;
    cout << "enter population size(even): ";
    cin >> counts;

    p = new Population[counts];
    sum = 0;

    for(int i = 0; i < counts; i++)
    {

        cout << "enter starting population (5 bits) " << i + 1 << ": ";
        cin >> p[i].num;
        p[i].x = to_dec(p[i].num, 2);
        sum += p[i].x * p[i].x;
        p[i].partner = "";
    }
    avg = (double)sum / counts;

    for(int i = 0; ; i++)
    {
        cout << endl << endl <<  "GENERATION " << i << endl << endl;

        for(int j = 0; j < counts; j++)
        {


            p[j].fitness = (p[j].x * p[j].x) / avg;
            cout << p[j].num << "\t" << p[j].x << "\t" << p[j].x * p[j].x << "\t" << p[j].fitness << endl;
            if(p[j].partner == "")
            {
                //temp = j;
                temp2 = 0;
                while(1)
                {
                    temp = rand() % counts;
                    if(temp != j && p[temp].partner == "")
                        break;
                }
                while(temp2 == 0)
                {
                    temp2 = rand() % 5;
                }
                p[j].partner = p[temp].num;
                p[j].crossoverPoint = temp2;
                p[temp].partner = p[j].num;
                p[temp].crossoverPoint = temp2;
            }
            //p[j].crossover = false;

        }

        cout << endl << "CROSS OVER STAGE" << endl;
        sum = 0;
        for(int j = 0; j < counts; j++)
        {
            cout << p[j].num << "\t" << p[j].partner << "\t" << p[j].crossoverPoint << "\t";
            temp3 = p[j].num.substr(p[j].crossoverPoint);
            p[j].num = "";
            p[j].num = p[j].partner.substr(0, p[j].crossoverPoint);
            p[j].num += temp3;
            p[j].x = to_dec(p[j].num, 2);
            cout << p[j].num << "\t" << p[j].x << endl;
            sum += p[j].x * p[j].x;
            if(p[j].x == 31)
            {
                flag = true;
                break;
            }
            //p[j].crossover = true;
            p[j].partner = "";
        }
        avg = (double)sum / counts;

        if(flag)
        {
            cout << "highest value (x == 31) achieved in generation " << i  << endl;
            break;
        }


    }


    return 0;
}
