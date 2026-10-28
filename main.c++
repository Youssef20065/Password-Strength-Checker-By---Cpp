#include <iostream>
#include <string>
using namespace std;

void Line(int x) {
    for (int i = 0; i < x; i++) {
        cout << endl;
    }
}

int passworldlength(string X) {
    int nb=0;
    for(int i=0;i<X.length();i++){
        nb++;
    }
    return nb;
}

string isUp(string X){
    for(int i = 0; i <X.length();i++){
        if(X[i]>='A'&& X[i]<='Z'){
        return "YES";
        }
    }
    return "NO";
}

string isDown(string X){
    for(int i = 0; i <X.length();i++){
        if(X[i]>='a'&& X[i]<='z'){
        return "YES";
        }
    }
    return "NO";
}
string hasnumber(string X){
    for(int i = 0; i <X.length();i++){
        if(X[i]>='0' && X[i]<='9'){
        return "YES";
        }
    }
    return "NO";
}
string isspecial(string X) {
    for (int i = 0; i < X.length(); i++) {
        string c = X.substr(i, 1);

        if (isUp(c) == "NO" &&
            isDown(c) == "NO" &&
            hasnumber(c) == "NO") {
            return "YES";
        }
    }

    return "NO";
}
int scorecalcule(string X ){
        int score = 0;
        if(passworldlength(X)>=8){
            score++;
        }
        if (isUp(X)=="YES")
        {
            score++;
        }
        if (isDown(X) == "YES")
        score++;

        if (hasnumber(X) == "YES")
        score++;

        if (isspecial(X) == "YES")
        score++;

        return score;
        
        
}
string Str(int score){
    if(score<=1){
        return "VERY WEAK";
    }
    if(score==2){
        return "Weak";
    }
    if(score==3){
        return "Moderate";
    }
    if(score==4){
        return "Strong";
    }
    return "Very Strong";
}




int main() {

    cout << "===================" << endl;
    cout << "PASSWORD CHECKER" << endl;
    cout << "===================" << endl;

    Line(3);

    string Password;

    cout << "Enter your Password: ";
    cin >> Password;

    Line(2);
    cout << "==========Password Analyses=========="<<endl;

    Line(3);
    
    cout <<"Password length :"<<passworldlength(Password) << " characters"<<endl;
    cout<<"Uppercase letters: " << isUp(Password)<<endl;
    cout<<"Lowercase letters:" << isDown(Password)<<endl;
    cout<<"Numbers:    " << hasnumber(Password)<<endl;
    cout <<"Special characters:  "<< isspecial(Password)<<endl;
    Line(2);
    cout<<"======================"<<endl;
    cout<<"Score :" << scorecalcule(Password) <<"/5"<<endl;
    cout<<"Strength:"<<Str(scorecalcule(Password))<< endl;
    cout<<"======================="<<endl;
    return 0;
}