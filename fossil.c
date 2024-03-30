#include <stdio.h>
#include <stdlib.h>

// Define the structure of a fossil node
struct fossilNode {
    char name[50];
    struct fossilNode* next;
};

// Define the structure of the fossil stack
struct fossilStack {
    struct fossilNode* top;
};

// Create a new fossil node with a given name
struct fossilNode* createFossilNode(char name[]) {
    struct fossilNode* newNode = (struct fossilNode*) malloc(sizeof(struct fossilNode));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory for new fossil node.\n");
        return NULL;
    }
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

// Initialize a new empty fossil stack
void initFossilStack(struct fossilStack* stack) {
    stack->top = NULL;
}

// Check if the fossil stack is empty
int isFossilStackEmpty(struct fossilStack* stack) {
    return (stack->top == NULL);
}

// Push a new fossil onto the top of the stack
void pushFossil(struct fossilStack* stack, char name[]) {
    struct fossilNode* newNode = createFossilNode(name);
    if (newNode == NULL) {
        printf("Error: Unable to create new fossil node.\n");
        return;
    }
    newNode->next = stack->top;
    stack->top = newNode;
}

// Pop the top fossil from the stack and return its name
char* popFossil(struct fossilStack* stack) {
    if (isFossilStackEmpty(stack)) {
        printf("Error: Fossil stack is empty.\n");
        return NULL;
    }
    struct fossilNode* topNode = stack->top;
    stack->top = topNode->next;
    char* name = topNode->name;
    free(topNode);
    return name;
}

// Get the name of the top fossil without removing it from the stack
char* getTopFossil(struct fossilStack* stack) {
    if (isFossilStackEmpty(stack)) {
        printf("Error: Fossil stack is empty.\n");
        return NULL;
    }
    return stack->top->name;
}

// Remove the top fossil from the stack
void removeTopFossil(struct fossilStack* stack) {
    if (isFossilStackEmpty(stack)) {
        printf("Error: Fossil stack is empty.\n");
        return;
    }
    struct fossilNode* topNode = stack->top;
    stack->top = topNode->next;
    free(topNode);
}

int main() {
    // Example usage
    struct fossilStack fossils;
    initFossilStack(&fossils);
    pushFossil(&fossils, "Trilobite");
    pushFossil(&fossils, "Ammonite");
    pushFossil(&fossils, "Dinosaur");
    printf("Fossils: %s, %s, %s\n", popFossil(&fossils), popFossil(&fossils), popFossil(&fossils));
    return 0;
}