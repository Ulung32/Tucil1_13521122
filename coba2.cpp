#include <bits/stdc++.h>

using namespace std;

int char2Int (char X){
    if(X == 'A' or X == 'a'){
        return 1;
    }
    else if(X == '2'){
        return 2;
    }
    else if(X == '3'){
        return 3;
    }
    else if(X == '4'){
        return 4;
    }
    else if(X == '5'){
        return 5;
    }
    else if(X == '6'){
        return 6;
    }
    else if(X == '7'){
        return 7;
    }
    else if(X == '8'){
        return 8;
    }
    else if(X == '9'){
        return 9;
    }
    else if(X == '10'){
        return 10;
    }
    else if(X == 'J' or X == 'j'){
        return 11;
    }
    else if(X == 'Q' or X == 'q'){
        return 12;
    }
    else if(X == 'K' or X == 'k'){
        return 13;
    }
    else{
        return 0;
    }
}

vector<int> split(string str){
    int i = 0;
    vector<int> temp;
    while(i < str.size()){
        if(str[i] != ' ' && str[i] != '\n'){
            temp.push_back(char2Int(str[i]));
        }
        i++;
    }
    return temp;
}
bool isValid(vector<int> input){
    if(input.size() != 4){
        return false;
    }
    else{
        bool valid = true;
        int i =0;
        while(i<input.size() && valid){
            if(input[i] == 0){
                valid = false;
            }
            else{
                i++;
            }
        }
        return valid;
    }
}

void inputStr(vector<string> * STR){
    string temp;
    temp = "";
    getline(cin, temp);
    while(temp != " "){
        (*STR).push_back(temp);
        temp = "";
        getline(cin, temp);
    }
}

int main(){
    int a;
    scanf("%d", &a);
    printf("%d", a);
    // vector<int> vec{1,2,3,5,2,3,8};
    // set<int> s(vec.cbegin(), vec.cend());
    // vec = vector<int>(s.cbegin(), s.cend());
    // for (int i = 0; i< vec.size(); i++){
    //     cout<<vec[i]<<endl;
    // }
}