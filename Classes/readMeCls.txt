class student
    private:
        firstName, lastName = hold the name of the student
        age, year, id = keep the age, the year and the id of a student (the id is the count of all students)
        height, weight, avgGrade = the said aspects of a student
        graduated = not graduated if 0, graduated otherwise
        totalStudent = used for the id
    public:
        student(...) = constructor
        printStudent() = prints the identity book of a student
        normalize() = subtracts from totalStudents if graduated
        printTotalStudents = prints totalStudent

class university (friends with student)
    private:
        avgScore, gradPerc = the specs of an university
    public:
        university() = constructor; initializes the private members and computes the average score of all students, graduated or not_a_directory
        averageScore() = prints the average score of a university
        graduationPercentage() = computes and prints the graduation Percentage

class dataBase (derived from university, friends with student and university)
    private:
        aboveAvg, belowAvg = the specification of the given data base
        years = map that keeps the count of students per year
    public:
        dataBase() = constructor; initializes the private members and counts both the students per year and how many are below and above average, respectively
        printYears() = prints the content of years
        getAbove() = return aboveAvg
        getBelow() = return belowAvg

main()
    "names.txt" = input text file that contains random names for the students
    "print.txt" = output text file that will contain each student's profile
    v = vector that holds student objects
    X = university object
    db = dataBase object
What it does:
    - reads every single name from file and creates a student object with random variables that is pushed back
    - for each object, prints the profile of each student ( it. printStudent() )
    - for each object, normalizes the amount of students that have not graduated yet
    - prints the total count of Students
    - creates a university objects
    - computes and prints the average score and graduation percentage
    - creates a dataBase object
    - counts the students per year and prints them
    - computes and prints the count of above and below average students using get methods
