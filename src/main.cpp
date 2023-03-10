#include <bits/stdc++.h>

#include <chrono>
using namespace std::chrono;
using namespace std;

int char2Int (char X){
    if(X == 'A' or X == 'a'){
        return 1;
    }else if(X == '2'){
        return 2;
    }else if(X == '3'){
        return 3;
    }else if(X == '4'){
        return 4;
    }else if(X == '5'){
        return 5;
    }else if(X == '6'){
        return 6;
    }else if(X == '7'){
        return 7;
    }else if(X == '8'){
        return 8;
    }else if(X == '9'){
        return 9;
    }else if(X == 'T'){
        return 10;
    }else if(X == 'J' or X == 'j'){
        return 11;
    }else if(X == 'Q' or X == 'q'){
        return 12;
    }else if(X == 'K' or X == 'k'){
        return 13;
    }else{
        return 0;
    }
}

string int2Char (int X){
    switch (X)
    {
    case 1:
        return "A";
        break;
    case 2:
        return "2";
        break;
    case 3:
        return "3";
        break;
    case 4:
        return "4";
        break;
    case 5:
        return "5";
        break;
    case 6:
        return "6";
        break;
    case 7:
        return "7";
        break;
    case 8:
        return "8";
        break;
    case 9:
        return "9";
        break;
    case 10:
        return "10";
        break;
    case 11:
        return "J";
        break;
    case 12:
        return "Q";
        break;
    case 13:
        return "K";
        break;
    default:
        break;
    }
}

vector<int> split(string str){
    int i = 0;
    vector<int> temp;
    while(i < str.size()){
        if(str[i] != ' '){
            if(str[i] == '1' && str[i+1] == '0'){
                temp.push_back(char2Int('T'));
                i++;
            }
            else{
                temp.push_back(char2Int(str[i]));
            }
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

void inputNumber (vector<int>* Number){
    string input;
    bool valid = false;
    cout << "Masukkan 4 angka! (spasi untuk input angka selanjutnya, enter jika selesai input)"<< endl;
    input = "";
    getline(cin, input);
    // inputStr(&input);
    vector<int> temp;
    temp = split(input);
    while(!isValid(temp)){
        cout<< "Input kamu gak valid gan, ulangi!!!"<< endl;
        cout<< "Input harus 4 angka dan valid (A,2,3,4,5,6,7,8,9,10,J,Q,K)"<<endl;
        input = "";
        getline(cin, input);
        temp = split(input);
    }
    *Number = temp;
}

void randomInput (vector<int>* Number){
    srand(time(NULL));
    cout << "Angka yang didapat dari random : "<< endl;
    for(int i = 0; i<4; i++){
        int a = 1 + (rand() % 13);
        cout << int2Char(a)<< " ";
        (*Number).push_back(a);
    }
    cout << endl;
}

vector<vector<int>> permutationNumber(vector<int> Number){
    vector<vector<int>> permutation;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(j != i){
                for(int k = 0; k<4; k++){
                    if(k != j and k != i){
                        for(int l = 0; l<4; l++){
                            if(l != k and l != j and l != i){
                                vector<int> temp;
                                temp.push_back(Number[i]);
                                temp.push_back(Number[j]);
                                temp.push_back(Number[k]);
                                temp.push_back(Number[l]);
                                permutation.push_back(temp);
                            }
                        }
                    }
                }
            }
        }
    }
    return permutation;
}

vector<vector<char>> permutationOpr (vector<char> Operator){
    vector<vector<char>> permutation;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            for(int k = 0; k<4; k++){
                vector<char> temp;
                temp.push_back(Operator[i]);
                temp.push_back(Operator[j]);
                temp.push_back(Operator[k]);
                permutation.push_back(temp);
            }
        }
    }
    return permutation;
}

float getComputation (float X, float Y, char Operator){
    if(Operator == '*'){
        return X*Y;
    }
    else if(Operator == '+'){
        return X+Y;
    }
    else if(Operator == '-'){
        return X - Y;
    }
    else if(Operator == '/'){
        if(Y == 0){
            return 9999999;
        }
        else{
            return X/Y;
        }
    }
}

