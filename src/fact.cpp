#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

/*
    Sin banderas, factorizar un solo número.
    Con la bandera -array o -a, factorizar un array de números.
    Con la bandera -extended o -e, mostrar la factorización extendida (8 = 2, 2, 2 en vez de 2^3).
*/

vector<u64> extendedvec(vector<pair<u64, int>>& vec) {
    vector<u64> ans;
    for (int i = 0; i < (int)vec.size(); i++) {
        while (vec[i].second--) ans.push_back(vec[i].first);
    }
    return ans;
}

vector<pair<u64, int>> tovec(const map<u64, int>& mapa) {
    vector<pair<u64, int>> ans;
    for (auto p : mapa) ans.push_back(p);
    return ans;
}

map<u64, int> fact(u64 x) {
    map<u64, int> factores;
    if (x <= 1) return factores;
    for (u64 i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            factores[i]++;
            x /= i;
        }
    }
    if (x > 1) factores[x]++;
    return factores;
}

void imprimirFact(u64 x, bool extended) {
    auto factores = tovec(fact(x));
    cout << BOLD << "Los factores de " << RESET << RED << x << ": " << RESET << "\n";
    if (extended) {
        cout << BOLD << GREEN;
        auto ans = extendedvec(factores);
        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i];
            if (i + 1 != (int)ans.size()) cout << ", ";
            else cout << '\n';
        }
    } else {
        for (int i = 0; i < (int)factores.size(); i++) {
            cout << BOLD << GREEN << factores[i].first << "^" << factores[i].second << RESET;
            if (i + 1 != (int)factores.size()) {
                cout << ", ";
            } else cout << '\n';
        }
    }
}

int main(int argc, char* argv[]) {
    bool extended = false;
    bool arrayMode = false;

    // Verificar las banderas
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-extended" || arg == "-e") {
            extended = true;
        } else if (arg == "-array" || arg == "-a") {
            arrayMode = true;
        }
    }

    if (arrayMode) {
        // Modo array: factorizar mas de un numero
        cout << BOLD << "Ingresa los números separados por espacios: " << RESET;
        string line;
        getline(cin, line);
        stringstream ss(line);
        u64 num;
        while (ss >> num) {
            imprimirFact(num, extended);
        }
    } else {
        // Modo normal: factorizar un solo número
        if (argc > 1) {
            u64 num;
            try {
                num = stoull(argv[argc - 1]);
                imprimirFact(num, extended);
            } catch (invalid_argument&) {
                cout << RED << "Error: Argumento no válido." << RESET << endl;
            }
        } else {
            cout << BOLD << "Ingresa un número: " << RESET;
            u64 num;
            cin >> num;
            imprimirFact(num, extended);
        }
    }
    return 0;
}