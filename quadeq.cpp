#include <bits/stdc++.h>

using namespace std;

namespace newSpace /// namespace = creates scopes that cut off the usage of global variables: namespace namespaceName{}
{
    class quadraticEq /// class within namespace
    {
    private:
        double x, y, z; /// parameters of each equation
        short int no; /// index of each equation
        bool complexEq; /// holds if the equation has complex solutions or not
        static int cnt; /// counts how many times objects have been created using the class
    public:
        quadraticEq() : x(0), y(0), z(0), no(++cnt) { cout<<"Null quadratic equation created (no. "<<no<<")\n"; }; /// constructor with no parameters
        quadraticEq(double x, double y, double z) /// constructor with parameters
        {
            this->x = x; /// this pointer = used in this case due to the identical names of the parameter and member: this->member = parameter
            this->y = y;
            this->z = z;
            no = ++cnt;
            cout<<"Quadratic equation created (no. "<<no<<")\n";
        }
        ~quadraticEq() /// destructor
        {
            cout<<"Quadratic equation deleted (no. "<<no<<")\n";
            cnt--;
        }
        void solutions() /// solve for f(a) = xa^2 + ya + z
        {
            if(x != 0)
            {
                cout<<"No. "<<no<<" has ";
                double sol1 = (-y+sqrt(y*y-4*x*z))/(2*x), sol2 = (-y-sqrt(y*y-4*x*z))/(2*x);
                if(!isnan(sol1) || !isnan(sol2))
                {
                    cout<<"the solution(s): ";
                    if(sol1 != sol2) cout<<sol1<<" "<<sol2<<'\n';
                        else cout<<sol1<<'\n';
                }
                else
                {
                    cout<<"complex solutions\n";
                    complexEq = 1;
                }
            }
                else cout<<"No. "<<no<<" is not a quadratic equation\n";
        }
        static void countCalls() /// prints cnt
        {
            cout<<"Number of times the class has been called: "<<cnt<<"\n";
        }
        void sign(); /// method declared outside the class
    };

    void quadraticEq::sign()
    {
        if(x<0) cout<<"No. "<<no<<" has maximum\n";
            else cout<<"No. "<<no<<" has minimum\n";
    }

    void displayText() /// plain void function in namespace
    {
        cout<<"Compute the solutions and the sign of a quadratic equation\n\n";
    }

    int randomNumber = 483516;
}

int newSpace::quadraticEq::cnt; /// namespace static variable global declaration: namespaceName::className::staticMemberName

namespace additionalSpace /// new namespace
{
    int x = 10, y = 9, z = 3;
    void printMsg()
    {
        cout<<"Function from additionalSpace\n";
    }
}

using namespace additionalSpace; /// using namespace = everything within the namespace becomes globally available

int main()
{
	cout<<"Number in namespace: "<<newSpace::randomNumber<<"\n\n"; /// namespace variable call: namespaceName::variableName;
    newSpace::displayText(); /// namespace function call: namespaceName::functionName(parameters);
    newSpace::quadraticEq A;
    newSpace::quadraticEq B(1, -2, 7);
    newSpace::quadraticEq* C = new newSpace::quadraticEq(1, 6, 9); /// pointer to object

    cout<<'\n';

    A.solutions();
    A.sign();

    cout<<'\n';

    B.solutions();
    B.sign();

    cout<<'\n';

    C->solutions();
    C->sign();

    cout<<'\n';

    newSpace::quadraticEq::countCalls(); /// namespace static method call: namespaceName::className::staticMethodName();

    cout<<'\n';

    newSpace::quadraticEq* D = new newSpace::quadraticEq(1, 3, 9);
    D->solutions();
    D->sign();

    cout<<'\n';

    newSpace::quadraticEq::countCalls();

    cout<<'\n';

    printMsg(); /// function from namespace additionalSpace
    newSpace::quadraticEq E(x, y, z); /// uses x, y, z from namespace additionalSpace
    E.solutions();
    E.sign();

    cout<<'\n';

    delete D; /// pointer deallocation ( ~quadraticEq() is automatically called )
    delete C;

    return 0;
} /// end of program/ scope, non-pointer objects get deleted ( ~quadraticEq() is automatically called )
