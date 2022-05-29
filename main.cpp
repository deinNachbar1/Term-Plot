#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <regex>

#define EULER 2.71828183

using namespace std;

int main() {

    char line = '#';

    struct winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    const double row = w.ws_row -1.0;
    const double col = w.ws_col;

    bool screen[(int) col][(int) row];

    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            screen[i][j] = false;
        }
    }

    cout << "\x1B[2J\x1B[H";

    string fun;
    cout << "function type: " << endl;
    cout << "(1) function 1. grade       a*x + b" << endl;
    cout << "(2) function 2. grade       a*x² + b*x + c" << endl;
    cout << "(3) function 3. grade       a*x³ + b*x² + c*x + d" << endl;
    cout << "(4) function 4. grade       a*x⁴ + b*x³ + c*x² + d*x + e" << endl;
    cout << "(5) sin-function            a * sin(b*x + c) + d" << endl;
    cout << "(6) cos-function            a * cos(b*x + c) + d" << endl;
    cout << "(7) tan-function            a * tan(b*x + c) + d" << endl;
    cout << "(8) e-function              a*e^(b*x) + c" << endl;
    cout << endl;
    cin >> fun;

    cout << "\x1B[2J\x1B[H";

    if(fun == "1") {
        string aIn;
        string bIn;

        cout << "function 1. grade | a*x + b" << endl << endl;
        cout << "a: ";
        cin >> aIn;
        cout << "b: ";
        cin >> bIn;

        float a = stof(aIn);
        float b = stof(bIn);

        for(double i = -col/2.0; i < col/2.0; i+=0.01) {
            double x = i + col/2;

            double y = a * i + b;
            y += row/2;

            if(y >= 0 && y < row) {
                screen[(int) round(x)][(int) round(y)] = true;
            }
        }

    }else if(fun == "2") {
        string aIn;
        string bIn;
        string cIn;

        cout << "function 2. grade | a*x² + b*x + c" << endl << endl;
        cout << "a: ";
        cin >> aIn;
        cout << "b: ";
        cin >> bIn;
        cout << "c: ";
        cin >> cIn;

        float a = stof(aIn);
        float b = stof(bIn);
        float c = stof(cIn);



        for(double i = -col/2.0; i < col/2.0; i+=0.01) {
            double x = i + col/2.0;

            double y = a * pow(i, 2) + b * i + c;
            y += row/2;

            if(y >= 0 && y < row) {
                screen[(int) round(x)][(int) round(y)] = true;
            }
        }

    }else if(fun == "3") {

        string aIn;
        string bIn;
        string cIn;
        string dIn;

        cout << "function 3. grade | a*x³ + b*x² + c*x + d" << endl << endl;
        cout << "a: ";
        cin >> aIn;
        cout << "b: ";
        cin >> bIn;
        cout << "c: ";
        cin >> cIn;
        cout << "d: ";
        cin >> dIn;

        float a = stof(aIn);
        float b = stof(bIn);
        float c = stof(cIn);
        float d = stof(dIn);

        for(double i = -col/2.0; i < col/2.0; i+=0.01) {
            double x = i + col/2;

            double y = a * pow(i, 3) + b * pow(i, 2) + c * i + d;
            y += row/2;

            if(y >= 0 && y < row) {
                screen[(int) round(x)][(int) round(y)] = true;
            }
        }

    }else if(fun == "4") {

        string aIn;
        string bIn;
        string cIn;
        string dIn;
        string eIn;

        cout << "function 4. | grade a*x⁴ + b*x³ + c*x² + d*x + e" << endl << endl;
        cout << "a: ";
        cin >> aIn;
        cout << "b: ";
        cin >> bIn;
        cout << "c: ";
        cin >> cIn;
        cout << "d: ";
        cin >> dIn;
        cout << "e: ";
        cin >> eIn;

        float a = stof(aIn);
        float b = stof(bIn);
        float c = stof(cIn);
        float d = stof(dIn);
        float e = stof(eIn);

        for(double i = -col/2.0; i < col/2.0; i+=0.01) {
            double x = i + col/2;

            double y = a * pow(i, 4) + b * pow(i, 3) + c * pow(i, 2) + d * i + e;
            y += row/2;

            if(y >= 0 && y < row) {
                screen[lround(x)][lround(y)] = true;
            }
        }

    }else if(fun == "5") {

        string aIn;
        string bIn;
        string cIn;
        string dIn;

        cout << "sin-function | a * sin(b*x + c) + d" << endl << endl;
        cout << "a: ";
        cin >> aIn;
        cout << "b: ";
        cin >> bIn;
        cout << "c: ";
        cin >> cIn;
        cout << "d: ";
        cin >> dIn;

        float a = stof(aIn);
        float b = stof(bIn);
        float c = stof(cIn);
        float d = stof(dIn);

        for(double i = -col/2.0; i < col/2.0; i+=0.01) {
            double x = i + col/2;

            double y = a * sin((b*i + c)) + d;
            y += row/2;

            if(y >= 0 && y < row) {
                screen[lround(x)][lround(y)] = true;
            }
        }

    }else if(fun == "6") {

        string aIn;
        string bIn;
        string cIn;
        string dIn;

        cout << "cos-function | a * cos(b*x + c) + d" << endl << endl;
        cout << "a: ";
        cin >> aIn;
        cout << "b: ";
        cin >> bIn;
        cout << "c: ";
        cin >> cIn;
        cout << "d: ";
        cin >> dIn;

        float a = stof(aIn);
        float b = stof(bIn);
        float c = stof(cIn);
        float d = stof(dIn);

        for(double i = -col/2.0; i < col/2.0; i+=0.01) {
            double x = i + col/2;

            double y = a * cos((b*i + c)) + d;
            y += row/2;

            if(y >= 0 && y < row) {
                screen[lround(x)][lround(y)] = true;
            }
        }

    }else if(fun == "7") {

        string aIn;
        string bIn;
        string cIn;
        string dIn;

        cout << "tan-function | a * tan(b*x + c) + d" << endl << endl;
        cout << "a: ";
        cin >> aIn;
        cout << "b: ";
        cin >> bIn;
        cout << "c: ";
        cin >> cIn;
        cout << "d: ";
        cin >> dIn;

        float a = stof(aIn);
        float b = stof(bIn);
        float c = stof(cIn);
        float d = stof(dIn);

        for(double i = -col/2.0; i < col/2.0; i+=0.01) {
            double x = i + col/2;

            double y = a * tan((b*i + c)) + d;
            y += row/2;

            if(y >= 0 && y < row) {
                screen[lround(x)][lround(y)] = true;
            }
        }

    }else if(fun == "8") {
        string aIn;
        string bIn;
        string cIn;

        cout << "e-function | a*e^(b*x) + c" << endl << endl;
        cout << "a: ";
        cin >> aIn;
        cout << "b: ";
        cin >> bIn;
        cout << "c: ";
        cin >> cIn;

        float a = stof(aIn);
        float b = stof(bIn);
        float c = stof(cIn);

        for(double i = -col/2.0; i < col/2.0; i+=0.01) {
            double x = i + col/2;

            double y = a * pow(EULER, (b*i)) + c;
            y += row/2;

            if(y >= 0 && y < row) {
                screen[lround(x)][lround(y)] = true;
            }
        }
    }

    cout << "\x1B[2J\x1B[H";

    //print screen ------------------------------------------------------

    for(int i = (int) row; i > 0; i--) {
        for(int j = 0; j < col; j++) {
            if(screen[j][i]) {
                cout << line;
            }else if (i == row && j == (int) (col/2)) {
                cout << "y";
            }else if (j == (col -1) && i == (int) (row/2)) {
                cout << "x";
            }else if (i == (int) (row/2) && j == (int) (col/2)) {
                cout << "+";
            }else if (i == (row -1) && j == (int) (col/2)) {
                cout << "^";
            }else if (i == (int) (row/2) && j == col -2) {
                cout << ">";
            }else if(i == (int) (row/2)) {
                cout << "-";
            }else if(j == (int) (col/2)) {
                cout << "|";
            }else {
                cout << " ";
            }
        }
        cout << endl;
        usleep(1000 * 50);
    }

    return 0;
}

