#include<iostream>
using namespace std;
const int maxvex = 100;
typedef bool state;
int indegree[maxvex]{};
typedef struct edgenode {
    int adj;
    int weight;
    edgenode* next;
} edgenode;
typedef struct vexnode {
    char data;
    edgenode* firstedge;//指向箭头的点
    int in;
}vexnode, adjlist[maxvex];
typedef struct {
    adjlist ad;
    int numvex, numedges;
}graphadj;
void createalgraph(graphadj* g) {
    int i, j, k;
    edgenode* e;
    cin >> g->numvex >> g->numedges;
    for (int i = 0; i < g->numvex; i++) {
        cin >> g->ad[i].data;
        cout << g->ad[i].data << "  ";
        g->ad[i].firstedge = NULL;
    }
    cout << endl;
    for (int k = 0; k < g->numedges; k++)
    {
        e = new edgenode();
        cin >> i >> j >> e->weight;
        e->adj = j;
        e->next = g->ad[i].firstedge;
        g->ad[i].firstedge = e;
        //cout << indegree[j] << endl;
        indegree[j]++;
    }
    for (int i = 0; i < g->numvex; i++)
    {

        g->ad[i].in = indegree[i];
        cout << "出度表为:" << g->ad[i].in << "   ";
    }
    cout << endl;
}
int* stack2;
int top2;
int* evt;
int* lvt;
state TopologicalSort(graphadj* g) {
    edgenode* e;
    int k, gettop;
    int count = 0;
    int top = 0;
    int* stack;
    stack = new int[g->numvex];
    for (int i = 0; i < g->numvex; i++) {
        if (0 == g->ad[i].in) {
            stack[++top] = i;
        }
    }
    top2 = 0;
    evt = new int[g->numvex];
    for (int i = 0; i < g->numvex; i++) {
        evt[i] = 0;
    }
    stack2 = new int[g->numvex];
    while (0 != top) {
        gettop = stack[top--];
        stack2[++top2] = gettop;
        cout << "弹出的节点为:" << g->ad[gettop].data << endl;
        count++;
        for (e = g->ad[gettop].firstedge; e; e = e->next)
        {
            k = e->adj;
            cout << "neiborhood:" << k << "开始前的节点" << g->ad[k].in << endl;
            if (!(--(g->ad[k].in))) {
                stack[++top] = k;
                cout << "减后出度为:" << g->ad[k].in << endl;
            }
            cout << "减后出度为:" << g->ad[k].in << endl;
            if (evt[gettop] + e->weight > evt[k]) {
                evt[k] = evt[gettop] + e->weight;
            }
        }
    }
    cout << count << endl;
    if (count < g->numvex) {//说明有环; 
        return false;
    }
    else {
        return true;
    }
}
void criticalpath(graphadj* g) {
    edgenode* e;
    int gettop, k;
    int ete, lte;

    bool ast = TopologicalSort(g);
    lvt = new int[g->numvex];
    for (int i = 0; i < g->numvex; i++) {
        lvt[i] = evt[g->numvex-1];
    }
    while (top2 != 0) {
        gettop = stack2[top2--];
        for (e = g->ad[gettop].firstedge; e; e = e->next) {
            k = e->adj;
            if (lvt[k] - e->weight < lvt[gettop]){
                lvt[gettop] = lvt[k] - e->weight;
            }
        }
    }
    for (int i = 0; i < g->numvex; i++) {
        for (e = g->ad[i].firstedge; e; e = e->next) {
            k = e->adj;
            ete = evt[i];
            lte = evt[k] - e->weight;
            if (ete == lte) {
                //printf("<%s -> %s> length: %d", g->ad[i].data, g->ad[k].data, e->weight);
                cout << g->ad[i].data << " " << "->" << " " << g->ad[k].data << " " << "length:" << e->weight<< "   ";
            }
        }
    }
}

int main() {
    graphadj gr;
    createalgraph(&gr);
    criticalpath(&gr);
    return 0;
}