#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

struct Tadatok {
int nap;
int ora;
int perc;
string rendszam;
int id;
int km;
int kibe;
};

int main()
{
    Tadatok berles[500];
    string temp;
    int db = 0;
    char seged[100];
    ifstream fajl_be ("autok.txt");
    while (!fajl_be.eof()) {
    getline (fajl_be,temp);
    if (temp != "") {
    sscanf(temp.c_str(), "%d %d:%d %s %d %d %d", &berles[db].nap, &berles[db].ora, &berles[db].perc, seged, &berles[db].id, &berles[db].km,&berles[db].kibe);
    berles[db].rendszam = seged;
    db++;
    }}
    //int proba = 2;
    //cout<<berles[proba].nap<<" "<<berles[proba].ora<<":"<<berles[proba].perc<<" "<<berles[proba].rendszam<<" "<<berles[proba].id<<" "<<berles[proba].km<<" "<<berles[proba].kibe<<endl;
    //cout<<db<<endl;

    cout<<"2. feladat"<<endl;
    int i;
    string utolso_auto;
    int utolso_nap;
    for (i=0;i<db;i++)
    {
        if (berles[i].kibe == 0)
        {
            utolso_auto = berles[i].rendszam;
            utolso_nap = berles[i].nap;
        }
    }
    cout<<utolso_nap<<". nap rendszam: "<<utolso_auto<<endl;
    cout<<"3. feladat"<<endl;
    int valasztott_nap;

    cout<<"Nap: ";
    cin>>valasztott_nap;
    cout<<"Forgalom a(z) "<<valasztott_nap<<". napon:"<<endl;
    for (i=0;i<db;i++)
    {
        if (berles[i].nap==valasztott_nap)
        {
            cout<<berles[i].ora<<":"<<berles[i].perc<<" "<<berles[i].rendszam<<" "<<berles[i].id<<" "<<(berles[i].kibe == 0?"ki":"be")<<endl;;
           /* if (berles[i].kibe==0)
                cout<<"ki"<<endl;
            else
                cout<<"be"<<endl;*/
        }
    }
    cout<<"4. feladat"<<endl;
    string autok[10];
    int r = 0;
    int j = 0;
    for (i=0;i<db;i++)
    {
        int b = 0;

        for (j=0;j<r;j++)
        {
            if (berles[i].rendszam == autok[j])
                b++;
        }
        if (b==0)
            autok[r++]=berles[i].rendszam;
    }

    int ki_be_szaml = 0;
    int szaml = 0;
    for (i=0;i<r;i++)
    {
        ki_be_szaml = 0;

        for (j=0;j<db;j++)
        {
            if ((berles[j].rendszam == autok[i]) && (berles[j].kibe == 0))
            {

                ki_be_szaml++;
            }
            else if ((berles[j].rendszam == autok[i]) && (berles[j].kibe == 1))
            {
                ki_be_szaml--;
            }
        }
        if (ki_be_szaml == 1)
            szaml++;
    //cout<<autok[i]<<" "<<ki_be_szaml<<endl; //Teszt
    }
    cout<<"A honap vegen "<<szaml<<" autot nem hoztak vissza."<<endl;
    cout<<"5. feladat"<<endl;
    int elso;
    int utolso;
    int autok_km[10];
    int seged2 = 0;

   for (i=0;i<10;i++)
    {
        seged2 = 0;
        for (j=0;j<db;j++)
        {
            if ((berles[j].rendszam == autok[i]) && (seged2 == 0))
            {
                elso = berles[j].km;
                seged2++;
            }
            else if ((berles[j].rendszam == autok[i]) && (seged2 != 0))
            {
                utolso = berles[j].km;
            }
        }
        autok_km[i]=utolso-elso;
        cout<<autok[i]<<" "<<autok_km[i]<<" km"<<endl;
    }
    cout<<"6. feladat"<<endl;

    int autok_hossz[10];
    int azon_hossz[10];
    int tav_max = 0;
    int tav_id = 0;


    for (i=0;i<db;i++)
    {
        int auto_id =0;
            for(j=0;j<10;j++)
            {
                if (berles[i].rendszam == autok[j])
                auto_id = j;
            }
        if (berles[i].kibe == 0)
        {
            autok_hossz[auto_id] = berles[i].km;
            azon_hossz[auto_id] = berles[i].id;
        }
        else
        {
            int tavolsag = berles[i].km - autok_hossz[auto_id];
            if (tavolsag > tav_max)
            {
                tav_max = tavolsag;
                tav_id = azon_hossz[auto_id];
            }
        }
    }


    cout<<"A leghoszabb ut: "<<tav_max<<" km, szemely: "<<tav_id<<endl;

    cout<<"7.feladat"<<endl;
    string rendszam;
    cout<<"Rendszam:";
    cin>>rendszam;

    string s = rendszam + "_menetlevel.txt";
    string seged_3;
    ofstream ki(s.c_str());
    for (i=0;i<db;i++)
    {
        if (rendszam == berles[i].rendszam) {

            if (berles[i].kibe == 0)
            {
                ki << berles[i].id << "\t" << berles[i].nap << ".\t"<< berles[i].ora << ":"<<berles[i].perc << "\t" << berles[i].km << " km" << "\t";
            }
            else
            {
                ki << berles[i].nap << "."<<(char)9<< berles[i].ora << ":"<<berles[i].perc << "\t" << berles[i].km << " km"<<endl;
            }
        }
    }
     cout<<"Menetlevel kesz.";

    return 0;
}
