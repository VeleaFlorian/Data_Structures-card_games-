#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

TSortedList populate_list(int* v, char* c, char* t) {
    TNode* head = NULL;
    for(int  i = 0; i < 13; i++) {
        for(int j = 0; j < 4;j++) {
            head = create_list(head,*(v + i), *(c + i), *(t + j));
        }
    }
    return head;
}

void print_list(TSortedList head, FILE* fout) {
    TNode* node = head;
    while(node->next != NULL) {
        fprintf(fout,"%c%c ", node->card,node->type);
        node = node->next;
    }
    fprintf(fout,"%c%c\n", node->card,node->type);
}

TSortedList invert_list(TSortedList head) {
    TNode* next = head->next;
    TNode* node = head;
    node->next = NULL;
    while(next != NULL) {
        node = next;
        next = next->next;
        node->next = head;
        head = node;
    }
    return head;
}

TSortedList intercalation(TSortedList head) {
    TNode* node1 = head;
    TNode* node2 = getNth(head,27);
    TNode* next1 = head->next;
    TNode* next2 = node2->next;

    while(next2 != NULL) {
        node1->next = node2;
        node2->next = next1;
        node1 = next1;
        node2 = next2;
        next1 = next1->next;
        next2 = next2->next;
    }
    node1->next = node2;
    
    return head;
}
TSortedList Mongean(TSortedList head) {
    TNode* node = head->next;
    head->next = NULL;
    TNode* next = node->next;
    int i = 1;

    while(next != NULL) {
        node->next = NULL;
        if(i%2 == 0) {
            head = insert_last(head,node);
        }
        else {
            head = insert_first(head,node);
        }
        i++;
        node = next;
        next = next->next;    
    }
   
        if(i%2 == 0) {
            head = insert_last(head,node);
        }
        else {
            head = insert_first(head,node);
        }
    return head;
}

