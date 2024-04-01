#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR 256
#define MAX_TREE_HT 100

/*______________________________________________________________________________________________________________

   File: huffman.c
   Author: Aleksei Strunin

   Description:
   This C program implements the Huffman coding algorithm for lossless data compression. It includes functions for
   encoding a file using Huffman coding and creating a binary Huffman tree.

   Functions:
   - int encodeFile(EncoderState *state, char *input_file, char *output_file);
      Encodes the input file using Huffman coding and writes the compressed data to the output file.

   - struct MinHeapNode *extractMin(struct MinHeap *minHeap);
      Extracts the node with the minimum frequency from the MinHeap.

   - struct MinHeapNode *newNode(char data, unsigned freq);
      Creates a new MinHeapNode with the given data and frequency.

   - struct MinHeap *createMinHeap(unsigned capacity);
      Creates a MinHeap with the specified capacity.

   - void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode);
      Inserts a MinHeapNode into the MinHeap.

   - void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b);
      Swaps two MinHeapNode pointers.

   - void minHeapify(struct MinHeap *minHeap, unsigned idx);
      Maintains the MinHeap property starting from the given index.

   - int isSizeOne(struct MinHeap *minHeap);
      Checks if the MinHeap has only one node.

   - struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size);
      Creates and builds a MinHeap based on the input data and frequencies.

   - struct HuffmanResult buildHuffmanTree(char data[], int freq[], int size);
      Builds the Huffman tree using the provided data and frequencies.

   - void buildHashTable(EncoderState *state, struct MinHeapNode *root, int arr[], int top);
      Builds a hash table for efficient lookup of Huffman codes.

   - unsigned int hashFunction(char c);
      Hash function for indexing the hash table.

   - char* getHuffmanCode(EncoderState *state, char c);
      Retrieves the Huffman code for a given character.

   - HashTable *createHashTable();
      Creates an empty hash table.

   - void insertHashTable(HashTable *ht, char c, char *code);
      Inserts a key-value pair into the hash table.

   - char *lookup(HashTable *ht, char c);
      Looks up the value associated with the given key in the hash table.

   - void freeMinHeap(struct MinHeap *minHeap);
      Frees the memory allocated for the MinHeap.

   - void freeHuffmanTree(struct MinHeapNode *root, struct MinHeap *minHeap);
      Frees the memory allocated for the Huffman tree and the MinHeap.

   - void freeNode(Node *node);
      Frees the memory allocated for a linked list node.

   - void destroyHashTable(HashTable *ht);
      Frees the memory allocated for the hash table.

   - void print_usage();
      Prints the program usage information.

   Global Constants:
   - #define MAX_CHAR 256: Maximum number of distinct characters (ASCII values).
   - #define MAX_TREE_HT 100: Maximum height of the Huffman tree.

   Global Types:
   - struct MinHeapNode: Represents a node in the MinHeap.
   - struct MinHeap: Represents the MinHeap data structure.
   - struct Node: Represents a linked list node for hash table collision resolution.
   - struct HashTable: Represents a hash table for efficient storage of Huffman codes.
   - struct HuffmanResult: Represents the result of the Huffman tree construction.

   Additional Notes:
   - The program supports encoding of input files using the Huffman coding algorithm.
   - It utilizes a MinHeap to efficiently construct the Huffman tree.
   - The resulting Huffman tree is used to generate Huffman codes for each character.
   - The encoded data is written to an output file.
   - The program allows customization of input and output file paths through command-line arguments.
   
   Instructions:
   ./yourExecutable -i completeShakespeare.txt -o yourExec.out

________________________________________________________________________________________________________________*/ 
struct MinHeapNode{
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};
typedef struct Node {
    char character;
    char* code;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node* table[MAX_CHAR];
} HashTable;

struct HuffmanResult {
    struct MinHeapNode *root;
    struct MinHeap *minHeap;
};

typedef struct {
    HashTable *ht;
} EncoderState;

int encodeFile(EncoderState *state, char *input_file, char *output_file);
struct MinHeapNode *extractMin(struct MinHeap *minHeap);
struct MinHeapNode *newNode(char data, unsigned freq);
struct MinHeap *createMinHeap(unsigned capacity);

void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode);
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b);
void minHeapify(struct MinHeap *minHeap, unsigned idx);
void buildMinHeap(struct MinHeap *minHeap);
int isSizeOne(struct MinHeap *minHeap);
int isLeaf(struct MinHeapNode *root);

struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size);
struct HuffmanResult buildHuffmanTree(char data[], int freq[], int size);
void buildHashTable(EncoderState *state, struct MinHeapNode *root, int arr[], int top);

unsigned int hashFunction(char c);
char* getHuffmanCode(EncoderState *state, char c);
HashTable *createHashTable();
void insertHashTable(HashTable *ht, char c, char *code);
char *lookup(HashTable *ht, char c);

void freeMinHeap(struct MinHeap *minHeap);
void freeHuffmanTree(struct MinHeapNode *root, struct MinHeap *minHeap);
void freeNode(Node *node);
void destroyHashTable(HashTable *ht);



int main(int argc, char *argv[])
{
    EncoderState state;
    state.ht = NULL;

    int opt;
    char input_file[100] = "completeShakespeare.txt";
    char output_file[100] = "huffman.out";

    for (opt = 1; opt < argc; opt++)
    {
        if (strcmp(argv[opt], "-i") == 0)
        {
            strncpy(input_file, argv[opt + 1], sizeof(input_file) - 1);
            opt++;
        }
        else if (strcmp(argv[opt], "-o") == 0)
        {
            strncpy(output_file, argv[opt + 1], sizeof(output_file) - 1);
            opt++;
        }
        else
        {
            print_usage();
            return 1;
        }
    }

    encodeFile(&state, input_file, output_file);

    return 0;
}



