#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================================
        STRUCT DEFINITIONS
========================================= */

// Edge (Recommendation)
struct Edge {
    struct Product *dest;
    struct Edge *next;
};

// Product Node
struct Product {
    int id;
    char name[50];
    struct Product *next;
    struct Edge *adj;
};

struct Product *head = NULL;

/* =========================================
        FUNCTION DECLARATIONS
========================================= */

struct Product* createProduct(int, char[]);
struct Product* searchProductById(int);
void addProduct();
void deleteProduct();
void updateProduct();
void searchProduct();
void displayProducts();
void addRecommendation();

/* =========================================
        CREATE PRODUCT NODE
========================================= */

struct Product* createProduct(int id, char name[]) {
    struct Product *newNode =
        (struct Product*)malloc(sizeof(struct Product));

    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->adj = NULL;

    return newNode;
}

/* =========================================
        SEARCH PRODUCT (UTILITY)
========================================= */

struct Product* searchProductById(int id) {
    struct Product *temp = head;

    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

/* =========================================
        CREATE (ADD PRODUCT)
========================================= */

void addProduct() {
    int id;
    char name[50];

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    if (searchProductById(id)) {
        printf("⚠ Product already exists!\n");
        return;
    }

    printf("Enter Product Name: ");
    scanf("%s", name);

    struct Product *newNode = createProduct(id, name);
    newNode->next = head;
    head = newNode;

    printf("✅ Product Added Successfully!\n");
}

/* =========================================
        ADD RECOMMENDATION (EDGE)
========================================= */

void addRecommendation() {
    int id1, id2;

    printf("\nEnter Source Product ID: ");
    scanf("%d", &id1);

    printf("Enter Recommended Product ID: ");
    scanf("%d", &id2);

    struct Product *p1 = searchProductById(id1);
    struct Product *p2 = searchProductById(id2);

    if (!p1 || !p2) {
        printf("❌ Invalid Product ID(s)!\n");
        return;
    }

    struct Edge *newEdge =
        (struct Edge*)malloc(sizeof(struct Edge));

    newEdge->dest = p2;
    newEdge->next = p1->adj;
    p1->adj = newEdge;

    printf("🔗 Recommendation Added!\n");
}

/* =========================================
        READ (DISPLAY PRODUCTS)
========================================= */

void displayProducts() {
    struct Product *temp = head;

    if (!temp) {
        printf("\n⚠ No products available!\n");
        return;
    }

    printf("\n====== PRODUCT LIST ======\n");

    while (temp != NULL) {
        printf("\nID: %d | Name: %s\n", temp->id, temp->name);
        printf("Recommendations: ");

        struct Edge *e = temp->adj;

        if (!e) {
            printf("None");
        }

        while (e != NULL) {
            printf("%s -> ", e->dest->name);
            e = e->next;
        }

        printf("NULL\n");
        temp = temp->next;
    }
}

/* =========================================
        UPDATE PRODUCT
========================================= */

void updateProduct() {
    int id;
    char newName[50];

    printf("\nEnter Product ID to Update: ");
    scanf("%d", &id);

    struct Product *p = searchProductById(id);

    if (!p) {
        printf("❌ Product Not Found!\n");
        return;
    }

    printf("Enter New Name: ");
    scanf("%s", newName);

    strcpy(p->name, newName);

    printf("✏ Product Updated Successfully!\n");
}

/* =========================================
        DELETE PRODUCT
========================================= */

void deleteProduct() {
    int id;
    printf("\nEnter Product ID to Delete: ");
    scanf("%d", &id);

    struct Product *temp = head, *prev = NULL;

    while (temp && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("❌ Product Not Found!\n");
        return;
    }

    // Remove edges pointing to this product
    struct Product *p = head;
    while (p != NULL) {
        struct Edge *e = p->adj, *prevE = NULL;

        while (e != NULL) {
            if (e->dest == temp) {
                if (prevE)
                    prevE->next = e->next;
                else
                    p->adj = e->next;

                free(e);
                break;
            }
            prevE = e;
            e = e->next;
        }
        p = p->next;
    }

    // Remove node
    if (prev)
        prev->next = temp->next;
    else
        head = temp->next;

    // Free adjacency listṇ
    struct Edge *e = temp->adj;
    while (e) {
        struct Edge *del = e;
        e = e->next;
        free(del);
    }

    free(temp);

    printf("🗑 Product Deleted Successfully!\n");
}

/* =========================================
        SEARCH PRODUCT
========================================= */

void searchProduct() {
    int id;

    printf("\nEnter Product ID to Search: ");
    scanf("%d", &id);

    struct Product *p = searchProductById(id);

    if (!p) {
        printf("❌ Product Not Found!\n");
        return;
    }

    printf("🔍 Found → ID: %d | Name: %s\n", p->id, p->name);
}

/* =========================================
        MAIN MENU (MENU-DRIVEN)
========================================= */

int main() {
    int choice;

    while (1) {
        printf("\n====================================\n");
        printf("  ONLINE MARKETPLACE GRAPH SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Node\n");
        printf("2. Delete Node\n");
        printf("3. Update Node\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Add Recommendation\n");
        printf("7. Exit\n");
        printf("====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: deleteProduct(); break;
            case 3: updateProduct(); break;
            case 4: searchProduct(); break;
            case 5: displayProducts(); break;
            case 6: addRecommendation(); break;
            case 7: exit(0);
            default: printf("⚠ Invalid Choice!\n");
        }
    }

    return 0;
}  