#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <assert.h>

// Defineste lista simpla inlantuita, dar si nodurile listei / stivei

typedef struct node {
    char card;
    char type;
    int value;
    struct node* next;
} TNode, *TSortedList;

// Defineste stiva

typedef struct Stack{
	TNode* head; 
	long size;
}Stack;

// Creeaza noduri

TSortedList create(int v, char c, char t) {
    TNode* node = (TNode*) malloc(sizeof(TNode));
    node->card = c;
    node->type = t;
    node->value = v;
    node->next = NULL;
    return node;

}

// Creeaza lista 

TSortedList create_list(TSortedList head, int v, char c, char t){
    TNode* node = create(v,c,t);
    if(head == NULL){
        head = node;
        return head;
    }
    TNode* prev = head;
    while(prev->next != NULL) {
        prev = prev->next;
    } 
    prev->next = node;
    return head;
}

// Returneaza al N-lea nod

TSortedList getNth(TSortedList head, int n) {
    TNode* node = head;
    while(n > 1){
        n--;
        node = node->next;
    }
    return node;
}

// Verifica daca exista sau nu nod cu valoarea respectiva

int contains(TSortedList head, char element) {
    TNode* node = head;
    while(node != NULL) {
        if(node->type == element)
        return 1;
        node = node->next;
    }
    return 0;
}

// Sterge nodul cu valoarea respectiva

TSortedList deleteOnce(TSortedList head, char element) {
    
    TNode* node = head;
    if(contains(node, element) == 0) {
        return head;
    }
    else {
        if(head->type == element) {
            head = head->next;
            free(node);
            return head;
        }
        TNode* temp = head->next;
        while(temp != NULL) {
            if(temp->type == element) {
                node->next = temp->next;
                free(temp);
                return head;
            }
            node = temp;
            temp = temp->next;
        }
        
    }
    return NULL;
}

// Insereaza la sfarsitul listei nodul dorit

TSortedList insert_last(TSortedList head, TSortedList node) {
    
    if(head == NULL) {
        head = node;
        return head;
    }
    TNode* iter = head;
    while(iter->next != NULL) {
        iter = iter->next;
    }
    iter->next = node;

    return head;
}

//Insereaza la inceputul listei nodul dorit

TSortedList insert_first(TSortedList head, TSortedList node) {
    node->next = head;
    head = node;

    return head;
}

// Functie de eliberare a memoriei dintr-o lista

TSortedList destroy_list(TSortedList head) {
    TNode* node = head;
    TNode* next = node->next;
    while(next != NULL) {
        free(node);
        node = next;
        next = next->next;
    }
    free(node);
    return NULL;
}

// Creeaza stiva

Stack* createStack(void){
	Stack* s = (Stack*) malloc(sizeof(Stack));
	s->head = NULL;
	s->size = 0;
	return s;
}

// Insereaza la inceputul stivei nodul dorit

void push(Stack *stack, char c, char t, int v){
	TNode* node = (TNode*) malloc(sizeof(TNode));
	node->card =  c;
    node->type = t;
    node->value = v;
	if(stack == NULL) {
		stack->head = node;
		node->next = NULL;
		stack->size = stack->size +1 ;
	}
	else{
		node->next = stack->head;
		stack->head = node;
		stack->size = stack->size +1 ;
	}
	

}

// Elimina primul nod din lista

void pop(Stack *stack){
	TNode* node = stack->head;
	node = node->next;
	free(stack->head);
	stack->size--;
	stack->head = node;
}

// Functie de eliberare a memoriei dintr-o stiva

void destroyStack(Stack *stack){
	TNode* node = stack->head->next;
	while(node != NULL) {
		free(stack->head);
		stack->head = node;
		node = node->next;
	}
	free(stack->head);
	free(stack);
}

// Numara cartile ramase ale jucatorilor

int count_cards(TSortedList head) {
    int x = 0;
    TNode* node = head;
    while(node != NULL) {
        x++;
        node = node->next;
    }
    return x;
}

// Functie ce returneaza valoarea primului nod

int top(Stack* stack) {
    return stack->head->value;
}



#endif