int encodeFile(EncoderState *state, char *input, char *output)
{
    int dataSize = 0;
    int freq[MAX_CHAR] = {0};
    char data[MAX_CHAR];

    FILE *inFile = fopen(input, "r");
    if (!inFile)
    {
        perror("Failed to open input file");
        return 1;
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF)
    {
        if (freq[(int)ch] == 0)
        {
            data[dataSize++] = ch;
        }
        freq[(int)ch]++;
    }

    int finalFreq[dataSize];
    for (int i = 0; i < dataSize; i++)
    {
        finalFreq[i] = freq[(int)data[i]];
    }

    struct HuffmanResult huffmanResult = buildHuffmanTree(data, finalFreq, dataSize);

    int ar[MAX_TREE_HT], tp = 0;
    state->ht = createHashTable();
    buildHashTable(state, huffmanResult.root, ar, tp);

    FILE *outFile = fopen(output, "wb");
    if (!outFile)
    {
        perror("Failed to open output file");
        return 1;
    }

    int bit_position = 0;
    unsigned char byte = 0;

    fseek(inFile, 0L, SEEK_SET);

    ch = 0;
    while ((ch = fgetc(inFile)) != EOF)
    {
        const char *code = getHuffmanCode(state, ch);

        if (code == NULL)
        {
            printf("Error: Huffman code for character %c not found\n", ch);
            return 1;
        }

        while (*code)
        {
            byte <<= 1;

            if (*code == '1')
            {
                byte |= 1;
            }

            bit_position++;

            if (bit_position == 8)
            {
                fwrite(&byte, 1, 1, outFile);
                bit_position = 0;
                byte = 0;
            }
            code++;
        }
    }

    if (bit_position > 0)
    {
        byte <<= (8 - bit_position);
        fwrite(&byte, 1, 1, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    freeHuffmanTree(huffmanResult.root, huffmanResult.minHeap);
    destroyHashTable(state->ht);

    return 0;
}

struct MinHeapNode *newNode(char data, unsigned freq) {
    struct MinHeapNode *temp = malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct MinHeap *createMinHeap(unsigned capacity) {
    struct MinHeap *minHeap = malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *minHeap, unsigned idx) {
    unsigned smallest = idx, left = 2 * idx + 1, right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap *minHeap) {
    return minHeap->size == 1;
}

struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[--minHeap->size];
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
    minHeap->array[minHeap->size++] = minHeapNode;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void buildMinHeap(struct MinHeap *minHeap) {
    for (int i = (minHeap->size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

int isLeaf(struct MinHeapNode *root) {
    return !(root->left) && !(root->right);
}

struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct HuffmanResult buildHuffmanTree(char data[], int freq[], int size) {
    struct HuffmanResult result;
    struct MinHeapNode *left, *right, *top;
    result.minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(result.minHeap)) {
        left = extractMin(result.minHeap);
        right = extractMin(result.minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(result.minHeap, top);
    }

    result.root = extractMin(result.minHeap);
    return result;
}

void buildHashTable(EncoderState *state, struct MinHeapNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 1;
        buildHashTable(state, root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 0;
        buildHashTable(state, root->right, arr, top + 1);
    }

    if (isLeaf(root)) {
        char *code = malloc(top + 1);
        for (int i = 0; i < top; ++i)
            code[i] = arr[i] + '0';
        code[top] = '\0';
        insertHashTable(state->ht, root->data, code);
    }
}

unsigned int hashFunction(char c)
{
    return (unsigned int)c % MAX_CHAR;
}

char *getHuffmanCode(EncoderState *state, char c)
{
    return lookup(state->ht, c);
}

HashTable* createHashTable() {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < MAX_CHAR; i++) {
        ht->table[i] = NULL;
    }
    return ht;
}

void insertHashTable(HashTable* ht, char c, char* code) {
    unsigned int index = hashFunction(c);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = c;
    newNode->code = code;
    newNode->next = NULL;
    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        Node* temp = ht->table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

char* lookup(HashTable* ht, char c) {
    unsigned int index = hashFunction(c);
    Node* temp = ht->table[index];
    while (temp != NULL) {
        if (temp->character == c) {
            return temp->code;
        }
        temp = temp->next;
    }
    return NULL;
}

void freeMinHeap(struct MinHeap *minHeap)
{
    if (minHeap == NULL)
    {
        return;
    }
    free(minHeap->array);
    free(minHeap);
}

void freeHuffmanTree(struct MinHeapNode *root, struct MinHeap *minHeap)
{
    if (root == NULL)
    {
        return;
    }

    freeHuffmanTree(root->left, NULL);
    freeHuffmanTree(root->right, NULL);
    free(root);
    freeMinHeap(minHeap);
}

void freeNode(Node* node) {
    if (node == NULL) {
        return;
    }
    freeNode(node->next);
    free(node);
}

void destroyHashTable(HashTable* ht) {
    for (int i = 0; i < MAX_CHAR; i++)
    {
        Node *temp = ht->table[i];
        while (temp != NULL)
        {
            Node *next = temp->next;
            free(temp->code);
            free(temp);
            temp = next;
        }
    }
    free(ht);
}
