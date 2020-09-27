#include <bits/stdc++.h>

using namespace std;
class complex_no
{
private:
    double real, img;
public:
    complex_no(): real(0), img(0){}
    void print_no()
    {
        if(real) cout<<real;
        if(img)
        {
            if(img>0)
            {
                if(img==1) cout<<"+i";
                    else cout<<"+"<<img<<"i";
            }
            else cout<<img<<"i";
        }
        if(real==0 && img==0) cout<<0;
    }
    void read()
    {
        real = rand()%100; img = rand()%100;
        //cin>>real>>img;
        print_no();
        cout<<'\n';
    }
    void mod()
    {
        cout<<"The modulus of ";
        print_no();
        cout<<" is: "<<sqrt(real*real+img*img)<<'\n';
    }
    void angle()
    {
        cout<<"The angle of ";
        print_no();
        cout<<" is: "<<atan((double)img/(double)real)*360/asin(1.0)<<" degrees"<<'\n';
    }
    void add(complex_no a, complex_no b)
    {
        real=a.real+b.real;
        img=a.img+b.img;
        cout<<"The sum of the numbers is: ";
        print_no();
        cout<<'\n';
    }
    void dif(complex_no a, complex_no b)
    {
        real=a.real-b.real;
        img=a.img-b.img;
        cout<<"The difference of the numbers is: ";
        print_no();
        cout<<'\n';
    }
    void multiply(complex_no a, complex_no b)
    {
        real=a.real*b.real-a.img*b.img;
        img=a.img*b.real+a.real*b.img;
        cout<<"The numbers multiplied is: ";
        print_no();
        cout<<'\n';
    }
    void divide(complex_no a, complex_no b)
    {
        double upr=a.real*b.real+a.img*b.img;
        double upi=a.img*b.real-a.real*b.img;
        double down=b.real*b.real+b.img*b.img;
        real=upr/down;
        img=upi/down;
        cout<<"The numbers divided is: ";
        print_no();
        cout<<'\n';
    }
};

int main()
{
    srand(time(NULL));
    complex_no a, b, op;
    a.read();
    b.read();
    a.mod();
    b.angle();
    op.add(a,b);
    op.dif(a,b);
    op.multiply(a, b);
    op.divide(a, b);
  	return 0;
}
