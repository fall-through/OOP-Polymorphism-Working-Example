#include <iostream>

using namespace std;


//create abstract class, makes class look less complex, makes it easier to read and for other dev to work on it
class AbstractEmployee{
    //Ask for promotion is a mehtod, void is return type
    //virtual -- makes void AskforPromotion obligatory for any class that uses abstract employee
    //have to provide implementation of askforpromotion in 
    virtual void AskForPromotion()= 0;
};

//need to give return type, 
//void means function wont return anything
//need this fucntion above main function so c++ knows about it
void sayHi(string name, int age);
double cube(double num);
int getMax(int num1, int num2);
string getDayOfWeek(int dayNum);
void whilelooops (int index);
bool guessinggame(int secretNum, int guess);

//everything in class is private by default
//Employee now can be used as a type (kinda like int string etc), we can name different objects using same type
//:AbstractEmployee -- signs contract , inherits from abstract employee
class Employee:AbstractEmployee{
    //makes it so we cannot access name, comany, age from any other class
public:
    string Name;
    string Company;
    int Age;
    //anything outside of class will have access to public functions
public:
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    int setAge(int age){
        if(age>=18)
        Age = age;
    }
    int getAge(int age){
        return Age;
    }
    
    string Company; 
    int Age;

    void IntroduceYourself(){
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }
    //constuctor, has to haev same name as class, cannot have same return type
    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        age = Age;

    }
    void AskForPromotion(){
        if(Age > 30)
            cout << Name << " got promoted !!! " << endl;
        else
            cout << Name << " no promotion " << endl;
    }
    //POLYMORPHISM -- when a parent class reference is used to refer to an object of a child class
    //here is our mehtod we will invoke on developer and teacher
    //use virtual so that it will check if implementation is in classes, and if there it is it will excecute that instead, if there is no implementation it will just implement the work method in class 
    //AKA "is checking email, task backlog, performing tasks... "
    virtual void Work(){
        cout << Name << " is checking email, task backlog, performing tasks... " << endl; 
    }
};
//derived class, base class
//developer will now have all properties of employee
class Developer:public Employee{
    public:
        string FavProgrammingLanguage;
        //THREE RULES fro creating constuctor : does not have return type, has same name as class, needs to be public
        Developer(string name, string company, int age, string favProgrammingLanguage)
            //pass three we already did to employee constuctor
            :Employee(name, company, age)
        {
            FavProgrammingLanguage = favProgrammingLanguage;
        }
        void fixBug(){
            cout << getName() << "fixed bug using " << FavProgrammingLanguage << endl;
        }
        void Work(){
            cout << Name << " is writing " << FavProgrammingLanguage << " code" << endl; 
    }

};

class Teacher: public Employee{
    public: 
        string Subject;
        void Preparelesson(){
            cout << Name << " is preparing " << Subject << " lesson" << endl;
    }
    //CREATE CONSTUCTOR
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }
    void Work(){
        cout << Name << " is teaching " << Subject << endl; 
    }
};

int main()
{
    //default constuctor, compiler will automatically give us constructor if we dont create one
    Employee employee1 = Employee("Autumn", "Kitten Inc", 20);
    // employee1.Name = "Autumn";
    // employee1.Company = "Kitten Inc";
    // employee1.Age = 25;
    employee1.IntroduceYourself();

    //creating object of class
    Employee employee2 = Employee("John", "Big Lots", 34);
        employee2.IntroduceYourself();
    // employee2.Name = "John";
    employee1.setName("Anna");
    employee1.setCompany("Amazon");
    cout << employee1.getName() << "Is " << employee1.getCompany() << " years old" << endl;

    //employee1.AskForPromotion();
    //employee2.AskForPromotion();

    Developer d = Developer("Autumn", "Kitten Inc", 20, "C++");
    d.fixBug();

    d.AskForPromotion();

    Teacher t = Teacher("Jack", "HS", 55, "French");
    t.Preparelesson();


    //e is pointer, reference to developer
    Employee* e1 = &d;
    Employee* e2 = &t;

    //arrow access members using pointer
    e1->Work();
    e2->Work();



    // d.Work();
    // t.Work();











    //bool stores true or false variable
    bool isMale = true;
    bool isTall = true;
    
    //basically saying if isMale is true because we set it = to true
    //and operator is &&
    //or operator ||
    // ! negation -- means not
    // isMale || isTall is a condition
    // will keep going until reaches conclusion
    if(isMale || isTall){
        cout << "You are a male";

    } else if (isMale && !isTall){
        cout << "You are  a male and you are not tall";


    } else {
        cout << "You are a female";
    }
    
    
    
    cout << "Top" << endl;
    
    
    //call sayHi
    sayHi("Mike", 21);
    cout << "Bottom";


    //dont have to set = to anything at declaration

    int luckyNums[] = {1, 2, 3, 4, 5};

    //print out specific number -- this would print out 1. bc arrays start at 0

    cout << luckyNums[0];


    //modifies number in array

    luckyNums[0] = 19;


    cout <<  cube(5.0);

    cout << getMax(2, 5, 10);

    cout << getDayOfWeek(0);



    return 0;
}

void sayHi(string name, int age){
    cout << "Hi!!!! " << name << "you are " << age << endl;

}
//first doubke is return type, cube is name, second double is data type
double cube(double num){
    return num * num * num;
    //dont code anything under return
}
//comparisons w if
//use double equals when doing comparisons if(comparisons:)) if (num1 == num2)
int getMax(int num1, int num2, int num3){
    int result;

    if(num1 >= num2 && num1 >= num3) {
        result = num1;
    }
    else if (num2 >= num1 && num2 >= num3){
        result = num2;
    }
    else {
        result = num3;
    }
    return result;
}

void betterCalculator(int num1, int num2, char op)
{
    cout << "Enter first number";
    cin >> num1;
    cout << "Enter operator";
    cin >> op;
    cout << "Enter second number";
    cin >> num2;
    //put char in ''
    if(op == '+'){
        int result = num1 + num2;    
    } else if (op == '-'){

        int restult = num1 - num2;
    } //....... contine this
    else {
        cout << "invalid operator";
    }

}
//SWITCH STATEMENT
//avoids doing a ton of if statements
string getDayOfWeek(int dayNum){
    string dayName;

    switch(dayNum){
        case 0: 
            dayName = "Sunday";
            break;
        case 1:
            dayName = "Monday";
            break;
            //....... cont for every day of week 
        default:
            dayName = "Invalid day Number";

    }



    return dayName;
}

void whilelooops (int index){
    int index = 1;
    //make sure condition can become false
    while(index <= 5){

        cout << index << ", ";
        index++;
        // will print 1, 2, 3, 4, 5 
        // will execute over and over until condition is false
    }

    //do while loop
    // this will execute code before checking condition
    int index = 6;
    do{
        cout << index << endl;
        index++;
    }while(index <= 5);
}



bool guessinggame(int secretNum, int guess){

    int secretNum = 7;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;
    bool outofGuesses = false;

    while(secretNum != guess && !outofGuesses){

        if(guessCount < guessLimit){

        cout << "Enter guess: ";
        cin >> guess;
        guessCount++;

        } else {
            outofGuesses = true;
        }

        if(outofGuesses){
            cout << "You Lose!";
        } else {
            cout << "You Win!";
        }


    }
    cout << "you win";
    return 0;
}
