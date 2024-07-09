#include<iostream>
using namespace std;

void prefix(string);
void suffix(string);
void substring(string);

int main(){
    string str;
    int choice;

    cout<<"Suyog Rana Magar\n";

    cout <<"\nEnter the string: ";
    cin >> str;
    do{
        cout << "\n1. Prefix 2. Suffix 3. Substring 0. Exit\t\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                prefix(str);
                break;

            case 2:
                suffix(str);
                break;

            case 3:
                substring(str);
                break;

            default:
                choice = 0;
                cout << "Exiting Program.." << endl;
                break;
        }
    }while(choice != 0);
}

void prefix(string s){
    cout << "\nPrefix Combination are:- " << endl;

    string temp;
    for(int i = 0; i < s.length(); i++){
        temp += s[i];
        cout << temp << endl;
    }
    cout << endl << endl;
}

void suffix(string s){
    cout << "\nSuffix Combination are:- " << endl;
    string temp;

    for(int i = s.length() - 1; i >= 0; i--){
        temp = s[i] + temp;
        cout << temp << endl;
    }
    cout << endl << endl;
}

void substring(string s){
    cout << "\nSubstring Combination are:- " << endl;
    for (int i = 0; i < s.length(); i++) {
        string temp;
        for (int j = i; j < s.length(); j++) {
            temp += s[j];
            cout << temp << endl;
        }
        cout<<"\n";
    }
    cout << endl << endl;
}
