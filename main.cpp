#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <time.h>
using namespace std;
int ttr[20][10],n=20,m=10,pts=1;
int remove(int i)
{
    int s=0,ok=0;
    if(i<=1) return 0;
    for(int j=1;j<=m;j++)
        if(ttr[i][j]==0) ok=1;
    if(ok==0)
        {
            pts++;
            for(int q=i;q>0;q--)
                for(int k=1;k<=m;k++)
                ttr[q][k]=ttr[q-1][k];
            remove (i);
        }
    return remove(i-1);
}
int out(int piesaurm)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 8);

    system("cls");
    switch(piesaurm)
    {
    case 1:
        cout<<"Piesa Urmatoare: X X"<<endl;
        cout<<"                 X X";
    break;

    case 2:
    cout<<"Piesa Urmatoare: X X X X"<<endl;
    break;

    case 3:
        cout<<"Piesa Urmatoare: X X X"<<endl;
        cout<<"                   X";
    break;

    case 4:
        cout<<"Piesa Urmatoare:   X X"<<endl;
        cout<<"                 X X";
    }
    cout<<endl<<"Puncte: "<<pts-1<<" "<<endl;

    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
            if((i==0 || i==n+1) || (j==0 || j==m+1))
            {
                SetConsoleTextAttribute(hConsole, 3976); //650
                cout<<"  ";
                SetConsoleTextAttribute(hConsole, 8);
            }
            else
                if(ttr[i][j]==0) cout<<". ";
                    else
                    {
                        switch(ttr[i][j])
                        {
                            case 1:
                            SetConsoleTextAttribute(hConsole, 69);
                            cout<<"  ";
                            SetConsoleTextAttribute(hConsole, 8);
                            break;
                            case 2:
                            SetConsoleTextAttribute(hConsole, 102);
                            cout<<"  ";
                            SetConsoleTextAttribute(hConsole, 8);
                            break;
                            case 3:
                            SetConsoleTextAttribute(hConsole, 187);
                            cout<<"  ";
                            SetConsoleTextAttribute(hConsole, 8);
                            break;
                            case 4:
                            SetConsoleTextAttribute(hConsole, 34);
                            cout<<"  ";
                            SetConsoleTextAttribute(hConsole, 8);
                            break;
                        }
                    }
            cout<<endl;
    }

}
void movedownp1(int &i,int k)
{
    do
    if(i+1<n && ttr[i+2][k]==0 && ttr[i+2][k+1]==0)
    {
        ttr[i][k]=0;
        ttr[i][k+1]=0;
        ttr[i+2][k]=2;
        ttr[i+2][k+1]=2;
        i++;
    }
    while(i+1<n && ttr[i+2][k]==0 && ttr[i+2][k+1]==0);
}
void moveleftp1(int i,int &k)
{
    if(k>1 && ttr[i][k-1]==0 && ttr[i+1][k-1]==0)
        {
            ttr[i][k-1]=2;
            ttr[i+1][k-1]=2;
            ttr[i][k+1]=0;
            ttr[i+1][k+1]=0;
            k--;
        }
}
void moverightp1(int i,int &k)
{
    if(k<m-1 && ttr[i][k+2]==0 && ttr[i-1][k+2]==0)
        {
            ttr[i][k]=0;
            ttr[i+1][k]=0;
            ttr[i][k+2]=2;
            ttr[i+1][k+2]=2;
            k++;
        }
}
int turap1(int i,int k,int piesaurm)
{
    int dir=0;
    out(piesaurm);
    cout<<"Miscare: ";
    cin>>dir;
    if(dir==1) moveleftp1(i,k);
    if(dir==2) movedownp1(i,k);
    if(dir==3) moverightp1(i,k);
    if((ttr[i+2][k]!=0 || ttr[i+2][k+1]!=0) || i==n-1) return 0;
    return turap1(i,k,piesaurm);
}
void pozp2(int i,int k,int poz)
{
    if(poz==2 && k<=m-3)
    {
        for(int l=1;l<=3;l++)
            ttr[i+l][k]=0;
        for(int l=1;l<=3;l++)
            ttr[i][k+l]=3;
    }
    if(poz==1)
    {
        for(int l=1;l<=3;l++)
            ttr[i][k+l]=0;
        for(int l=1;l<=3;l++)
            ttr[i+l][k]=3;
    }
}
void moveleftp2(int i,int &k,int poz)
{
    if(poz==1)
    {
        if(k>1 && ttr[i][k-1]==0 && ttr[i+1][k-1]==0 && ttr[i+2][k-1]==0 && ttr[i+3][k-1]==0)
        {
            for(int l=0;l<=3;l++)
            ttr[i+l][k]=0;
            for(int l=0;l<=3;l++)
            ttr[i+l][k-1]=3;
            k--;
        }
    }
    if(poz==2)
    {
        if(k>1 && ttr[i][k-1]==0)
            {
                ttr[i][k-1]=3;
                ttr[i][k+3]=0;
                k--;
            }
    }
}
void moverightp2(int i,int &k,int poz)
{
    if(poz==1)
        {
            if(k<m && ttr[i][k+1]==0 && ttr[i+1][k+1]==0 && ttr[i+2][k+1]==0 && ttr[i+3][k+1]==0)
            {
                for(int l=0;l<=3;l++)
                ttr[i+l][k]=0;
                for(int l=0;l<=3;l++)
                ttr[i+l][k+1]=3;
                k++;
            }
        }
        else
        {
            if(k<m-3 && ttr[i][k+4]==0)
            {
                ttr[i][k]=0;
                ttr[i][k+4]=3;
                k++;
            }
        }
}
void movedownp2(int &i,int k,int poz)
{
    if(poz==1)
    {do
        if(i<n-3 && ttr[i+4][k]==0)
            {
                ttr[i+4][k]=3;
                ttr[i][k]=0;
                i++;
            }
        while(i<n-3 && ttr[i+4][k]==0);
    }
    if(poz==2)
        do
        if(i<n && ttr[i+1][k]==0 && ttr[i+1][k+1]==0 && ttr[i+1][k+2]==0 && ttr[i+1][k+3]==0)
            {for(int l=0;l<=3;l++)
            {
                ttr[i][k+l]=0;
                ttr[i+1][k+l]=3;
            }
            i++;}
        while(i<n && ttr[i+1][k]==0 && ttr[i+1][k+1]==0 && ttr[i+1][k+2]==0 && ttr[i+1][k+3]==0);
}
int turap2(int i,int k,int piesaurm,int poz)
{
    int dir=0;
    out(piesaurm);
    cout<<"Miscare: ";
    cin>>dir;
    if(dir==1) moveleftp2(i,k,poz);
    if(dir==2) movedownp2(i,k,poz);
    if(dir==3) moverightp2(i,k,poz);
    if(dir==4)
        {
            if(poz==1) poz=2;
            else poz=1;
            pozp2(i,k,poz);
            out(piesaurm);
        }

    if(i>=n-3 || ttr[i+4][k]!=0) return 0;
    return turap2(i,k,piesaurm,poz);
}
void pozp3(int &i,int k,int &poz)
{
    switch(poz)
    {
        case 1:
        poz=2;
            ttr[i+1][k-1]=1;
            ttr[i+2][k]=1;
            ttr[i][k-1]=0;
            ttr[i][k+1]=0;
            i++;
        break;

        case 2:
        poz=3;
            ttr[i+1][k]=0;
            ttr[i][k+1]=1;
        break;

        case 3:
        poz=4;
            ttr[i][k-1]=0;
            ttr[i+1][k]=1;
        break;

        case 4:
        poz=1;
            ttr[i-1][k]=0;
            ttr[i][k-1]=1;
        break;

    }
}
void moverightp3(int i,int &k,int poz)
{
    if(poz==1)
        if(k<m-1 && ttr[i][k+2]==0 && ttr[i+1][k+1]==0)
        {
            ttr[i][k+2]=1;
            ttr[i+1][k+1]=1;
            ttr[i][k-1]=0;
            ttr[i+1][k]=0;
            k++;
        }
    if(poz==2)
        if(k<m && ttr[i][k+1]==0 && ttr[i-1][k+1]==0 && ttr[i+1][k+1]==0)
        {
            ttr[i-1][k+1]=1;
            ttr[i][k+1]=1;
            ttr[i+1][k+1]=1;
            ttr[i-1][k]=0;
            ttr[i+1][k]=0;
            ttr[i][k-1]=0;
            k++;
        }
    if(poz==3)
        if(k<m-1 && ttr[i][k+2]==0 && ttr[i-1][k+1]==0)
        {
            ttr[i][k+2]=1;
            ttr[i-1][k+1]=1;
            ttr[i-1][k]=0;
            ttr[i][k-1]=0;
            k++;
        }
    if(poz==4)
        if(k<m-1 && ttr[i][k+2]==0 && ttr[i-1][k+1]==0 && ttr[i+1][k+1]==0)
        {
            ttr[i][k+2]=1;
            ttr[i-1][k+1]=1;
            ttr[i+1][k+1]=1;
            ttr[i-1][k]=0;
            ttr[i][k]=0;
            ttr[i+1][k]=0;
            k++;
        }
}
void moveleftp3(int i,int &k,int poz)
{
    if(poz==1)
        if(k>2 && ttr[i][k-2]==0 && ttr[i+1][k-1]==0)
        {
            ttr[i][k-2]=1;
            ttr[i+1][k-1]=1;
            ttr[i+1][k]=0;
            ttr[i][k+1]=0;
            k--;
        }
    if(poz==2)
        if(k>2 && ttr[i][k-2]==0 && ttr[i+1][k-1]==0 && ttr[i-1][k-1]==0)
        {
            ttr[i-1][k]=0;
            ttr[i][k]=0;
            ttr[i+1][k]=0;
            ttr[i-1][k-1]=1;
            ttr[i+1][k-1]=1;
            ttr[i][k-2]=1;
            k--;
        }
    if(poz==3)
        if(k>2 && ttr[i][k-2]==0 && ttr[i-1][k-1]==0)
        {
            ttr[i][k-2]=1;
            ttr[i-1][k-1]=1;
            ttr[i-1][k]=0;
            ttr[i][k+1]=0;
            k--;
        }
    if(poz==4)
        if(k>1 && ttr[i-1][k-1]==0 && ttr[i][k-1]==0 && ttr[i+1][k-1]==0)
        {
            ttr[i-1][k]=0;
            ttr[i+1][k]=0;
            ttr[i][k-1]=1;
            ttr[i-1][k-1]=1;
            ttr[i+1][k-1]=1;
            ttr[i][k+1]=0;
            k--;
        }
}
void movedownp3(int &i,int k,int poz)
{
    if(poz==1)
        while(i<n-1 && ttr[i+2][k]==0 && ttr[i+1][k-1]==0 && ttr[i+1][k+1]==0)
        {
            ttr[i+2][k]=1;
            ttr[i+1][k-1]=1;
            ttr[i+1][k+1]=1;
            ttr[i][k-1]=0;
            ttr[i][k]=0;
            ttr[i][k+1]=0;
            i++;
        }
    if(poz==2)
        while(i<n-1 && ttr[i+2][k]==0 && ttr[i+1][k-1]==0)
        {
            ttr[i+1][k-1]=1;
            ttr[i+2][k]=1;
            ttr[i][k-1]=0;
            ttr[i-1][k]=0;
            i++;
        }
    if(poz==3)
        while(i<n && ttr[i+1][k-1]==0 && ttr[i+1][k]==0 && ttr[i+1][k+1]==0)
        {
            ttr[i+1][k-1]=1;
            ttr[i+1][k]=1;
            ttr[i+1][k+1]=1;
            ttr[i][k-1]=0;
            ttr[i][k+1]=0;
            ttr[i-1][k]=0;
            i++;
        }
    if(poz==4)
        while(i<n-1 && ttr[i+2][k]==0 && ttr[i+1][k+1]==0)
        {
            ttr[i+2][k]=1;
            ttr[i+1][k+1]=1;
            ttr[i-1][k]=0;
            ttr[i][k+1]=0;
            i++;
        }
}
int turap3(int i,int k,int piesaurm,int poz)
{
    int dir=0;
    out(piesaurm);
    cout<<"Miscare: ";
    cin>>dir;

    if(dir==4) pozp3(i,k,poz);
    if(dir==1) moveleftp3(i,k,poz);
    if(dir==2) movedownp3(i,k,poz);
    if(dir==3) moverightp3(i,k,poz);

    if(i<n-1);
    {
        if(poz==1 && (i>=n-1 || ttr[i+1][k+1]!=0 || ttr[i+1][k-1]!=0 || ttr[i+2][k]!=0)) return 0;
        if(poz==2 && (i>=n-1 || ttr[i+1][k-1]!=0 || ttr[i+2][k]!=0)) return 0;
        if(poz==3 && (i>=n   || ttr[i+1][k+1]!=0 || ttr[i+1][k-1]!=0 || ttr[i+1][k]!=0)) return 0;
        if(poz==4 && (i>=n-1 || ttr[i+1][k+1]!=0 || ttr[i+2][k]!=0)) return 0;
    }
    return turap3(i,k,piesaurm,poz);
}
int pozp4(int &i,int &k,int &poz)
{
    int o;
    if(poz==1)
        {
            poz=2;
            ttr[i][k-1]=2;
            ttr[i+2][k]=2;
            ttr[i][k]=0;
            ttr[i][k+1]=0;
            cout<<ttr[i][k]<<" "<<ttr[i][k-1]<<" ";
            k--;
            return 0;
        }
    if(poz==2)
        {
            poz=3;
            ttr[i][k]=0;
            ttr[i][k+1]=1;
            ttr[i+2][k]=1;
            ttr[i+2][k+1]=0;
            k++;
            return 0;
        }

    if(poz==3)
        {
            poz=1;
            ttr[i+2][k-1]=0;
            ttr[i][k+1]=4;
            return 0;
        }
}
void movedownp4(int &i,int k,int poz)
{
    switch(poz)
    {
    case 1:
        if(i<n-1 && ttr[i+2][k]==0 && ttr[i+2][k-1]==0 && ttr[i+1][k+1]==0)
        {
            ttr[i+2][k]=4;
            ttr[i+2][k-1]=4;
            ttr[i+1][k+1]=4;
            ttr[i+1][k-1]=0;
            ttr[i][k]=0;
            ttr[i][k+1]=0;
            i++;
        }
    }
}
void moveleftp4(int i,int k,int poz)
{
    switch(poz)
    {
    case 1:
        if(k>2 && ttr[i][k-1]==0 && ttr[i+1][k-2]==0)
        {
            ttr[i][k-1]=4;
            ttr[i+1][k-2]=4;
            ttr[i][k+1]=0;
            ttr[i+1][k]=0;
            k--;
        }
    }
}
int turap4(int i,int k,int piesaurm,int poz)
{
    int dir=0;
    out(piesaurm);
    cout<<"Miscare: ";
    cin>>dir;

    if(dir==4) pozp4(i,k,poz);
    if(dir==1) moveleftp4(i,k,poz);
    if(dir==2) movedownp4(i,k,poz);
    //if(dir==3)


        if(i<n-1 || ttr[i+2][k-1]!=0 || ttr[i+2][k]!=0 || ttr[i+1][k+1]!=0) return 0;
        if(i<n-2 || ttr[i+2][k]!=0 || ttr[i+3][k+1]!=0) return 0;
        if(i<n-2 || ttr[i+2][k]!=0 || ttr[i+3][k-1]!=0) return 0;
    return turap4(i,k,piesaurm,poz);
}
int turanoua(int piesa)
{
    remove(n);
    for(int o=1;o<=m;o++)
        if(ttr[1][o]==1)
    {
        cout<<endl<<endl<<"GATA BRE, S-A TERMINAT JOCU!"<<endl;
        return 0;
    }

    int piesaurm;
    srand(time(0));
    piesaurm=(rand () % 3)+1;

    clock_t t,r;

    int i=1,k=5;
    if(piesa==1)
    {
        ttr[i][k]=2;
        ttr[i][k+1]=2;
        ttr[i+1][k]=2;
        ttr[i+1][k+1]=2;
        turap1(i,k,piesaurm);
        return turanoua(piesaurm);
    }
    if(piesa==2)
    {
        ttr[i][k]=3;
        ttr[i+1][k]=3;
        ttr[i+2][k]=3;
        ttr[i+3][k]=3;
        turap2(i,k,piesaurm,1);
        return turanoua(piesaurm);
    }
    if(piesa==3)
    {
        ttr[i][k]=1;
        ttr[i+1][k]=1;
        ttr[i][k+1]=1;
        ttr[i][k-1]=1;
        turap3(i,k,piesaurm,1);
        return turanoua(piesaurm);
    }
    /*if(piesa==4)
    {
        ttr[i][k]=4;
        ttr[i][k+1]=4;
        ttr[i+1][k]=4;
        ttr[i+1][k-1]=4;
        turap4(i,k,piesaurm,1);
        return turanoua(piesaurm);
    }*/
}
int main()
{
    int o;
    srand(time(0));
    o=(rand () % 3)+1;
    turanoua(o);
}