TSortedList N_piles(TSortedList head, int n, int* v) {
    TNode** node = (TNode**) malloc(sizeof(TNode)*n); 
    int reminder = 52%n;
    node[0] = head;
    
    for(int i = 1; i < n; i++) {
        if(reminder != 0) {
        node[i] = getNth(node[i-1],(52/n) + 2); 
        reminder--;
        }
        else {
            node[i] = getNth(node[i-1],(52/n) + 1);
        }
        TNode* iter = node[i-1];
        while(iter->next != node[i]){
            iter = iter->next;
        }
        iter->next = NULL;
    }
    for(int i = 0; i < n - 1; i++) {
        TNode* iter = node[v[i] - 1];
       
        while(iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = node[v[i+1] - 1];
    }
    head = node[v[0] - 1];
    node[v[0] - 1] = NULL;
   for(int i = 0; i < n ; i++) {
       node[v[i] - 1] = NULL; 
   }
   free(node);
    return head;
}


char* War(TSortedList head) {
    char c[13] = {'A','K','Q','J','T','9','8','7','6','5','4','3','2'};
   
    char *string = malloc(sizeof(char)*10);
    Stack* s = createStack();
    TNode* player1 = head;
    TNode* node = getNth(head, 26);
    TNode* player2 = node->next;
    node->next = NULL;
    
    for(int  i = 0; i < 100; i++) {
        
        if(player1 == NULL) {
            destroy_list(player2);
            strcpy(string,"2");
            free(s);
            return string;
        }
        else if(player2 == NULL){
            destroy_list(player1);
            strcpy(string,"1");
            free(s);
            return string;
        }
        if(player1->value > player2->value) {
            TNode* node = player1;
            player1 = player1->next;
            node->next = NULL;
            player1 = insert_last(player1,node);
            node = player2;
            player2 = player2->next;
            node->next = NULL;
            player1 = insert_last(player1,node);
        }
        else if( player1->value < player2->value) {
           TNode* node = player2;
            player2 = player2->next;
            node->next = NULL;
            player2 = insert_last(player2,node);
            node = player1;
            player1 = player1->next;
            node->next = NULL;
            player2 = insert_last(player2,node);
        }
        else {
            int nr = player2->value + 1;
            if(nr > count_cards(player2))
                nr = count_cards(player2);
            if(nr > count_cards(player1))
                nr = count_cards(player1);    
            
            TNode* node1 = getNth(player1, nr);
            TNode* node2 = getNth(player2, nr);
            
            if(node1->value > node2->value) {
                for(int j = 0; j < nr; j++) {
                push(s,player2->card,player2->type,player2->value);
                player2 = deleteOnce(player2,player2->type);
                }
                for(int j = 0; j < nr ; j++) {
                push(s,player1->card,player1->type,player1->value);
                player1 = deleteOnce(player1,player1->type);
                }
                
                while(s->head != NULL) {
                TNode* node = create(s->head->value,s->head->card,s->head->type);
                pop(s);
                player1 = insert_last(player1,node);
                }   

            }
            else {
                for(int j = 0; j < nr; j++) {
                push(s,player1->card,player1->type,player1->value);
                player1 = deleteOnce(player1,player1->type);
                }
                for(int j = 0; j < nr; j++) {
                push(s,player2->card,player2->type,player2->value);
                player2 = deleteOnce(player2,player2->type);
                
                }
                while(s->head != NULL) {
                TNode* node = create(s->head->value,s->head->card,s->head->type);
                player2 = insert_last(player2,node);
                pop(s);
                }
            }
        }
        
    }
    free(s);
    int v1[13] = {0};
    int v2[13] = {0};
    int nr1 = count_cards(player1);
    int nr2 = count_cards(player2);
   
    for(int i = 0; i < nr1; i++) {
        if(player1->value > 10)
        v1[player1->value - 3]++;
        else
            v1[player1->value - 2]++;
        player1 = deleteOnce(player1,player1->type);
    }
    
     for(int i = 0; i < nr2; i++) {
        if(player2->value > 10)
        v2[player2->value - 3]++;
        else
            v2[player2->value - 2]++;
        player2 = deleteOnce(player2,player2->type);
    }

     for(int i = 12; i >= 0; i--) {
        if(v1[i] > v2[i]) {
            strcpy(string,"1 ");
            strncat(string,&c[12-i],1);
            return string;
        }
        else if(v1[i] < v2[i]) {
            strcpy(string,"2 ");
            strncat(string,&c[12-i],1);
            return string;
        }

    }
    return "-1";
}

int check_type_card(TSortedList head, int x, char* string) {
    
    if(contains(head,string[x]) == 1)
        return x;
    x++;
    if(x > 3)
        x = 0;
    if(contains(head,string[x]) == 1)
        return x;
    x++;
    if(x > 3)
        x = 0;
    if(contains(head,string[x]) == 1)
        return x;
    x++;
    if(x > 3)
        x = 0;
    if(contains(head,string[x]) == 1)
        return x;
    else 
        return -1;
}

char* Rolling_Stone(TSortedList head) {
    
    TNode** players = (TNode**) malloc(sizeof(TNode)*4);

    players[0] = head;
    TNode* node = getNth(head,13);
    players[1] = node->next;
    node->next = NULL;
    node = getNth(players[1],13);
    players[2] = node->next;
    node->next = NULL;
    node = getNth(players[2],13);
    players[3] = node->next;
    node->next = NULL;

    Stack* s = createStack();

    char v[4] = {'s','h','c','d'};
    char* result = malloc(sizeof(char)*10);
    
    int aux = 0;
    int j = 0;
    
    for(int i = 0; i < 4; i++) {
        
        int check_card = check_type_card(players[aux],i,v);
        
        if(check_card == -1) {
            break;
        }
        i = check_card;
        players[aux] = deleteOnce(players[aux], v[check_card]);
        push(s,'F',v[check_card], 100);
        aux++;
        j = aux;
        while(j <= 4) {
            if(j > 3)
                j = 0;

            if(contains(players[j],v[check_card]) == 1) {
                    players[j] = deleteOnce(players[j], v[check_card]);
                    push(s,'F',v[check_card], 100);
                    if(players[j] == NULL) {
                        for(int k = 0; k < 4; k++) {
                            if(j != k) {
                                destroy_list(players[k]);
                            }
                        }
                        free(players);
                        destroyStack(s);
                        sprintf(result,"%d", j + 1);
                        return result;
                    }         
                }
            else {
                while(s->head != NULL) {
                    
                    TNode* node = create(s->head->value,s->head->card,s->head->type);
                    players[j] = insert_last(players[j],node);
                    pop(s);
                }
                aux = j;
                break;
                }
            j++;
        }
        if( i == 3) 
            i = -1;
    }
    return NULL;
}

char* Scarabei(TSortedList head) {

    TNode** players = (TNode**) malloc(sizeof(TNode)*4);

    players[0] = head;
    TNode* node = getNth(head,13);
    players[1] = node->next;
    node->next = NULL;
    node = getNth(players[1],13);
    players[2] = node->next;
    node->next = NULL;
    node = getNth(players[2],13);
    players[3] = node->next;
    node->next = NULL;
    TNode* prev_player = NULL;

    Stack* s = createStack();
    char* result = malloc(sizeof(char)*10);
    int v[4] = {1,1,1,1};

    int nr_players_out = 0;
    int player_to_play = 0;
    int winner = 0;
    
    int k = 0; //if k == 0 direction + else -

    while(player_to_play < 4) {
        if(players[player_to_play] != NULL) {
            if(nr_players_out == 3) {
                if(s->head != NULL) {
                    destroyStack(s);
                }
                else 
                    free(s);
                for(int j = 0; j < 4; j++) {
                if(players[j] != NULL)
                destroy_list(players[player_to_play]);
                }
                free(players);
                sprintf(result,"%d", player_to_play + 1);
                return result;
            }
            if (s->head == NULL) {
                if(players[player_to_play]->value == 8) {
                    if( k == 0)
                        k = 1;
                    else
                        k = 0;
                }
                push(s,players[player_to_play]->card,players[player_to_play]->type,players[player_to_play]->value);
                players[player_to_play] = deleteOnce(players[player_to_play],players[player_to_play]->type);
                prev_player = players[player_to_play];
            }
            else {
                if(top(s) < 12) {
                if(players[player_to_play]->value == 8) {
                    if( k == 0)
                        k = 1;
                    else
                        k = 0;
                }
                
                push(s,players[player_to_play]->card,players[player_to_play]->type,players[player_to_play]->value);
                players[player_to_play] = deleteOnce(players[player_to_play],players[player_to_play]->type);
                prev_player = players[player_to_play];
                winner = player_to_play;
                
                }
                else if(top(s) >= 12) {
                    if(players[player_to_play]->value < 12 && players[player_to_play]->value != 8) {
                        push(s,players[player_to_play]->card,players[player_to_play]->type,players[player_to_play]->value);
                        players[player_to_play] = deleteOnce(players[player_to_play],players[player_to_play]->type);
                        while(s->head != NULL) {
                            TNode* node = create(s->head->value,s->head->card,s->head->type);
                            prev_player = insert_last(prev_player,node);
                            pop(s);
                        }
                    }
                    else if( players[player_to_play]->value >= 12) {
                        push(s,players[player_to_play]->card,players[player_to_play]->type,players[player_to_play]->value);
                        players[player_to_play] = deleteOnce(players[player_to_play],players[player_to_play]->type);
                        prev_player = players[player_to_play];
                        winner = player_to_play;
                    }
                    else if( players[player_to_play]->value == 8) {
                        if( k == 0) {
                            k = 1;
                        }
                        else
                            k = 0;
                        push(s,players[player_to_play]->card,players[player_to_play]->type,players[player_to_play]->value);
                        players[player_to_play] = deleteOnce(players[player_to_play],players[player_to_play]->type);
                    }
                }
            }
        }
        else if(v[player_to_play] == 1){
            nr_players_out++;
            v[player_to_play] = 0;
        }
        if(k == 0) {
        
            if(player_to_play == 3)
                player_to_play = 0;
            else
                player_to_play++;
        }
        else {
            
            if(player_to_play == 0)
                player_to_play = 3;
            else
                player_to_play--;
        }
        if(s->head == NULL) {
            player_to_play = winner;
        }
    
    }
    return NULL;
}




int main() {
    int v[13] = {15,14,13,12,10,9,8,7,6,5,4,3,2};
    char c[13] = {'A','K','Q','J','T','9','8','7','6','5','4','3','2'};
    char t[4] = {'s','h','c','d'};
    
    TNode* head = populate_list(v,c,t);

    FILE* fint;
    FILE* fout;

    fint = fopen("in","r");
    fout = fopen("out","w");
    
    char task_name[100];
    char shuffle[100];
    int nr_of_shuffles;

    fscanf(fint,"%s",task_name);
    fscanf(fint,"%d",&nr_of_shuffles);
    for(int i = 0; i < nr_of_shuffles; i++) {
            fscanf(fint,"%s",shuffle);
            if(strcmp("inversare", shuffle) == 0) {
                head = invert_list(head);
            }
            if(strcmp("intercalare", shuffle) == 0) {
                head = intercalation(head);
            }
            if(strcmp("mongean", shuffle) == 0) {
                head = Mongean(head);
            }
            if(strcmp("npiles",shuffle) == 0) {
                int piles;
                int clues[100];
                fscanf(fint,"%d", &piles);
                    for(int i = 0; i < piles;i++) {
                        fscanf(fint,"%d", &clues[i]);
                    }
                head = N_piles(head,piles,clues);
            }
    
    }

    
    if(strcmp("amestecare",task_name) == 0) {
        print_list(head, fout);
        destroy_list(head);
    }
    if(strcmp("razboi",task_name) == 0) {
        char* string = War(head);
       fprintf(fout,"%s", string);
        free(string);
    }
    if(strcmp("rollingstone",task_name) == 0) {
       char* string =  Rolling_Stone(head);
       fprintf(fout,"%s", string);
       free(string);
    }
    if(strcmp("scarabei",task_name) == 0) {
        char* string = Scarabei(head);
        fprintf(fout,"%s", string);
        free(string);
    } 
    
    fclose(fint);
    fclose(fout);
    return 0;

}