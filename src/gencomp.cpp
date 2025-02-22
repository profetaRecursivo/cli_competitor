#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

string sanitize_name(const string &name) {
    string sanitized = name;
    for (char &c : sanitized) {
        if (c == ' ') c = '_';
    }
    return sanitized;
}

void create_directory(const string &path) {
    if (mkdir(path.c_str(), 0777) == -1 && errno != EEXIST) {
        cerr << "Error al crear el directorio: " << path << endl;
        exit(1);
    }
}

void create_files(const string &path, int n, const string &snippet) {
    vector<string> names = {"a", "b", "c", "d", "e", "f", "g", "h"};
    for (int i = 0; i < n && i < (int)names.size(); i++) {
        string file_path = path + "/" + names[i] + ".cpp";
        ofstream file(file_path);
        if (!file) {
            cerr << "Error al crear el archivo: " << file_path << endl;
            exit(1);
        }
        file << snippet;
        file.close();
    }
}

string read_snippet(const string &snippet_path) {
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
    
    string competition_name = argv[1];
    string competition_path = getenv("HOME") + string("/competencias/") + sanitize_name(competition_name);
    int num_problems = 0;
    string snippet;

    for (int i = 2; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-n" && i + 1 < argc) {
            num_problems = stoi(argv[++i]);
        } else if (arg == "-snp" && i + 1 < argc) {
            snippet = read_snippet(argv[++i]);
        }
    }
    
    create_directory(competition_path);
    create_files(competition_path, num_problems, snippet);
    
    // Abrir VS Code en la carpeta de la competencia y cerrar la terminal
    string command = "code " + competition_path + " && exit";
    system(command.c_str());
    
    return 0;
}
