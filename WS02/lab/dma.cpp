#include <iostream>
#include "dma.h"
using namespace std;
namespace seneca {
    int reverse() {
        int n = 0;

        cout << "Enter the number of double values:\n";
        cout << "> ";
        cin >> n;
        double* arr = new double[n];

        for (int i = 0; i < n; i++) {
            cout << i + 1 << "> ";
            cin >> arr[i];
            cin.clear();
        }

        for (int i = n - 1; i >= 0; i--) {
            cout << arr[i] << "\n";
            cin.clear();
        }

        cin.ignore(1000, '\n');
        delete[] arr;

        return 0;
    }

    Contact* getContact() {
        Contact* cptr = new Contact;

        cout << "Name: ";
        cin >> cptr->m_name;
        cin.clear();

        cout << "Last name: ";
        cin >> cptr->m_lastname;
        cin.clear();

        cout << "Phone number: ";
        cin >> cptr->m_phoneNumber;
        cin.clear();

        cin.ignore(1000, '\n');
        return cptr;
    }

    int display(Contact& cptr) {
        cout << cptr.m_name << " " << cptr.m_lastname << ", ";
        cout << "+" << cptr.m_phoneNumber << "\n";

        if (cptr.m_phoneNumber == 0) {
            cout << "*********************************" << endl;
        }

        return 0;
    }

    int setEmpty(Contact& cptr) {
        cptr.m_name[0] = '\0';
        cptr.m_lastname[0] = '\0';
        cptr.m_phoneNumber = 0;


        return 0;
    }

    int deallocate(Contact* cptr) {
        delete [] cptr;

        return 0;
    }
}
