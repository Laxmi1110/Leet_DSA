#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000   // hash table size

typedef struct {
    int key;
    int value;
    int used;
} HashEntry;

HashEntry hashTable[SIZE];

// hash function
int hash(int key) {
    if(key < 0) key = -key;
    return key % SIZE;
}

// insert into hash table
void insert(int key, int value) {
    int index = hash(key);
    
    while(hashTable[index].used) {
        index = (index + 1) % SIZE;  // linear probing
    }
    
    hashTable[index].key = key;
    hashTable[index].value = value;
    hashTable[index].used = 1;
}

// search in hash table
int search(int key) {
    int index = hash(key);
    
    while(hashTable[index].used) {
        if(hashTable[index].key == key)
            return hashTable[index].value;
        
        index = (index + 1) % SIZE;
    }
    
    return -1;  // not found
}

// LeetCode function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    // initialize hash table
    for(int i = 0; i < SIZE; i++)
        hashTable[i].used = 0;
    
    int* result = (int*)malloc(2 * sizeof(int));
    
    for(int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        int index = search(complement);
        if(index != -1) {
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        
        insert(nums[i], i);
    }
    
    *returnSize = 0;
    return NULL;
}
