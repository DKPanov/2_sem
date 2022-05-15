#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node* next; //��� Node*: ������ �������� ���� Node
    string data;
};

string last_name (Node* node, int M){
    while (node->next != node){  // (*node).next != node
        for (int i = 0; i < M-2; i++){
            node = node->next;
        }
        Node* next_node = node->next->next; //next_node - ����� ������, ��� ����� ����� ���������
        delete node->next;
        node->next = next_node;
        node = next_node; // ��� node->next
    }
    string result = node->data;
    delete node;
    return result;
}



int main() {

    setlocale(LC_ALL, "rus");

    int N;
    cout << "������� ����� ���������� " << endl;
    cin >> N;

    string name;
    cin >> name;
    Node* first = new Node{nullptr, name}; //������� ��������� ��� ������� ��������
    Node* last = first; //��������� �� ��������� ��� ���������� ��������
    for (int i = 1; i < N; i++){
        cin >> name;
        last->next = new Node{nullptr, name};
        last = last->next;
    }
    last->next = first;

    int M;
    cout << "������� ����� ���� � ���������� " << endl;
    cin >> M;

    cout << last_name(first, M);


    return 0;

}
