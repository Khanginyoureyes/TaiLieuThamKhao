#include <iostream>

using namespace std;

struct Node // Định nghĩa một Node
{
    int data;
    Node* prev;
    Node* next;
};

struct DoubleLinkList // Định nghĩa một danh sách liên kết đôi
{
    Node* Head;
    Node* Tail;
};


void Init(DoubleLinkList& a) // Khởi tạo danh sách liên kết đôi
{
    a.Head = NULL;
    a.Tail = NULL;
}

Node* makeNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void addHead(Node* p, DoubleLinkList& a) // Thêm Node vào đầu danh sách
{
    if (a.Head == NULL)
    {
        a.Head = p;
        a.Tail = a.Head;
    }else
    {
        a.Head->prev = p;
        p->next = a.Head;
        a.Head = p;
    }
}

void addTail(Node* p, DoubleLinkList& a) // Thêm Node vào cuối danh sách
{
    if (a.Head == NULL)
    {
        a.Head = p;
        a.Tail = a.Head;
    }else
    {
        a.Tail->next = p;
        p->prev = a.Tail;
        a.Tail = p;
    }
}

void insertBefore(Node* p, DoubleLinkList& a, int& n, int position)// Thêm trước phần tử
{
    if (a.Head == NULL || position > n + 1 || position < 0)
    {
        cout << "Chen vi tri that bai" << endl;
    }else
    {
        Node* currentNode = a.Head;
        for (int i = 0; i < position - 1; i++)
        {
            currentNode = currentNode->next;
        }
        Node* Prever = currentNode->next->prev;
        p->next = currentNode->next;
        currentNode->next = p;
        Prever = p;
        p->prev = currentNode->next;
    }
}

void Input(DoubleLinkList& a, int& n) // Nhập
{
    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Nhap du lieu: ";
        cin >> data;
        Node* newNode = makeNode(data);
        addTail(newNode, a);
    }
}

void Traverse(DoubleLinkList& a)// Duyệt danh sách liên kết
{
    Node* currentNode = a.Head;
    if (currentNode == NULL)
    {
        cout << "Danh sach rong" << endl;
    }else
    {
        while (currentNode != NULL)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
    }
}


int main()
{
    int n;
    cout << "Nhap kich thuoc cua danh sach: ";
    cin >> n;
    DoubleLinkList a;
    Init(a);

    Input(a, n);
    //Traverse(a);

    /* int x;
    cout << "Nhap du lieu can chen: ";
    cin >> x;
    Node* newNode = makeNode(x);
    addTail(newNode, a);
    Traverse(a); */

    int x, vt;
    cout << "Nhap du lieu can chen: ";
    cin >> x;
    cout << "Nhap vi tri can chen: ";
    cin >> vt;
    Node* newNode = makeNode(x);
    insertBefore(newNode, a, n, vt);
    Traverse(a);
    return 0;
}