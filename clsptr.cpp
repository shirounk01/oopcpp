#include <bits/stdc++.h>

using namespace std;

class individual
{
private:
    double height, weight;
    string name, eyeColor;
    int age;
public:
    individual() : height(0), weight(0), name("Unnamed"), eyeColor("Unknown"), age(0) { cout<<"Base individual born\n"; };
    individual(double h, double w, string n, string ec, int a)
    {
        height = h;
        weight = w;
        name = n;
        eyeColor = ec;
        age = a;
        cout<<"Custom individual born - "+name+"\n";
    }
    ~individual()
    {
        cout<<name+" got killed\n";
    }
    void printIndividual()
    {
        cout<<"Name: "+name+"    Age: "<<age<<"    W/H/eC: "<<weight<<" "<<height<<" "+eyeColor+"\n";
    }
};

int main()
{
    /// basic object construction
    individual in1;
    { /// scope begins
        individual in2(2, 2, "Steve", "Brown", 2);
    } /// scope ends = in2 gets destructed ( ~individual() is automatically called )
    // in2.printIndividual(); /// out of scope
    cout<<'\n';

    individual in3(3, 3, "Eric", "Green", 3);
    in3.printIndividual(); /// basic method call

    cout<<'\n';
    /// pointer to object construction
    individual* in4 = new individual;
    individual* in5 = new individual(5, 5, "Alex", "Blue", 5);
    individual* in6 = new individual;

    cout<<'\n';

    in5->printIndividual(); /// use of arrow operator to invoke a method
    delete in4; /// deletes in4 reference = ~individual() is automatically called

    cout<<'\n';

    { /// scope begins
        individual* in7 = new individual(7, 7, "Emmy", "Black", 7);
        delete in7;
    } /// scope ends and does not automatically call ~individual(), but it goes out of scope

    cout<<'\n';
    /// pointer objects have to be destroyed/delete
    delete in5;
    delete in6;

    cout<<'\n';
    /// array of objects
    individual* in = new individual[3]{{8, 8, "Emma", "Brown", 8}, {9, 9, "Emily", "Green", 9}, {10, 10, "Bruce", "Brown", 10}};
    delete[] in; /// deletes the entire array

    cout<<'\n';

    return 0;
} /// normally declared (non-pointer) objects are destructed when the program ends
