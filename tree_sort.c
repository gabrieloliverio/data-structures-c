#include <stdio.h>
#include <malloc.h>
#define MAX 10

struct tree {
    struct tree *left;
    struct tree *right;
    int num;
};

void insert(struct tree **, int);
void in_order(struct tree *);

int main() {
    struct tree *t;
    int arr[MAX] = {1, 48, 3, 25, 4, 53, 43, 99, 85, 0};
    t = NULL;

    printf("\nUnsorted array: ");
    for (int i = 0; i < MAX; i++) {
        printf("\t%d", arr[i]);
    }

    for (int i = 0; i < MAX; i++) {
        insert(&t, arr[i]);
    }

    printf("\nSorted array: \t");
    in_order(t);
}

void insert(struct tree **t, int num) {
    if (*t == NULL) {
        *t = malloc(sizeof(struct tree));
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->num = num;
    } else {
        if (num < (*t)->num) {
            insert(&((*t)->left), num);
        } else {
            insert(&((*t)->right), num);
        }
    }
}

void in_order(struct tree *t) {
    if (t != NULL) {
        in_order(t->left);
        printf("\t%d", t->num);
        in_order(t->right);
    }
}

