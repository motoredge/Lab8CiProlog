#include "ciProlog.h"

// the knowledge base
// a linked list of propositions
// if a proposition is on the list, it is assumed to be true
// anything not on the list is false
// the first element is empty; it is used as an anchor for kb_head and kb_tail
// we always add at kb_tail
// we always search from kb_head->next;

PROP_TYPE *kb_head, *kb_tail;

void initKnowledgeBase(void)
{
    kb_head = kb_tail = (PROP_TYPE *) malloc(sizeof(PROP_TYPE)); // always empty head of the list
    kb_head->name = ""; // indicates the empty head; skip in searches
    kb_head->next = NULL;
}

void yyerror(char *s)
{
    fprintf(stderr, "yyerror: %s\n", s);
}

// returns negation of input
bool not(bool logexpr1)
{
    // TODO implement the function
    return !logexpr1;

    return false;
}

// logical and...
bool and(bool logexpr1, bool logexpr2)
{
    // TODO implement the function
    return (logexpr1 && logexpr2);
    return false;
}

// logical or...
bool or(bool logexpr1, bool logexpr2)
{
    // TODO implement the function
    return (logexpr1 || logexpr2);

    return false;
}

// Check if the proposition is in the database.
// If it is already there, return false.
// If it is not already there, add it to the database and return true.
bool assert(char *proposition)
{
    // TODO implement the function
    if(eval(*proposition)== true)
    {
        return false;
    }
    else{
        if(kb_tail == NULL)
        {
            kb_head = kb_tail = (PROP_TYPE* ) malloc(sizeof(PROP_TYPE));
            (*kb_head).name = proposition;
            (*kb_head).next = NULL;
        }
        else{
            kb_tail->next = (PROP_TYPE*) malloc(sizeof(PROP_TYPE));
            kb_tail = kb_tail->next;
            kb_tail->name = proposition;
            kb_tail->next = NULL;
        }
        return true;
    }
}

// Search the database for the proposition.
// If it is in the database, remove it from the database and return true.
// If it is not in the database, return false.
bool retract(char *proposition)
{
    // TODO implement the function
    if(eval(*proposition))
    {
        PROP_TYPE *currNode = kb_head;
        PROP_TYPE *nextNode = NULL;
        do{
            nextNode = currNode->next;
            if (currNode->name == NULL)
                free(currNode->name);

            free(currNode);
            currNode = nextNode;
        }while(currNode != NULL);

        kb_head = NULL;
        kb_tail = NULL;
    }
    else{
        return false;
    }
}

// Find the proposition in the knowledge base.
// If found, return true.
// Otherwise, return false.
bool eval(char *proposition)
{
    // TODO implement the function
    PROP_TYPE *currNode = kb_head
    return false;
};
