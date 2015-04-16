#include <stdio.h>
#include <string.h>
#include <memory.h>


struct node{
    char letter[12];
    int next[26];
};

struct node dictionary[500000];
int alloc = 1;

void insertLetter(char *letter, char *key)
{
    int root = 0, p = 0;
    for(; key[p] != '\0'; ++p)
    {
        if(dictionary[root].next[key[p] - 'a'] == 0)
            dictionary[root].next[key[p] - 'a'] = alloc++;
        root = dictionary[root].next[key[p] - 'a'];
    }
    strcpy(dictionary[root].letter, letter);
}

void translate(char *key)
{
    int root = 0, p = 0;
    for(; key[p] != '\0'; ++p)
    {
        if(dictionary[root].next[key[p] - 'a'] == 0)
        {
            printf("eh\n");
            return;
        }
        root = dictionary[root].next[key[p] - 'a'];
    }
    if(dictionary[root].letter[0] == '\0')
    {
        printf("eh\n");
        return;
    }
    printf("%s\n", dictionary[root].letter);
}

int main()
{
    char letter[12], key[12], c;
    int i;
    memset(dictionary, 0, sizeof(dictionary));
    while(1)
    {
        c = getchar();
        if(c == '\n')
            break;
        for(i = 0; c !=' '; c = getchar(), ++i)
            letter[i] = c;
        letter[i] = '\0';
        for(c = getchar(), i = 0; c != '\n'; c = getchar(), ++i)
            key[i] = c;
        key[i] = '\0';
        insertLetter(letter, key);
    }
    while(scanf("%s", key) != EOF)
    {
        translate(key);
    }
    return 0;
}
