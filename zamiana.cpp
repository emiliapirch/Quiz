#include <fstream>
#include <iostream>
using namespace std;

bool IsBlank(char a) {return (a == ' ' || a == '\n' || a == '\t' || (int)a == 0);}
string RawString(string s) {
    string res = "";
    for (int i=0; i<s.size(); i++) {
        if (!IsBlank(s[i])) res += s[i];
    }
    return res;
}

/* bool IfComment(string line) {
    if ((line[0] == '/' && line[1] == '/')) return true;
    else return false;
} */

bool ActiveLine(string line) {
    if ((line[0] == '/' && line[1] == '/') || line.size() == 0 || line[0] == '\n') return false;
    line = RawString(line);
    for (int i=0; i<line.size(); i++)
        if (line[i] == '-') return true;
    return false;
}

string make_name(string org) {
    string org1 = "";
    /*for (int i=0; i<org.size(); i++) {
        if (org[i] == '.') org1 += "_rev.";
        else org1 += org[i];
    }*/
    org1 = org + "_rev";
    return org1;
}

string clear_string(string s) {
    string res;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == ' ' && (i == 0 || i == s.size()-1)) {
            continue;
        }
        else res += s[i];
    }
    return res;
}

pair<string, string> rev_question(string line) {
    string question, answer;
    bool q = true;

    for (int  i=0; i<line.size(); i++) {
        if (line[i] == '-' && q) q = false;
        else if (q) question += line[i];
        else answer += line[i];
    }

    question = clear_string(question);
    answer = clear_string(answer);

    return {question, answer};
}

string EraseEnding(string line) {
    string ending = "_rev";
    int ind = ending.size() - 1;

    if (line.size() <= ending.size()) return line;

    for (int i=line.size()-1; i>line.size() - ending.size(); i--) {
        if (line[i] != ending[ind--]) return line;
    }

    string res = "";
    for (int i=0; i<line.size() - ending.size(); i++) {
        res += line[i];
    }
    return res;
}

int main() {
    string line, orgpath;

    ofstream rev;
    ifstream org, srcfile;

    srcfile.open("source.txt", ios::in);
    if (!srcfile.is_open()) {
        cout << "Plik source.txt nie istnieje.\n";
        exit(0);
    }

    getline(srcfile, orgpath);

    orgpath = EraseEnding(orgpath);

    org.open(orgpath, ios::in);
    if (!org.is_open()) {
        cout << "Plik "<< orgpath <<" nie istnieje.\n";
        exit(0);
    }

    rev.open(make_name(orgpath), ios::out);

    if (!rev.is_open()) {
        cout << "Plik " << make_name(orgpath) << " nie istnieje.\n";
        exit(0);
    }

    while (getline(org, line)) {
        if (!ActiveLine(line)) {
            rev << line << '\n';
        }

        else {
            pair<string, string> set = rev_question(line);

            string op1 = set.first + " -" + set.second;
            string op2 = set.second + " -" + set.first;
            rev << op1 << "\n" << op2 << "\n\n";
        }
    }

    srcfile.close();
    org.close();
    rev.close();
}

