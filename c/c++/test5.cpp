#include<iostream>

using namespace std;

int checkNguyenTo(int x)
{
    for(int i = 2; i < x; i++)
    {
        if(x % i == 0)
        {
            return 0;
        } 
    
    }
    return 1;
} 

void sort(int a[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[100], temp;
    do
    {
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            a[i]=temp;
        }
    } while (temp < 1);

    int sosonguyento=0;
    for(int i = 0; i < n; i++)
    {
        if(checkNguyenTo(a[i])==1)
        {
            sosonguyento++;
        }

    }

    cout<<"co "<<sosonguyento<<" so nguyen to"<<endl;
    
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    sort(a, n);
    for(int i = 0; i < n; i++)
        {
            cout <<a[i]<<" ";
        }
    return 0;
}