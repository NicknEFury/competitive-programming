#include <string>

using namespace std;

struct Trie {
    static const int k = 26;

    struct Vertex {
        Vertex* to[k] = {0};
        bool terminal = false;
    };

    Vertex* root;

    Trie() : root(new Vertex()) {}

    void add_string(string &s) {
        Vertex* v = root;
        for (char c : s) {
            c -= 'a';
            if (!v->to[c])
                v->to[c] = new Vertex();
            v = v->to[c];
        }
        v->terminal = true;
    }

    bool find(string &s) {
        Vertex* v = root;
        for (char c : s) {
            c -= 'a';
            if (!v->to[c]) return false;
            v = v->to[c];
        }
        return v->terminal;
    }

    bool erase(string &s) {
        Vertex* v = root;
        for (char c : s) {
            c -= 'a';
            if (!v->to[c])
                return false;
            v = v->to[c];
        }
        bool existed = v->terminal;
        v->terminal = false;
        return existed;
    }
};


