#include <iostream>
using namespace std;

class ArrayDemo {
public:
    void oneD() {
        int arr[5] = {1, 2, 3, 4, 5};
        cout << "1D Array: ";
        for (int i = 0; i < 5; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void twoD() {
        int arr[2][2] = {{1, 2}, {3, 4}};
        cout << "2D Array:\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    void threeD() {
        int arr[2][2][2] = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
        cout << "3D Array:\n";
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    cout << "arr[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl;
    }
};

int main() {
    ArrayDemo a;
    a.oneD();
    a.twoD();
    a.threeD();
    return 0;
}

