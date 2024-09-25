#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

//global variable
struct Node* head;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

//i need open, switch, close
//open is insert at head linked list
//close is delete node with val in linked list
//switch is make node with val the head node

void insertAtHead(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    return;
}

void deleteAtVal (int val) {
    //Node* temp = (Node*)malloc(sizeof(Node));
    Node* curr = head;
    Node* next_node = curr->next;

    if (curr->data == val) //if the val is the 1st node just set the 2nd node as the head and free 1st node
    {
        if (next_node == NULL)
        {
            head = NULL;
            free(curr);
            return;
        }
        head = next_node;
        free(curr);
        return;
    }

    else 
    {   
        if (next_node->data == val) 
        {
            curr->next = next_node->next;
            free(next_node);
            return;
        }

        while (next_node->data != val) 
        { //traverses through stops when its equal to val
            curr = curr->next;
            next_node = next_node->next;

            if (next_node == NULL)
            {
                head = NULL;
                free(curr);
                return;
            }

            if (next_node->data == val) 
            {
                curr->next = next_node->next;
                free(next_node);
                return;
            }
        }

    }    
}

void switchToHead(int val) {

    
    if (head == NULL)
    {
        //printf("list is empty\n");
        return;
    }

    Node* curr = head;
    Node* curr_next = curr->next;

    if (curr->data == val || curr_next == NULL) 
    {
        //printf("nothing to switch\n");
        return;
    }

    if (curr_next->data == val) {
        curr->next = curr_next->next;
        curr_next->next = head;
        head = curr_next;
        return;
    }

    while (curr != NULL && curr_next->data != val)
    {
        curr = curr->next;
        curr_next = curr_next->next;
        if (curr_next->data == val)
        {
            curr->next = curr_next->next; //1->2->3->NULL, switch 3,     3-> 1 -> 2 -> NULL
            curr_next->next = head; 
            head = curr_next;

            return;
        }
    }

    // if (head == NULL) 
    // {
    //     printf("list is empty\n");
    //     return;
    // }

    // Node* curr = head;
    // Node* curr_next = curr->next;


    // Node* head_track = head;//extra pointer tracking original head node

    // if (curr->data == val) //means val is already at head
    // {
    //     printf("\nalready at head, nothing to switch\n");
    //     return;
    // }

    // else 
    // {
    //     while (curr != NULL && curr_next->data != val)
    //     {
    //         curr = curr->next;
    //         curr_next = curr_next->next;
    //         if (curr_next->data == val)
    //         {   
    //             curr->next = head_track;
    //             head_track->next = curr_next->next;
    //             curr_next->next = curr;
    //             return;
    //         }
    //     }

    // }

}

void printHead() {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// int repeatInt(int val) {
//     Node* temp = head;
//     while (temp != NULL) {
//         if (temp->data == val) {
//             printf("val is already here\n");
//             return 0;
//         }
//         temp = temp->next;

//     }
//     return 1;
// }
//i need another fucntion to determine when there is nothing in list so i can escape main func

int main()
{    
    head = NULL; //empty list
    //printf("put in command prompt: ");

    //for now lets say o = open, c = close, and s = switch
    char input[7]; //string array, size 6 for switch
    int val;
    
    while (1)
    {
        // printf("\nEnter command (open, close, switch) and value: ");
        scanf("%s %d", input, &val);
        //printf("string %s\n", input);
        //printf("number %d\n", val);

        if (strcmp(input, "open") == 0) 
        {   
            //if (repeatInt(val) == 1) {
            insertAtHead(val);
            // printf("%d\n", head->data);
            //}
        }   
        else if (strcmp(input, "close") == 0)
        {
            //if (repeatInt(val) == 1) {
            deleteAtVal(val);
            // printf("%d\n", head->data);
            //}
        }
        else if (strcmp(input, "switch") == 0 )
        {
            //if (repeatInt(val) == 1) {
            switchToHead(val);
            // printf("%d\n", head->data);
            //}
        } 
        else 
        {
            // printf("unknown command\n");
        }


        if (head != NULL) {
            //printHead();
            printf("%d\n", head->data);
        }
        else {
            printf("\n");
        }

        //printHead();

        if (head == NULL)
        {
            // printf("\nlist is empty \n");
            break;
        }
    }
    return 0;
}