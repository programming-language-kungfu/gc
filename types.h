/**
 * interpreter has two data types ie an int and a pair,
 * an object in the language of this interpreter can be an int or a pair.
 */

typedef enum {
    OBJ_INT,
    OBJ_PAIR
} ObjectType;

typedef struct sObject {
    unsigned char marked;
    ObjectType type;

    union {
        /* OBJ_INT */
        int value;

        /* OBJ_PAIR */
        struct {
            struct sObject* head;
            struct sObject* tail;
        };
    };
} Object;
