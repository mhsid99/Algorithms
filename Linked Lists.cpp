/*
    1. Floyd's Cycle detection//for finding cycles in Linked lists.
    Time complexity: O(n), as we have traversed the loop once and then traveled X distance. 
    Auxiliary space: O(1), as only pointers are used therefore constant space complexity.

bool detectLoop(Node *head)
{
    Node *slowPointer = head, *fastPointer = head;

    while (slowPointer != NULL && fastPointer != NULL && fastPointer->next != NULL)
    {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer)
            return 1;
    }
    return 0;
}
*/