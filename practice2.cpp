//POINTERS

#include <iostream>

using namespace std;

int main(){
    int n = 0;
    //this will print adress -- a ton of random numbers
    cout << &n << endl;
    int * ptr = &n;
    //will also printt address of n value, means pointer is storing address of n variable
    cout << ptr << endl;
    //dereference pointer
    //this will print out value of n (5)
    cout << *ptr << endl;
    *ptr= 10;
    //will spit out 10
    cout << *ptr << endl;
    
    
    
   //vectors -- store info of same data type, need to import #include <vector>
    //to declare vector<DataType> nameOfVector
    vector<string> myVector;
    
    myVector.push_back("king");
    //can use unsigned for int to make sure its always positive
    for(unsigned int i = 0; i < myVector.size(); i++){
        cout << myVector.at[i] << " ";
    }
    
    cout << "Vector: ";
    
    for()
    
    


    







    return 0;
}
