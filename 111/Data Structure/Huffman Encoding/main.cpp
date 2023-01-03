#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <streambuf>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
};

Node* getNode(char ch, int freq, Node* left, Node* right) {
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

struct comp {
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

void compress(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    compress(root->left, str + "0", huffmanCode);
    compress(root->right, str + "1", huffmanCode);
}

void decompress(Node* root, int &index, string str) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        cout << root->ch;
        ofstream output("output.txt", ios_base::app);
        output << root->ch;
        return;
    }

    index++;

    if (str[index] =='0') {
        decompress(root->left, index, str);
    }
    else {
        decompress(root->right, index, str);
    }
}

void buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, comp> queue;

    for (auto pair: freq) {
        queue.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (queue.size() != 1) {
        Node *left = queue.top(); queue.pop();
        Node *right = queue.top();	queue.pop();

        int sum = left->freq + right->freq;
        queue.push(getNode('\0', sum, left, right));
    }

    Node* root = queue.top();

    unordered_map<char, string> huffmanCode;
    compress(root, "", huffmanCode);

    ofstream codes("code.txt");

    cout << "Huffman Codes\n" << "--------------------------------\n" << '\n';
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
        codes << (int)pair.first << " " << pair.second << '\n';
    }

    codes.close();

    cout << "\nOriginal string was :\n" << text << '\n';

    string str = "";
    for (char ch: text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is :\n" << str << '\n';

    int encodedLength = str.size();

    while (str.size() % 8 != 0) {
        str += '0';
    }

    ofstream out("compressed", ios::binary);
    for (int i = 0; i < (int)str.size(); i += 8) {
        bitset<8> bits(str.substr(i, 8));
        out << char(bits.to_ulong());
    }

    out.close();

    ifstream in("compressed", ios::binary);
    string encodedString;
    char ch;
    while (in.get(ch)) {
        encodedString += bitset<8>(ch).to_string();
    }

    cout << "\nEncoded string from file is :\n" << encodedString << '\n';

    encodedString = encodedString.substr(0, encodedLength);

    cout << "\nEncoded string from file after removing additional zeroes :\n" << encodedString << '\n';

    str = encodedString;

    in.close();

    cout << "\n";

    cout << "Huffman codes from code.txt :\n" << "--------------------------------\n" << '\n';

    ifstream codes2("code.txt");
    unordered_map<char, string> huffmanCode2;
    string line;
    while (getline(codes2, line)) {
        stringstream ss(line);
        int ch;
        string code;
        ss >> ch >> code;
        huffmanCode2[(char)ch] = code;
        cout << (char)ch << " " << code << '\n';
    }
    
    codes2.close();

    unordered_map<char, Node*> tree;
    for (auto pair: huffmanCode2) {
        Node* node = getNode(pair.first, 0, nullptr, nullptr);
        tree[pair.first] = node;
    }

    Node* root2 = getNode('\0', 0, nullptr, nullptr);
    for (auto pair: huffmanCode2) {
        Node* node = tree[pair.first];
        Node* parent = root2;
        for (int i = 0; i < (int)pair.second.size(); i++) {
            if (pair.second[i] == '0') {
                if (parent->left == nullptr) {
                    parent->left = getNode('\0', 0, nullptr, nullptr);
                }
                parent = parent->left;
            }
            else {
                if (parent->right == nullptr) {
                    parent->right = getNode('\0', 0, nullptr, nullptr);
                }
                parent = parent->right;
            }
        }
        parent->ch = pair.first;
    }

    int index = -1;
    cout << "\nDecoded string is: \n";

    ofstream output("output.txt");

    while (index < (int)str.size() - 2) {
        decompress(root2, index, str);
    }

    output.close();

    cout << '\n';
}

int main()
{
    ifstream t("input.txt");

    string str((std::istreambuf_iterator<char>(t)),
               std::istreambuf_iterator<char>());

    buildHuffmanTree(str);
    t.close();

    return 0;
}