/*
#include<iostream>
using namespace std;
const int maxvex=100;
typedef bool state;
int indegree[maxvex]{};
typedef struct edgenode {
    int adj;
    //int weight;
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
        g->ad[i].firstedge=NULL;
    }
    for (int k = 0; k < g->numedges; k++)
    {
        cin >> i >> j;
        e = new edgenode();
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
state TopologicalSort(graphadj*g) {
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
    while (0 != top) {
        gettop = stack[top--];
        cout << "弹出的节点为:" << g->ad[gettop].data << endl;
        count++;
        for (e = g->ad[gettop].firstedge; e; e = e->next)
        {
            k = e->adj;
            cout <<"neiborhood:"<< k <<"开始前的节点"<<g->ad[k].in<< endl;
            if (!(--(g->ad[k].in))){
            stack[++top] = k;
            cout << "减后出度为:"<< g->ad[k].in << endl;
            } 
            cout << "减后出度为:" << g->ad[k].in << endl;
            //注意在条件判断的时候就已经对neiborhood 剪过再进行if 会导致在剪一次。
            
            //else{
               // --(g->ad[k].in);
               // cout << "减后出度为:" << g->ad[k].in << endl;
            //}     
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

int main() {
    graphadj gr;
    createalgraph(&gr);
    bool flag = TopologicalSort(&gr);
    if (flag) {
        cout << "无环" << endl;
    }
    else {
        cout << "有环" << endl;
    }
    return 0;
}
*/