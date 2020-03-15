#include <iostream>
#include <string.h>
using namespace std;
class matrice{
private:
        int l,c;
        double **val;

public:
    friend istream& operator>>(istream&,matrice&);
    friend ostream& operator<<(ostream&,const matrice&);
    matrice (int, int);    //constructor initializare
    matrice();
    matrice(matrice&ob);
    matrice& operator=(const matrice&);
    matrice operator*(matrice&);
    //friend matrice& operator*(matrice& z1, matrice& z2);
    matrice operator+(matrice&);
    matrice operator-(matrice&);
    matrice& operator==(const matrice&);
    friend void nrlinii(matrice&ob){ cout<<ob.l;};
    friend void nrcoloane(matrice&ob){ cout<<ob.c;};
    friend void nrelemente(matrice&ob){
        int nr=0,i,j;
        for(i=0;i<ob.l;i++)
            for(j=0;j<ob.c;++j)
            {
            nr++;}
        cout<<nr;
    };


};
matrice::matrice(int linie,int coloana)
{
    l=linie;
    c=coloana;
    int i;
    this->val=new  double*[l];
    for(i=0; i<l; ++i)
        this->val[i]=new double[c];


}
matrice& matrice::operator=(const matrice&ob)
{
    if(ob.l!=l||ob.c!=this->c)
    {
        cout<<"Gresit";
        return *this;
    }
    else
        for(int i=0; i<l; ++i)
            for(int j=0; j<c; ++j)
                this->val[i][j]=ob.val[i][j];

                return *this;
}
istream &operator>>(istream&in,matrice&b)
{

    int i,j;
    for(i=0; i<b.l; ++i)
        for(j=0; j<b.c; ++j)
            in>>b.val[i][j];
    return in;
}
ostream &operator<<(ostream&out,const matrice&b)
{

    int i,j;
    for(i=0; i<b.l; ++i)
    {
        for(j=0; j<b.c; ++j)
            out<<b.val[i][j]<<" ";
        out<<'\n';
    }

    return out;
}
matrice matrice::operator+(matrice &ob)
{
    matrice z(this->l,this->c);
    int i,j;
    if(ob.l!=l||ob.c!=this->c)
    {
        cout<<"Gresit";
        return z;
    }
    else
        for(i=0; i<l; ++i)
            for(j=0; j<c; ++j)
            {
                z.val[i][j]=this->val[i][j]+ob.val[i][j];
            }
    return z;

}
matrice matrice::operator-(matrice &ob)
{
    matrice z(this->l,this->c);
    int i,j;
    if(ob.l!=l||ob.c!=this->c)
    {
        cout<<"Gresit";
        return z;
    }
    else
        for(i=0; i<l; ++i)
            for(j=0; j<c; ++j)
            {
                z.val[i][j]=this->val[i][j]-ob.val[i][j];
            }
    return z;

}
matrice matrice::operator*(matrice &ob)
{
    matrice z(this->l,this->c);
    int i,j,k,l;
    double aux1;
    for(i=0; i<l; ++i)
        for(j=0; j<c; ++j)
        {
            for(k=0; k<l; ++k)
            {
             for(l=0;l<c;++l)
                aux1=val[i][k]*ob.val[k][j];
                z.val[i][j]=z.val[i][j]+aux1;
            }
        }
    return z;
}
matrice& matrice::operator==(const matrice&ob)
{
    int nr=0;
    if(ob.l!=l||ob.c!=this->c)
    {
        cout<<"Nu sunt egale";
        return *this;
    }
    else
        for(int i=0; i<l; ++i)
            for(int j=0; j<c; ++j)
                {
                if(this->val[i][j]!=ob.val[i][j])
                    nr++;
                }

                if(nr==0){
                    cout<<"sunt egale";
                    return *this;
                }

                else cout<<"nu sunt egale";
}

/*inline matrice& operator*(matrice &z1, matrice& z2){
    matrice *z=new matrice;
    int i,j,k,y,aux1;
    for(i=0;i<=z1.l;++i)
        for(j=0;j<z1.c;++i)
        {
            for(k=0;k<z2.c;++k)
            {
                for(y=0;y<z2.l;++y)
                     aux1=z1.val[i][j]*z2.val[k][y];
                z->val[i][j]=z->val[i][j]+aux1;
            }
        }
        return *z;

}
*/
int main()
{
int lini,coloane;
cout<<"Numar linii:"<<endl;
cin>>lini;
cout<<"Numar coloane:"<<endl;
cin>>coloane;
 matrice a(lini,coloane);
    cin>>a;
    matrice x(lini,coloane);
    cin>>x;
    matrice b(lini,coloane);
    cin>>b;
    matrice o(lini,coloane);
    o=a*x;
    o=o+b;
    cout<<o;


    /*nrlinii(a);
    cout<<endl;
    nrcoloane(a);
    cout<<endl;
    nrelemente(a);
    */

    return 0;

}
