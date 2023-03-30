#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define TABLE_SIZE 1579727 // hash table size
int CURRENT_SIZE = 0; // current unique word in the dictionary
// for aesthetic
char table_bar[132] = "+---------------------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+\n";
char delim[22] = " 	\n.,'#[]()\"!?$&*-_;:";

unsigned long djb2_hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++) != 0) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
} // djb2 hash function

void MAKEUP(char* word, int len){
    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }
    if(isalnum(word[0]) != 0 && isalnum(word[len - 1]) != 0){

        return ;
    }
    else{
        word = strtok(word, ".,!?{}[]();:\"''-+=@#$^&*");
    }
} // ?? not efficient

void toLOWER(char* word){
    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }
}

typedef struct _PositionNode{
    int line;
    int page;
    struct _PositionNode* next;
} PositionNode; // help store position of line and page

typedef struct _PositionList{
    PositionNode* first;
    PositionNode* last;
} Position;

typedef struct _DictionaryNode{
    char* word;
    int appearTimes;
    Position* positionList;
    struct _DictionaryNode* next;
} DictionaryNode; // store basic information of a dictionary node

typedef struct _Dictionary{
    DictionaryNode* nodes[TABLE_SIZE];
} Dictionary; // our hash table

void insert_position(DictionaryNode* dictnode, int line, int page){
    PositionNode *new_node = malloc(sizeof(PositionNode));
    new_node->line = line;
    new_node->page = page;
    new_node->next = NULL;

    if(dictnode->positionList->last == NULL){
        dictnode->positionList->first = dictnode->positionList->last = new_node;
    }

    else{
        dictnode->positionList->last->next = new_node;
        dictnode->positionList->last = new_node;
    }
} // insert a position in which the word appear

Dictionary* make_dict(){
    Dictionary* dict = malloc(sizeof(Dictionary));
    for(int i = 0; i < TABLE_SIZE; i++){
        dict->nodes[i] = NULL;
    }
    return dict;
}

void free_dict(Dictionary* dict){
    for(int i = 0; i < TABLE_SIZE; i++){
        DictionaryNode* current = dict->nodes[i];
        while(current != NULL){
            DictionaryNode* next = current->next;
            PositionNode *cur_pos = current->positionList->first;
            while(cur_pos != NULL){
                PositionNode *next_pos = cur_pos->next;
                free(cur_pos);
                cur_pos = next_pos;
            }
            free(current->positionList);
            free(current);
            current = next;
        }
    }
    free(dict);
} // free memory of dictionary

DictionaryNode* lookup(Dictionary* dict, char* word, unsigned long hash) {
    DictionaryNode* current = dict->nodes[hash];
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
} // look up for the word in hash table

void insert_word(Dictionary* ordered_node, Dictionary* dict, char* word, int line, int page) {
    unsigned long hash = djb2_hash(word) % TABLE_SIZE; // get hash key
    DictionaryNode* new_node;

    // look up if the word has already existed in the dictionary
    if((new_node = lookup(dict, word, hash)) != NULL){
        new_node->appearTimes++;
        insert_position(new_node, line, page);
        return ;
    }

    // if the word hasn't been in the dictionary, create a new node for it
    Position *pos = malloc(sizeof(Position));
    pos->first = NULL; pos->last = NULL;
    new_node = malloc(sizeof(DictionaryNode));
    new_node->word = strdup(word);
    new_node->appearTimes = 1;
    new_node->positionList = pos;
    insert_position(new_node, line, page);
    new_node->next = dict->nodes[hash];
    dict->nodes[hash] = new_node;

    ordered_node->nodes[CURRENT_SIZE++] = new_node; // this one help sort the dictionary
}

void sort_dict(Dictionary* ordered_node){  
    for(int i = 0; i < CURRENT_SIZE - 1; i++){
        int min = i;
        for(int j = i + 1; j < CURRENT_SIZE; j++){
            if(strcmp(ordered_node->nodes[min]->word, ordered_node->nodes[j]->word) > 0){
                min = j;
            }
        }
        if(min != i){
            DictionaryNode* temp = ordered_node->nodes[i];
            ordered_node->nodes[i] = ordered_node->nodes[min];
            ordered_node->nodes[min] = temp;
        }
    }
}

void print_dict(Dictionary* ordered_node, FILE* outp){
    fprintf(outp, table_bar);
    for(int i = 0; i < CURRENT_SIZE; i++){
        DictionaryNode* current = ordered_node->nodes[i];
        //COUNTER +=current->appearTimes;  // appearance times of all the words

        // below just print the table to out.txt
        fprintf(outp, "| %-20s| %-10d", current->word, current->appearTimes);
        PositionNode* cur_pos = current->positionList->first;
        int counter = 0;
        while(cur_pos != NULL){
            if(counter == 8){
                counter = 0;
                fprintf(outp, "|\n| %-20c| %-10c", ' ', ' ');
            }
            fprintf(outp, "| %-3d %-6d", cur_pos->line, cur_pos->page);
            counter++;
            cur_pos = cur_pos->next;
        }
        for(int j = counter + 1; j <= 8; j++){
            fprintf(outp, "| %-3c %-6c", ' ', ' ');
        }
        fprintf(outp, "|\n");
        fprintf(outp, table_bar);
    }
}

int main(){
    time_t begin = clock();

    char* infile = "c/text.txt";
    char* outfile = "c/out.txt";
    FILE* inp = fopen(infile, "r");
    FILE* outp = fopen(outfile, "w");
    
    Dictionary* dict = make_dict();
    Dictionary* ordered_node = make_dict();
    int at_order = 1, at_line = 1, at_page = 1;
    int len = 1248; char* line = malloc(len);

    while(fgets(line, len, inp) != NULL){ // check if fgets get sth
        char* token = strtok(line, " \n,."); // split token
        while(token != NULL){
            if(at_order % 15 == 0){
                at_line++;
            }
            if(at_line == 25){
                at_line = 1;
                at_page++;
            }
            toLOWER(token);
            insert_word(ordered_node, dict, token, at_line, at_page);
            token = strtok(NULL, " \n,.");
            at_order++;
        }
    }
    
    sort_dict(ordered_node);
    print_dict(ordered_node, outp);
    
    fclose(inp);
    fclose(outp);
    free_dict(dict);
    free(ordered_node);
    
    time_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("Time Execution: %.6lf s", time_spent);
}