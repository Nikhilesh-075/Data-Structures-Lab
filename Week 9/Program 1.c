#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Function to calculate hash using remainder method
int hashFunction(int key, int m) {
    return key % m;
}

// Function to insert a value using linear probing
void insert(int hashtable[], int key, int m) {
    int i = 0;
    int hkey = hashFunction(key, m);
    int index;

    do {
        index = (hkey + i) % m;
        if (hashtable[index] == -1) {
            // If the slot is empty, insert the key
            hashtable[index] = key;
            printf("Inserted key %d at index %d\n", key, index);
            return;
        }
        i++;
    } while (i < m);

    printf("Unable to insert key %d. Table is full.\n", key);
}

// Function to search a value using linear probing
void search(int hashtable[], int key, int m) {
    int i = 0;
    int hkey = hashFunction(key, m);
    int index;

    do
    {
        index = (hkey + i) % m;
        if (hashtable[index] == key)
        {
            // If the key is found at the calculated index
            printf("Key %d found at index %d\n", key, index);
            return;
        }
        i++;
    }while(i<m);

    printf("Key %d not found in the table.\n", key);
}

int main()
{
    int hashtable[TABLE_SIZE];
    int i;

    // Initialize hashtable with -1 indicating empty slots
    for (i = 0; i < TABLE_SIZE; i++)
    {
        hashtable[i] = -1;
    }

    // Inserting values into the hashtable
    insert(hashtable, 1234, TABLE_SIZE);
    insert(hashtable, 5678, TABLE_SIZE);
    insert(hashtable, 9012, TABLE_SIZE);
    insert(hashtable, 2318, TABLE_SIZE);

    // Searching for values in the hashtable
    search(hashtable, 5678, TABLE_SIZE);
    search(hashtable, 2318, TABLE_SIZE);
    search(hashtable, 9999, TABLE_SIZE); // Not present in the hashtable

    return 0;
}
