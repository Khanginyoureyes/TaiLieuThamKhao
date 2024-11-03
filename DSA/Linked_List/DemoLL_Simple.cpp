#include <iostream>

using namespace std;

struct Node // Định nghĩa một Node
{
    int data;
    Node* next;
};

Node* makeNode(int x) // Tạo một Node mới
{
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;  
}

struct linkList // Định nghĩa một danh sách liên kết đơn
{
    Node* Head;
    Node* Tail;             
};

void Init(linkList &a) // Khởi tạo một danh sách liên kết đơn rỗng
{
    a.Head = NULL;
    a.Tail = NULL;
}

void Traverse(linkList& a) // Duyệt danh sách liên kết đơn
{
    Node* p = a.Head;
    if (p == NULL)
    {
        cout << "Danh sach rong" << endl;
    }else
    {
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    cout << endl;
}

void addHead(Node* p, linkList& a) // Thêm đầu danh sách
{
    if (a.Head == NULL)
    {
        a.Head = p;
        a.Tail = a.Head;
    }else
    {
        p->next = a.Head;
        a.Head = p;
    }
}

void addTail(Node* p, linkList& a) // Thêm cuối danh sách
{
    if (a.Head == NULL)
    {
        addHead(p, a);
    }else
    {
        a.Tail->next = p;
        a.Tail = p;
    }
}

int countNode(linkList& a) // Đếm Node
{
    int count = 0;
    Node* p = a.Head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void addPosition(Node* p, linkList& a, int position) // Thêm vị trí bất kì trong LL
{
    int size = countNode(a);
    if (position < 1 || position > size + 1)
    {
        cout << "Vi tri chen khong hop le" << endl;
    }else if (position == 1)
    {
        addHead(p, a);
    }else if (position == size + 1)
    {
        addTail(p, a);
    }else
    {
        Node* current = a.Head;
        for (int i = 0;  i < position - 1; i++)
        {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
    }
}



void InputLL(linkList& a, int& n) // Input danh sách liên kết đơn
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

void Output(linkList& a) // Output danh sách liên kết
{
    Traverse(a);
}

void DeleteHead(linkList& a) // Xoá đầu danh sách liên kết
{
    int x;
    Node* p;
    if (a.Head != NULL)
    {
        x = a.Head->data;
        p = a.Head;
        a.Head = a.Head->next;
        if (a.Head == NULL)
        {
            a.Tail = NULL;
        }
        delete p;
    }
}

void DeleteTail(linkList& a) // Xoá cuối danh sách
{
    if (a.Head == NULL)
    {
        a.Tail = NULL;
        return;
    }else if (a.Head->next == NULL)
    {
        DeleteHead(a);
    }else
    {
        Node* currentNode = a.Head;
        while (currentNode->next->next != NULL)
        {
            currentNode = currentNode->next;
        }
        Node* p;
        int x;
        x = a.Tail->data;
        p = a.Tail;
        currentNode->next = NULL;
        a.Tail = currentNode;
        delete p;
    }
}

int main()
{
    int n;
    cout << "Nhap kich thuoc cua danh sach lien ket: ";
    cin >> n;
    linkList a;
    Init(a);
    InputLL(a, n);

    //cout << countNode(a) << " Node";

    cout << "Danh sach vua nhap la: ";
    Output(a);

    /* int data;
    cout << "Nhap du lieu muon them vao dau: ";
    cin >> data;
    Node* newNode = makeNode(data);
    addHead(newNode, a);
    cout << "Danh sach sau khi chen dau la: ";
    Output(a); */

    /* int data, vt;
    cout << "Nhap vi tri can chen: ";
    cin >> vt;
    cout << "Nhap du lieu can chen: ";
    cin >> data;
    Node* newNode = makeNode(data);
    addPosition(newNode, a, vt);
    Output(a); */

    /* DeleteHead(a);
    cout << "Danh sach sau khi xoa dau la: ";
    Output(a); */

    DeleteTail(a);
    cout << "Danh sach sau khi xoa cuoi la: ";
    Output(a);
    return 0;
}