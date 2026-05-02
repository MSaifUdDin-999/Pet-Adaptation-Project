#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
using namespace std;
class Pet
{
protected:
    string name;
    int age;

public:
    Pet() : name("Unnamed"), age(0)
    {
        cout << "Pet default constructor called" << endl;
    }
    Pet(string petName, int petAge) : name(petName), age(petAge)
    {
        cout << "Pet parameterized constructor called with name: " << name << ", age: " << age << endl;
    }
    virtual ~Pet()
    {
        cout << "Pet destructor called" << endl;
    }
    virtual void displayInfo() const
    {
        cout << "Pet name: " << name << ", Age: " << age << endl;
    }
    void setName(const string &petName)
    {
        name = petName;
    }
    void setAge(int petAge)
    {
        if (petAge < 0)
        {
            throw invalid_argument("Age cannot be negative");
        }
        age = petAge;
    }
};
class Cat : public Pet
{
private:
    string breed;

public:
    Cat() : Pet(), breed("Unknown")
    {
        cout << "Cat default constructor called" << endl;
    }
    Cat(string catName, int catAge, string catBreed) : Pet(catName, catAge), breed(catBreed)
    {
        cout << "Cat parameterized constructor called with name: " << name << ", age: " << age << ", breed: " << breed << endl;
    }
    ~Cat()
    {
        cout << "Cat destructor called" << endl;
    }
    void displayInfo() const override
    {
        cout << "Cat name: " << name << ", Age: " << age << ", Breed: " << breed << endl;
    }
    void setBreed(const string &catBreed)
    {
        breed = catBreed;
    }
    void setInfo(const string &catName, const string &catBreed)
    {
        name = catName;
        breed = catBreed;
    }
};
class Dog : public Pet
{
private:
    string size;

public:
    Dog() : Pet(), size("Unknown")
    {
        cout << "Dog default constructor called" << endl;
    }
    Dog(string dogName, int dogAge, string dogSize) : Pet(dogName, dogAge), size(dogSize)
    {
        cout << "Dog parameterized constructor called with name: " << name << ", age: " << age
             << ", size: " << size << endl;
    }
    ~Dog()
    {
        cout << "Dog destructor called" << endl;
    }
    void displayInfo() const override
    {
        cout << "Dog name: " << name << ", Age: " << age << ", Size: " << size << endl;
    }
    void setSize(const string &dogSize)
    {
        size = dogSize;
    }
    void setInfo(const string &dogName, const string &dogSize)
    {
        name = dogName;
        size = dogSize;
    }
};
void handlePetOperations(vector<unique_ptr<Pet>> &pets)
{
    try
    {
        string catName, catBreed;
        int catAge;
        cout << "Enter cat name: ";
        getline(cin, catName);
        cout << "Enter cat age: ";
        cin >> catAge;
        cin.ignore();
        cout << "Enter cat breed: ";
        getline(cin, catBreed);
        pets.push_back(make_unique<Cat>(catName, catAge, catBreed));
        string dogName, dogSize;
        int dogAge;
        cout << "Enter dog name: ";
        getline(cin, dogName);
        cout << "Enter dog age: ";
        cin >> dogAge;
        cin.ignore();
        cout << "Enter dog size: ";
        getline(cin, dogSize);
        pets.push_back(make_unique<Dog>(dogName, dogAge, dogSize));
    }
    catch (const invalid_argument &e)
    {
        cout << "Invalid argument: " << e.what() << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Runtime error: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "An unknown error occurred" << endl;
    }
}
int main()
{
    vector<unique_ptr<Pet>> pets;
    handlePetOperations(pets);
    cout << "Displaying all pet information:" << endl;
    for (const auto &pet : pets)
    {
        pet->displayInfo();
    }
    return 0;
}