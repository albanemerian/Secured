# Secured 
The aim of this project is to make us learn about hash tables

## Key Objectives:

    Develop your own hash function.
    Create your own hash table.

Just like the previous module projects, you'll need to handle a large number of entries in your hash table effectively.
Hash Function

The hash function plays a crucial role in a hash table, determining the table index where data should be stored. <br>
It converts numerical data into a fixed-length string or a positive integer. Hash functions are fundamental in modern cryptography for authenticating transactions, messages, and digital signatures.
Developing Your Hash Function:

Your task is to develop your own hash function, which you'll later use in your hash table implementation.

```c
int hash(char *key, int len);
```
Criteria for a Good Hash Function:

    Deterministic Output: The output string is entirely determined by the hashed data. Constants are allowed but must be justified.
    Utilization of Input Data: All input data should be utilized in hashing.
    Uniform Distribution: Two similar inputs should result in very different output values.
    Even Distribution in Hash Table: The hash function should evenly distribute the data in the hash table.

## Example: Inserting Elements

The ht_insert function is used to insert a new element into the hash table. It's the key parameter that needs to be hashed to find out the index in which to store the value.

```c
int main(void) {
    hashtable_t *ht = new_hashtable(&hash, 4);
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Kratos", "./Trash/Hollidays_Pics/.secret_folder/kratos.ai");
    ht_insert(ht, "<3", "+33 6 31 45 61 23 71");
    ht_dump(ht);
    return 0;
}
```
Output:
```c
[0]:
> 13116 - +33 6 31 45 61 23 71
[1]:
> 1769199557 - ./Documents/Tournament/Modules/Vision
[2]:
> 1952572858 - ./Trash/Hollidays_Pics/.secret_folder/kratos.ai
[3]:
```
## TEST
| Category                         | Percentage | Tests | Crash |
|----------------------------------|------------|-------|-------|
| Algorithm app - Hash function    | 100%       | 4/4   | x     |
| Algorithm app - Hash table       | 100%       | 5/5   | x     |
| Basics                           | 100%       | 6/6   | x     |
| Data structure                   | 100%       | 5/5   | x     |
| Optimization                     | 100%       | 5/5   | x     |
| Robustness                       | 100%       | 10/10 | x     |
| End score                        | 100%       | 35/35 | x     |

Beware of -42 Epitech students !!!
