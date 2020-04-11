#include <iostream>

using namespace std;

const short int n_types = 6;
string types_names[n_types] = {"kg", "g", "mg", "funt", "uncja", "kamien"}; 
float types_from_kg[n_types] = {1, 1000, 1000000, 2.20462, 35.274, 0.15747};

double getDouble(); 
int getInt();
int menu(int n_types, string types_names[], float types_from_kg[]);
void calculate(int operation, float mass, int n_types, string types_names[], float types_from_kg[]);

int main()
{
    while (true) {
        //get menu symbol
        int operation = menu(n_types, types_names, types_from_kg);

        cout << "From " << types_names[operation] << " to others" << endl;

        if (operation == 99) {
            cout << "Exiting program" << endl;
            return 0;
        }
        
        //get data 
        cout << "Enter mass: ";
        float mass = getDouble();
        // calculate and show result
        calculate(operation, mass, n_types, types_names, types_from_kg);

    }
}

//get double from user
double getDouble() {
    double x;
    cin >> x;
    while (cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n'))
    {
        cout << "Invalid Input! Please input a float." << endl;
        cin.clear();
        while (cin.get() != '\n');
        cin >> x;
    }
    return x;
}

//get integer from user
int getInt() {
    int x;
    cin >> x;
    while (cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n'))
    {
        cout << "Invalid Input! Please input a integer." << endl;
        cin.clear();
        while (cin.get() != '\n');
        cin >> x;
    }
    return x;
}

//choose convertation type
int menu(int n_types, string types_names[], float types_from_kg[]) {
    cout << "Choose unit:" << endl;
    for (int i = 0; i < n_types; i++) {
        cout << i << " - " << types_names[i] << endl;
    }
    cout << "99 - exit program" << endl;

    bool got_it = false;
    int x;
    while (!got_it) {
        cout << "Your option: ";
        x = getInt();
        if ((x >= 0 && x < n_types) || x == 99) {
            got_it = true;
        }
        else {
            cout << "No such menu option" << endl;
        }
    }
    return x;
}

//calculate and output masses
void calculate(int operation, float mass, int n_types, string types_names[], float types_from_kg[]) {
    float mass_in_kg = mass / types_from_kg[operation];
    for (int i = 0; i < n_types; i++) {
        if (operation != i) {
            cout << mass << types_names[operation] << " = " << mass_in_kg * types_from_kg[i] << types_names[i] << endl;
        }
    }
}
