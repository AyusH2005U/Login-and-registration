#include <iostream>
#include <map>
#include <string>

using namespace std;
map<string, string> credentials;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    if (credentials.find(username) != credentials.end()) {
        cout << "Username already exists.\n";
        return;
    }
    cout << "Enter password: ";
    cin >> password;
    credentials[username] = password;
    cout << "Registration successful.\n";
}

void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (credentials.find(username) != credentials.end() && credentials[username] == password) {
        cout << "Login successful.\n";
    } else {
        cout << "Invalid username or password.\n";
    }
}

void resetPassword() {
    string username, newPassword;
    cout << "Enter username: ";
    cin >> username;
    if (credentials.find(username) == credentials.end()) {
        cout << "Username does not exist.\n";
        return;
    }
    cout << "Enter new password: ";
    cin >> newPassword;
    credentials[username] = newPassword;
    cout << "Password reset successful.\n";
}

int main() {
    int choice;
    do {
        cout << "\n1. Register\n2. Login\n3. Reset Password\n4. Exit\nChoose an option: ";
        cin >> choice;
        switch(choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                resetPassword();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);
    return 0;
}
