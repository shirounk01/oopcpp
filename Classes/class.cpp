#include <bits/stdc++.h>

using namespace std;

ofstream fout("print.txt");

class student /// class begins
{
private: /// private members = only visible within the class
    string firstName, lastName;
    short int age, year, id;
    double height, weight, avgGrade;
    bool graduated;
    static int totalStudents;   /// static variables = stay the same for all objects; they must be declared outside the class if private
public: /// public members = visible anywhere in the program
    /// constructor = initializes a declared object; it can be written in-line: className(dataType varName, ...) : varName(varValue), ... {}; or (*)
    //student(string fn, string ln, short int a, short int y, double h, double w, double ag) :
        //firstName(fn), lastName(ln), age(a), year(y), height(h), weight(w), avgGrade(ag), graduated(year > 4 ? 1 : 0), id(++totalStudents) {};
    student(string fn, string ln, short int a, short int y, double h, double w, double ag)
    /// like a method: className(dataType varName, ...) {varName=varValue; ...;}
    {
        firstName = fn;
        lastName = ln;
        age = a;
        year = y;
        height = h;
        weight = w;
        avgGrade = ag;
        graduated = (year > 4 ? 1 : 0);
        id = ++totalStudents;
    }
    void printStudent() /// basic print method = prints private members
    {
        fout<<"--------------------------------\n";
        fout<<"Full name: "+firstName+" "+lastName+"\n";
        fout<<"Year: "<<year<<"    Graduated: "<<(graduated ? "Yes" : "No")<<"\n";
        fout<<"ID: #"<<id<<"    Age: "<<age<<"\n";
        fout<<"Random ID: "<<firstName[0]<<firstName[firstName.size()-1]<<lastName[0]<<lastName[lastName.size()-1]<<id<<age<<"\n";
        fout<<"Average grade: "<<avgGrade<<"\n";
        fout<<"Height / Weight: "<<height<<" / "<<weight<<"\n";
        fout<<"--------------------------------\n\n";
    }
    void normalize()
    {
        totalStudents -= graduated;
    }
    static void printTotalStudents() /// static method = is callable without the creation of an object
    {
        cout<<"Current number of students registered: "<<totalStudents<<"\n";
    }
    friend class university; /// friend class = the said class can access private members of the class
    friend class dataBase;
};

vector<student> v;

class university
{
private:
    double avgScore, gradPerc;
public:
    university() /// constructor without parameters
    {
        avgScore = 0;
        gradPerc = 0;
        double sum = 0;
        for(auto it : v)
            sum += it.avgGrade;
        avgScore = sum / v.back().id;
    }
    void averageScore()
    {
        cout<<"Average university score: "<<avgScore<<"\n";
    }
    void graduationPercentage()
    {
        gradPerc = (double)(v.back().id-student::totalStudents)*100/v.back().id;
        cout<<"Graduation Percentage: "<<gradPerc<<"\n";
    }
    friend class dataBase;
};

class dataBase : public university /// derived class = inherits the methods/ constructors/ destructor of the parent class
{
private:
    int aboveAvg, belowAvg;
    map<int, int> years;
public:
    dataBase() /// being a derived class, the university() constructor is also called
    {
        aboveAvg = 0;
        belowAvg = 0;
        for(auto it : v)
        {
            if(it.avgGrade < avgScore) belowAvg++;
            else aboveAvg++;
            years[it.year]++;
        }
    }
    void printYears()
    {
        cout<<"\n";
        for(auto it = years.begin(); it != years.end(); ++it)
            cout<<"Year "<<it->first<<" has "<<it->second<<" students\n";
    }
    int getAbove(); /// get method = returns a private member; useful in order to protect data
    int getBelow(); /// outside the class method declaration (**)
};

int dataBase::getAbove() /// (**) is written like so: methodType myClass::methodName(dataType varName, ...) {...;}
{
    return aboveAvg;
}

int dataBase::getBelow()
{
    return belowAvg;
}

int student::totalStudents; /// private static variables global declaration
/// read README.txt in order to see what each member does as well as the entire program
int main()
{
    srand(time(NULL));
    ifstream fin("names.txt");
    string fn, ln;
    while(fin>>fn>>ln)
        v.push_back(student(fn, ln, rand()%7+18, rand()%6+1, (double)(rand()%10000)/100, (double)(rand()%10000)/100, (double)(rand()%1000)/100));
    for(auto it : v)
        it.printStudent(); /// method invocation through an object
    for(auto it = v.begin(); it != v.end(); ++it)
        (*it).normalize();
    student::printTotalStudents(); /// method invocation without an object (static)

    university X;
    X.averageScore();
    X.graduationPercentage();

    dataBase db;
    db.printYears();
    cout<<"Below average: "<<db.getBelow()<<" | | | Above average: "<<db.getAbove()<<"\n";
    return 0;
}
