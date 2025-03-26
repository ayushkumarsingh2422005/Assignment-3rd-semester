#include <iostream>
using namespace std;

void displayPolynomial(int coef[], int expo[], int terms) {
    for (int i = 0; i < terms; i++) {
        cout << coef[i] << "x^" << expo[i];
        if (i < terms - 1) cout << " + ";
    }
    cout << endl;
}

int main() {
    int terms1, terms2;

    // Input for the first polynomial
    cout << "Enter the number of terms in the first polynomial: ";
    cin >> terms1;
    int coef1[terms1], expo1[terms1];
    cout << "Enter coefficients and exponents (in descending order):\n";
    for (int i = 0; i < terms1; i++) {
        cin >> coef1[i] >> expo1[i];
    }

    // Input for the second polynomial
    cout << "Enter the number of terms in the second polynomial: ";
    cin >> terms2;
    int coef2[terms2], expo2[terms2];
    cout << "Enter coefficients and exponents (in descending order):\n";
    for (int i = 0; i < terms2; i++) {
        cin >> coef2[i] >> expo2[i];
    }

    int resultCoef[terms1 + terms2], resultExpo[terms1 + terms2];
    int i = 0, j = 0, k = 0;

    // Adding polynomials
    while (i < terms1 && j < terms2) {
        if (expo1[i] == expo2[j]) {
            resultCoef[k] = coef1[i] + coef2[j];
            resultExpo[k++] = expo1[i];
            i++; j++;
        } else if (expo1[i] > expo2[j]) {
            resultCoef[k] = coef1[i];
            resultExpo[k++] = expo1[i++];
        } else {
            resultCoef[k] = coef2[j];
            resultExpo[k++] = expo2[j++];
        }
    }

    // Copy remaining terms
    while (i < terms1) {
        resultCoef[k] = coef1[i];
        resultExpo[k++] = expo1[i++];
    }
    while (j < terms2) {
        resultCoef[k] = coef2[j];
        resultExpo[k++] = expo2[j++];
    }

    // Display result
    cout << "\nFirst Polynomial: ";
    displayPolynomial(coef1, expo1, terms1);
    cout << "Second Polynomial: ";
    displayPolynomial(coef2, expo2, terms2);
    cout << "Resultant Polynomial after Addition: ";
    displayPolynomial(resultCoef, resultExpo, k);

    return 0;
}