void result(vector<string> * hasil, vector<int> AngkaInput){
    vector<vector<int>> permutation;
    vector<char> Operator = {'+', '-', '*', '/'};
    vector<vector<char>> permutationOP;
    permutation = permutationNumber(AngkaInput);
    permutationOP = permutationOpr(Operator);
    for(int i = 0; i<24; i++){
        for(int j = 0; j<64; j++){
            float result1 = getComputation(getComputation(permutation[i][0], permutation[i][1], permutationOP[j][0]), getComputation(permutation[i][2], permutation[i][3], permutationOP[j][2]), permutationOP[j][1]);
            float result2 = getComputation(permutation[i][0], getComputation(permutation[i][1], getComputation(permutation[i][2], permutation[i][3], permutationOP[j][2]), permutationOP[j][1]), permutationOP[j][0]);
            float result3 = getComputation(getComputation(getComputation(permutation[i][0], permutation[i][1], permutationOP[j][0]), permutation[i][2], permutationOP[j][1]), permutation[i][3], permutationOP[j][2]);
            float result4 = getComputation(permutation[i][0], getComputation(getComputation(permutation[i][1], permutation[i][2], permutationOP[j][1]), permutation[i][3], permutationOP[j][2]), permutationOP[j][0]);
            float result5 = getComputation(getComputation(permutation[i][0], getComputation(permutation[i][1], permutation[i][2], permutationOP[j][1]), permutationOP[j][0]), permutation[i][3], permutationOP[j][2]);
            if(result1 == 24){
                string Equation = "(" + int2Char(permutation[i][0]) + permutationOP[j][0] + int2Char(permutation[i][1]) + ")" + permutationOP[j][1] + "(" + int2Char(permutation[i][2]) + permutationOP[j][2] + int2Char(permutation[i][3]) +")";
                (*hasil).push_back(Equation);
            }
            if(result2 == 24){
                string Equation = int2Char(permutation[i][0]) + permutationOP[j][0] + "(" + int2Char(permutation[i][1]) + permutationOP[j][1] + "(" + int2Char(permutation[i][2]) + permutationOP[j][2] + int2Char(permutation[i][3]) + "))";
                (*hasil).push_back(Equation);
            }
            if(result3 == 24){
                string Equation = "((" + int2Char(permutation[i][0]) + permutationOP[j][0] + int2Char(permutation[i][1]) + ")" + permutationOP[j][1] + int2Char(permutation[i][2]) + ")" + permutationOP[j][2] + int2Char(permutation[i][3]);
                (*hasil).push_back(Equation);
            }
            if(result4 == 24){
                string Equation = int2Char(permutation[i][0]) + permutationOP[j][0] + "((" + int2Char(permutation[i][1]) + permutationOP[j][1] + int2Char(permutation[i][2]) + ")" + permutationOP[j][2] + int2Char(permutation[i][3]) + ")";
                (*hasil).push_back(Equation);
            }
            if(result5 == 24){
                string Equation = "(" + int2Char(permutation[i][0]) + permutationOP[j][0] + "(" + int2Char(permutation[i][1]) + permutationOP[j][1] + int2Char(permutation[i][2]) + "))" + permutationOP[j][2] + int2Char(permutation[i][3]);
                (*hasil).push_back(Equation);
            }
        }
    }
}

void displayResult(vector<string> result){
    int length = result.size();
    for(int i = 0; i<length; i++){
        cout << result[i] << " = 24" << endl;
    }
}

vector<string> clearResult(vector<string> result){
    vector<string> clearresult;
    clearresult.push_back(result[0]);
    for(int i = 1; i<result.size(); i++){
        bool same = false;
        for(int j = 0; j < i; j ++){
            if(result[i] == result[j]){
                same = true;
                break;
            }
        }
        if(same == false){
            clearresult.push_back(result[i]);
        }
    }
    return clearresult;
}

void makefile(string fileName, vector<string> clear, vector<int> input){
    string path = "test/" + fileName + ".txt";
    std::ofstream outfile (path);
    outfile << "Input : ";
    for(int i = 0; i<4; i++){
        outfile << int2Char(input[i]) << " ";
    }
    outfile << "\nditemukan solusi sebanyak : " << clear.size()<< endl;
    outfile << endl;
    for(int i = 0; i< clear.size(); i++){
        outfile << clear[i]<< " = 24" << endl;
    }
}

int main(){
    bool run = true;
    while (run){
        string inputUser = "";
        vector<int> Input;
        vector<string> Hasil;
        string simpan;
        cout << "Ingin input angka sendiri? (Y/N) "<< endl;
        getline(cin, inputUser);
        while(inputUser != "Y" && inputUser != "N"){
            cout << "Input Y atau N !!!"<< endl;
            inputUser = "";
            getline(cin,inputUser);
        }
        if(inputUser == "Y"){
            inputNumber(&Input);
        }
        else{
            randomInput(&Input);
        }
        auto start = high_resolution_clock::now();
        result(&Hasil, Input);
        vector<string> clear;
        if(Hasil.size() > 0){
            clear = clearResult(Hasil);
        }
        else{
            clear = Hasil;
        }
        auto stop = high_resolution_clock::now();
        cout << "ditemukan solusi sebanyak : " << clear.size()<< endl;
        displayResult(clear);
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "execution time : " << duration.count() << " microseconds"<< endl;
        cout << "Apakah hasil ingin disimpan? (Y/N) ";
        cin >> simpan;
        if(simpan == "Y"){
            string Name;
            cout<<"Masukkan nama file! ";
            cin >> Name;
            makefile(Name, clear, Input);
            cout << "hasil berhasil disimpan di folder test"<< endl;
        }
        cout << "Ketik 1 jika ingin lanjut, 0 jika ingin udahan ! ";
        string lanjut;
        cin >> lanjut;
        while(lanjut != "1" && lanjut != "0"){
            cout<< "Inputnya 1 atau 0 bang, ulangi!!! "<< endl;
            cin >> lanjut;
        }
        if(lanjut == "0"){
            run = false;
            cout << "bye"<< endl;
        }
    }
}
 