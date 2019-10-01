#include <iostream>
using namespace std;

/**********************************************************************************************
 * Tao cau truc Node gom du lieu va cac nhanh TRAI, nhanh PHAI
 *                 [ data ]
 *                 /      \
 *            [ pLeft]   [pRight]
 *             /             \ (pRight)
 *          [data2]        [data3]
 *          /    \             \(pRight)
 *      [data4]  [data5]       [data6]
**********************************************************************************************/

struct node{
    int data;
    struct node *pLeft;
    struct node *pRight;
};

typedef struct node Node;
typedef Node* TREE;

void emptyNode(TREE t){   // Khoi Tao Node Moi  /// Empty Node cai da
    t = NULL;   
}
/**********************************************************************************************
 * Ham : Them Gia Tri moi vao Node
 * Tham So  : Cay Node , gia tri Dau vao (val)
 * Kieu Tra Ve : Void 
 * Mo Ta : Gia tri dau tien them vao la Node goc , gia tri ke tiep them vao node theo quy tac nh
 *     nho hon Node Goc thi di qua ben trai con lon hon Node Goc thi qua ben phai
 * Cap Nhat Node moi lan them gia tri moi
**********************************************************************************************/
void createNode(TREE &t, int val){
    if(t == NULL) {
        Node *p = new Node;             // Tao node moi de luu gia tri vao Node do
        p->data = val;                  // Tien hanh gan gia tri cho node 
        p->pLeft = NULL;
        p->pRight = NULL;               // Gan Node TRAI vaa Node PHAI bang NULL de con them gia tri vao lan sao
        t = p;                          // Cap Nhat gia tri cho Node
    }
    else
    {
        if(t->data > val)                 // Do gia tri them vao < gia tri Node goc nen them vao TRAI
        {    createNode(t->pLeft,val);}     // Duyet Node sang TRAI de tao them gia tri moi vao node
        else if(t->data < val)            //  Do gia tri them vao < gia tri Node goc nen them vao PHAI
        {    createNode(t->pRight,val);}    // Duyet Node sang PHAI de tao them gia tri moi vao node
    }
}
/************************************************************************************************
 * Duyet Node 
 * Mo ta : Duyet Theo Quy Tac tu TRAI --> Node --> PHAI (tu thap len cao)
 *    . Gap node nao thi xuat gia tri trai node do theo thu tu tang dan
************************************************************************************************/
void DuyetLNR(TREE p){
    if(p != NULL){
        DuyetLNR(p->pLeft);      // Duyet Qua TRAI de tim gia tri
        cout << p->data << " "; // Xuat gia tri Tai Node duoc duyet den
        DuyetLNR(p->pRight);     // Duyet Qua PHAI de tim gia tri
    }
}
/************************************************************************************************
 * Ham : Xac Dinh Node Hai La, Node Mot La, Node La
 * Tham So : Node*
 * Mo Ta : Duyet Node Toi khi Nao NULL thi dung
 *    - Node_Hai_La : Node TRAI "va" Node PHAI khong phai la NULL
 *    - Node_Mot_La : Node TRAI NULL "hoac" Node PHAI la NULL hoac nguoc lai
 *    - Node_La : Ca Node TRAI "va" Node PHAI deu NULL
 ************************************************************************************************/
void Node_Hai_La(TREE t){
    if(t != NULL){                               // Duyet den Node cuoi cung
        if(t->pLeft != NULL && t->pRight != NULL) // Ca Hai Nhanh cua Node khong phai NULL thi xuat gia tri
            cout << t->data << "\t";
        Node_Hai_La(t->pLeft);                   // De Quy Qua Node Ben TRAI Node hien tai
        Node_Hai_La(t->pRight);                  // De Quy Qua Node Ben PHAI Node hien tai
    }  
}
void Node_Mot_La(TREE p){
    if(p != NULL){
        if((p->pLeft != NULL && p->pRight == NULL) || (p->pLeft == NULL && p->pRight != NULL ))
            cout << p->data << "\t";
        Node_Mot_La(p->pLeft);                   // De Quy Qua Node Ben TRAI Node hien tai
        Node_Mot_La(p->pRight);                  // De Quy Qua Node Ben PHAI Node hien tai
    }
}
void Node_La(TREE p){
    if(p != NULL){
        if(p->pLeft == NULL && p->pRight == NULL)
            cout << p->data << "\t";
        Node_La(p->pLeft);
        Node_La(p->pRight);
    }
}
/************************************************************************************************
 * Ham : TimMax, TimMin
 * Tham So : Node*, MAX, MIN
 * Mo Ta : Duyet Node den Phan tu Node Cuoi Cung
 *    - TimMax : Duyet Node sang PHAI so voi Node hien tai , cu lap lai den khi nao p->pRight == NULL
 *               thi dung , cu moi lan duyet den Node nao thi cap Nhat gia tri MAX tai Node do
 *    - TimMin : Duyet Node sang TRAI so voi Node hien tai , cu lap lai den khi nao p->pLeft == NULL
 *               thi dung , cu moi lan duyet den Node nao thi cap Nhat gia tri MIN tai Node do
 ************************************************************************************************/
void TimMax(TREE p, int &MAX){  
    if(p != NULL){
        if(p->data > MAX)
            MAX = p->data;
        TimMax(p->pRight,MAX);
    }
}
void TimMin(TREE p, int &MIN){
    if(p != NULL){
        if(p->data < MIN)
            MIN = p->data;
        TimMin(p->pLeft,MIN);
    }
}
void TimGiaTri(TREE p, int val,bool &check){
    if(p != NULL){
        if(p->data == val){
            check = true;
        }
        TimGiaTri(p->pLeft,val,check);
        TimGiaTri(p->pRight,val ,check);
    }
}
void XoaNode(TREE p,int val){
    if(p != NULL){
        if(p->data < val)
            XoaNode(p->pRight,val);
        else if(p->data > val)
            XoaNode(p->pLeft,val);
        else                         // p->data == value 
        {
            Node *X = p;
            p->pLeft;
            X->data = p->data;
            delete X; 
        }  
            
    }
    
}
int main(){ 
    node* nod = NULL;
    // node nodl = &nod;
    emptyNode(nod);
    createNode(nod,-2);
    createNode(nod,9);
    createNode(nod,2);
    createNode(nod,7);
    createNode(nod,11);
    createNode(nod,4);
    createNode(nod,8);
    createNode(nod,6);
    createNode(nod,-11);
    createNode(nod,3);
    createNode(nod,19);
    DuyetLNR(nod);
    cout <<"\nNode Hai La : " <<  endl;   
    Node_Hai_La(nod);
    cout <<"\nNode Mot La : " <<  endl;   
    Node_Mot_La(nod);
    cout <<"\nNode La : " <<  endl;   
    Node_La(nod);
    int MAX = 0, MIN = 0;
    bool check = false;
    TimMax(nod,MAX);
    cout << "\nMAX : " << MAX;
    TimMin(nod,MIN);
    cout << "\nMIN : " << MIN;
    TimGiaTri(nod,1,check);
    if(check == true)
        cout << "\nTim Thay Gia Tri Ban Can Tim \n";
    else 
        cout << "\nKhong Tim Thay Gia Tri Ban Can Tim \n";
    XoaNode(nod,11);
    DuyetLNR(nod);
    cout << endl;
    return 0;
}