#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


void calculator() {
    double a,b;
    char op,cont;
    cout << "-------Calculator-------" << endl;
    cout << "Input Example: 2*2 or 2^3.\n";
    cout << "Operations: '+'  '-'  '*'  '/'  '^'  '%'  'r'(root).\n";
    do {
        cout << "Enter your operation: ";
        cin >> a >> op;
        if (op == 'r') { 
            if (a >= 0)
                cout << "Result: " << sqrt(a) << endl;
            else
                cout << "Error: Cannot take root of negative!\n";
        } 
        else {
            cin >> b;
            switch (op) {
                case '+': 
                    cout << "Result: " << a + b << endl; break;
                case '-': 
                    cout << "Result: " << a - b << endl; break;
                case '*': 
                    cout << "Result: " << a * b << endl; break;
                case '/':
                    if (b != 0) 
                        cout << "Result: " << a / b << endl;
                    else 
                        cout << "Error: Cant division by zero!\n";
                    break;
                case '^': 
                    cout << "Result: " << pow(a, b) << endl; break;
                case '%':
                    if ((int)b != 0) 
                        cout << "Result: " << (int)a % (int)b << endl;
                    else 
                        cout << "Error: Cant modulus by zero!\n";
                    break;
                default: 
                    cout << "Invalid operator!\n";
            }
        }
        cout << "Do you want to continue (y/n): ";
        cin >> cont;
    } while (cont == 'y'||cont == 'Y');
}


void temperatureConversion() {
    double temp;
    char unit,cont;
    cout << "-------Temperature Conversion-------" << endl;
    cout << "Enter temperature value and unit(c/f).\nExample: ' 5c '." << endl;
    do{
        cout <<"Temp to convert: ";
        cin >> temp >> unit;
        if (unit == 'c' || unit == 'C')
            cout << "Temp in Fahrenheit: " << (temp * 9/5) + 32 << " F" << endl;
        else if (unit == 'f' || unit == 'F')
            cout << "Temp in celisus: " << (temp - 32) * 5/9 << " C" << endl;
        else
            cout << "Invalid tempretuare unit";
        cout << "Do you want to continue (y/n): ";
        cin >> cont;
    } while (cont == 'y'||cont=='Y');
}

bool february(int y){
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        return true;
    else
        return false;
}
bool inputcorrection(int d, int m,int y){
    if (m < 1 || m > 12 || d < 1) 
        return false;
    int days;
    if (m == 2){
        if( february(y) ==true)
            days = 29;
        else
            days = 28; 
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) 
        days = 30;
    else 
        days = 31;
    if (d <= days)
        return true;
    else
        return false;
}
void dateDifference(){
    char cont;
    int d1, m1, y1, d2, m2, y2;
    int monthdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    cout << "-------Date Difference calculator-------\n";
    do{
    cout << "Enter first date (day month year): ";
    cin >> d1 >> m1 >> y1;
    while (inputcorrection(d1, m1, y1)==false){ 
        cout << "Invalid date Please enter first date (day month year): ";
        cin >> d1 >> m1 >> y1;
    }
    cout << "Enter second date (day month year): ";
    cin >> d2 >> m2 >> y2;
    while (inputcorrection(d2, m2, y2)==false){ 
        cout << "Invalid date Please enter second date (day month year): ";
        cin >> d2 >> m2 >> y2;
    }
    int days1 = y1 * 365 + d1;
    for (int i = 0; i < m1 - 1; i++){
        if(i==1 && february(y1)==true)
            days1 = days1 + 29;
        else
            days1 += monthdays[i];
    }
    int days2 = y2 * 365 + d2;
    for (int i = 0; i < m2 - 1; i++){
        if(i==1 && february(y2)==true)
            days2 = days2 + 29;
        else
            days2 += monthdays[i];
    }
    int diff = abs(days1 - days2);
    int years = diff / 365;
        diff = diff % 365;
    int months = 0;
    for (int i = 0; i < 12 ; i++) {
        diff = diff - monthdays[i];
        if(diff < 0){
            diff += monthdays[i];
            break;
        }months++;
    }
    int days = diff;
    cout << "Difference: " << years << " years, "<< months << " months, "<< days << " days.\n";
    cout << "Do you want to continue (y/n): ";
    cin >> cont;
    }while(cont=='y'||cont=='Y');
}


void currencyConversion() {
    char cont;
    double amount1, amount2, convert;
    string from, to;
    vector<string>currencies = {"USD", "EUR", "EGP", "SAR", "usd", "eur", "egp", "sar"};
    vector<double>rates = {1.0, 0.9, 50.0, 3.75, 1.0, 0.9, 50.0, 3.75};
    cout << "-------Currency Conversion calculator-------\nCurrencies: USD, EUR, EGP, SAR.\nInput example: 'Amount currency'(50 EGP).\n";
    do{
        cout << "Amount to convert from: ";
        cin >> amount1 >> from;
        cout << "convert to (USD, EUR, EGP, SAR): ";
        cin >> to;
        int flag1=0, flag2=0;
        for (int i=0 ; i<currencies.size() ;i++){
            if(from == currencies[i]){
                amount2 = amount1/rates[i];
                flag1=1;
            }if(to == currencies[i]){
                convert = rates[i];
                flag2=1;
            }
        }
        if( flag1==1 && flag2==1 ){
            cout << amount1 << " " << from << " = " << amount2*convert << " " << to <<endl;
            cout << "Do you want to continue (y/n): ";
            cin >> cont;
        }else{
            cout << "Invalid input please enter correct currency." << endl;
            cont = 'y';
        }
    }while(cont=='y'||cont=='Y');
}


void areaCalculation() {
    char cont;
    int shape;
    cout << "1. Square\n2. Rectangle\n3. Circle\n";
    do{
    cout << "Choose shape: ";
    cin >> shape;
    if (shape == 1) {
        double side;
        cout << "Enter side: ";
        cin >> side;
        cout << "Area: " << side * side << "\n";
    } else if (shape == 2) {
        double w, h;
        cout << "Enter width: ";
        cin >> w;
        cout << "Enter height: ";
        cin >> h;
        cout << "Area: " << w * h << "\n";
    } else if (shape == 3) {
        double r;
        cout << "Enter radius: ";
        cin >> r;
        cout << "Area: " << 3.14159 * r * r << "\n";
    } else {
        cout << "Invalid choice!\n";
    }
    cout << "Do you want to continue (y/n): ";
    cin >> cont;
    }while(cont=='y'||cont=='Y');
}

int main() {
    int choice;
    do {
        cout << "\n------- All in one calculator -------\n";
        cout << "1. Calculator\n";
        cout << "2. Temperature Conversion\n";
        cout << "3. Date Difference\n";
        cout << "4. Currency Conversion\n";
        cout << "5. Area Calculation\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: calculator(); break;
            case 2: temperatureConversion(); break;
            case 3: dateDifference(); break;
            case 4: currencyConversion(); break;
            case 5: areaCalculation(); break;
            case 6: cout << "Program exit, run to start again\n"; break;
            default: cout << "Invalid choice please enter correct number.\n";
        }
    } while (choice != 6);

    return 0;
}
