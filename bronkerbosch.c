#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 1000 // Maksimum düğüm sayısı

// Graf yapısı
typedef struct {
    int n; // düğüm sayısı
    bool adj[MAXV][MAXV]; // komşuluk matrisi
} Graph;

// Yığın yapısı
typedef struct {
    int items[MAXV];
    int top;
} Stack;

// Yığın işlemleri
void initializeStack(Stack *stack) {
    stack->top = -1;
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

bool isFull(Stack *stack, int n) {
    return stack->top == n-1;
}

void push(Stack *stack, int value) {
    if (isFull(stack, MAXV)) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1;
    }
    int value = stack->items[stack->top];
    stack->top--;
    return value;
}

// Bron-Kerbosch algoritması
void bronKerbosch(Graph *graph, Stack *r, Stack *p, Stack *x, bool *cliques) {
    if (isEmpty(p) && isEmpty(x)) {
        // R yığını bir maksimal klik oluşturuyor
        int i;
        for (i = 0; i <= r->top; i++) {
            cliques[r->items[i]] = true;
        }
        return;
    }
    int pivot = -1, i, j;
    for (i = 0; i < graph->n; i++) {
        if (!cliques[i]) {
            if ((isEmpty(p) || !graph->adj[i][p->items[p->top]]) && (isEmpty(x) || !graph->adj[i][x->items[x->top]])) {
                pivot = i;
                break;
            }
        }
    }
    if (pivot == -1) {
        return;
    }
    for (j = 0; j < graph->n; j++) {
        if (!cliques[j] && graph->adj[pivot][j]) {
            push(p, j);
            Stack new_r, new_p, new_x;
            initializeStack(&new_r);
            initializeStack(&new_p);
            initializeStack(&new_x);
            for (i = 0; i <= r->top; i++) {
                push(&new_r, r->items[i]);
            }
            for (i = 0; i <= p->top; i++) {
                if (graph->adj[p->items[i]][j]) {
                    push(&new_p, p->items[i]);
                }
            }
            for (i = 0; i <= x->top; i++) {
                if (graph->adj[x->items[i]][j]) {
                    push(&new_x, x->items[i]);
                }
            }
            bronKerbosch(graph, &new_r, &new_p, &new_x, cliques);
            pop(p);
            push(x, j);
        }
    }
}

// Test için grafımızı tanımlayacağız
int main() {
    Graph graph; 
    int i, j, n, m;
printf("Dugum sayisini girin: ");
scanf("%d", &n);
graph.n = n;
for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
        graph.adj[i][j] = false;
    }
}
printf("Baglanti sayisini girin: ");
scanf("%d", &m);
for (i = 0; i < m; i++) {
    int u, v;
    printf("Baglanti %d icin baslangic ve bitis dugumlerini girin: ", i+1);
    scanf("%d %d", &u, &v);
    graph.adj[u][v] = true;
    graph.adj[v][u] = true;
}
Stack r, p, x;
initializeStack(&r);
initializeStack(&p);
initializeStack(&x);
bool cliques[MAXV] = {false};
bronKerbosch(&graph, &r, &p, &x, cliques);
printf("Tum maksimal klikler:\n");
for (i = 0; i < graph.n; i++) {
    if (cliques[i]) {
        printf("%d ", i);
    }
}
printf("\n");
return 0;
}