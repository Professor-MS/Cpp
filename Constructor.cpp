#include <iostream>
using namespace std;
class User
{
public:
    string FirstName;
    string LastName;
    int Age;
    string Email;
    // Default Constructor (Empty)
    //  User(){}
    // Default Constructor with default value
    User()
    {
        cout<<"Default Constructor Called."<<endl;
        FirstName = "No Name";
        LastName = "Not set yet";
        Age = 0;
        Email = "Not set";
    }
    User(string fname, string lname, int age)
    {
        cout<<"Parameterized Constructor Called."<<endl;
        FirstName = fname;
        LastName = lname;
        Age = age;
        Email = FirstName + "." + lname + "@mail.com";
    }
};
void GetUserInfo(User u)
{
    cout << "First Name: " << u.FirstName << endl;
    cout << "Lasst Name: " << u.LastName << endl;
    cout << "Age: " << u.Age << endl;
    cout << "Email: " << u.Email << endl;
    cout << "______________________________________" << endl;
}
int main()
{
    // Calling Of Default Constructor
    User user1;
    GetUserInfo(user1);    
    // Calling of Parameterized Constructor
    User user2("professor", "salman", 20);
    GetUserInfo(user2);
    User user3(user2);//copy Constructor
    GetUserInfo(user3);
      system("pause");

    return 0;
}