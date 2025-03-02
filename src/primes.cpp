#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
vector<int> primos;
vector<bool> esprimo(MAXN + 1, 1);

void sieve() {
    esprimo[0] = esprimo[1] = 0;
    for (int i = 2; i <= MAXN; ++i) {
        if (esprimo[i]) {
            primos.push_back(i);
            for (int j = 2 * i; j <= MAXN; j += i) {
                esprimo[j] = 0;
            }
        }
    }
}

void imprimirPrimo(int x) {
    cout << "\033[1;32m" << x << " \033[0m";
}

void imprimirporrango(int l, int r) {
    for (int i = max(l, 2); i <= r; ++i) {
        if (esprimo[i]) {
            imprimirPrimo(i);
        }
    }
    cout << "\n";
}

void imprimirindexado(int l, int r) {
    if (l <= 0 || l > (int)primos.size()) {
        cerr << "\033[1;31mEl índice l está fuera de rango.\033[0m" << endl;
        return;
    }
    for (int i = l - 1; i < min(r, (int)primos.size()); ++i) {
        imprimirPrimo(primos[i]);
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    sieve();
    if (argc < 3) {
        cerr << "\033[1;31mUso: " << argv[0] << " [-i] l r\033[0m" << endl;
        return 1;
    }
    
    bool indexado = 0;
    int l, r;
    
    if (string(argv[1]) == "-i") {
        if (argc < 4) {
            cerr << "\033[1;31mUso: " << argv[0] << " -i l r\033[0m" << endl;
            return 1;
        }
        indexado = 1;
        l = stoi(argv[2]);
        r = stoi(argv[3]);
    } else {
        l = stoi(argv[1]);
        r = stoi(argv[2]);
    }
    
    if (indexado) {
        imprimirindexado(l, r);
    } else {
        imprimirporrango(l, r);
    }
    
    return 0;
}
