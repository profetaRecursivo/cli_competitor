#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

string limpiarnombre(string &name) {
    string ans = name;
    for (char &c : ans) {
        if (c == ' ') c = '_';
    }
    return ans;
}

void crearDirectorio( string &path) {
    if (mkdir(path.c_str(), 0777) == -1 && errno != EEXIST) {
        cerr << "Error al crear el directorio: " << path << endl;
        exit(1);
    }
}

void crearArchivos(string &path, int n, string &snippet) {
    for (int i = 0; i < n; i++) {
        string nombreArchivo;
        int num = i;
        while (num >= 0) {
            nombreArchivo = char('a' + (num % 26)) + nombreArchivo;
            num = num / 26 - 1;
        }
        string ruta = path + "/" + nombreArchivo + ".cpp";
        ofstream file(ruta);
        if (!file) {
            cerr << "Error al crear el archivo: " << ruta << endl;
            exit(1);
        }
        file << snippet;
        file.close();
    }
}


string leerssnipet(const string &snippet_path) {
    ifstream file(snippet_path);
    if (!file) {
        cerr << "Error al abrir el snippet: " << snippet_path << endl;
        exit(1);
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " \"nombre competencia\" -n <num_problemas> [-snp <snippet>]" << endl;
        return 1;
    }
    
    string nombreCompetencia = argv[1];
    string rutaBase = getenv("HOME") + string("/competencias");
    string rutaCompetencia = rutaBase + "/" + limpiarnombre(nombreCompetencia);
    int numProblemas = 0;
    string snippet;

    for (int i = 2; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-n" && i + 1 < argc) {
            numProblemas = stoi(argv[++i]);
        } else if (arg == "-snp" && i + 1 < argc) {
            snippet = leerssnipet(argv[++i]);
        }
    }
    
    crearDirectorio(rutaBase);
    crearDirectorio(rutaCompetencia);

    crearArchivos(rutaCompetencia, numProblemas, snippet);
    string command = "code " + rutaCompetencia + " && exit";
    system(command.c_str());
    return 0;
}
