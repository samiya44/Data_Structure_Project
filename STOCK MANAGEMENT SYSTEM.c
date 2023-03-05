#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct stock
{
    int stockno;
    char name[100];
    char quantity[100];
    float price;
    struct stock *next;

}* head;

//binary search
struct stock* middle(struct stock* start,struct stock* last)
{
    if (start == NULL)
        return NULL;

    struct stock* slow = start;
    struct stock* fast = start -> next;

    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    return slow;
}
 struct stock* binarySearch(struct stock *head, int stockno)
{
    struct stock* start = head;
    struct stock* last = NULL;

    do
    {
        struct stock* mid = middle(start, last);

        if (mid == NULL)
            return NULL;

        if (mid -> stockno == stockno)
            return mid;

        else if (mid -> stockno < stockno)
            start = mid -> next;

        else
            last = mid;

    } while (last == NULL ||
             last != start);

    return NULL;
}


//.............
void insert(int stockno, char* name, char* quantity, float price)
{
struct stock * stock = (struct stock *) malloc(sizeof(struct stock));
    stock->stockno = stockno;
    strcpy(stock->name, name);
    strcpy(stock->quantity, quantity);
    stock->price = price;
    stock->next = NULL;

    if(head==NULL){
        // if head is NULL
        // set stock as the new head
        head = stock;

 }
    else{
        // if list is not empty
        // insert stock in beginning of head
        stock->next = head;
        head = stock;
    }

}
void search(int stockno)
{
    struct stock * temp = head;

        if(binarySearch(head,stockno)==NULL)
		{
			printf("Data not found");
		}
		else
		{
            printf("Stock Number: %d\n", temp->stockno);
            printf("Name: %s\n", temp->name);
            printf("quantity: %s\n", temp->quantity);
            printf("price: %0.4f\n", temp->price);
            return;
        }

}
void update(int stockno)
{

    struct stock * temp = head;
    while(temp!=NULL){
if(temp->stockno==stockno){
            printf("Record with stock number %d Found !!!\n", stockno);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new quantity number: ");
            scanf("%s", temp->quantity);
            printf("Enter new price: ");
            scanf("%f",&temp->price);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;

    }
    printf("stock with stock number %d is not found !!!\n", stockno);
}
void Delete(int stockno)
{
    struct stock * temp1 = head;
    struct stock * temp2 = head;
while(temp1!=NULL){

        if(temp1->stockno==stockno){

            printf("Record with stock number %d Found !!!\n", stockno);

            if(temp1==temp2){
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
}

            printf("Record Successfully Deleted !!!\n");
            return;

 }
        temp2 = temp1;
        temp1 = temp1->next;

    }
    printf("stock with stock number %d is not found !!!\n", stockno);

}
void display()
{
    struct stock * temp = head;
    while(temp!=NULL){

        printf("Stock Number: %d\n", temp->stockno);
        printf("Name: %s\n", temp->name);
        printf("quantity: %s\n", temp->quantity);
        printf("price: %0.4f\n\n", temp->price);
        temp = temp->next;

    }
}
void sort()
{
    struct stock *curNode,*nextNode;
    curNode = head;
    while(curNode!=0)
    {
        nextNode = curNode->next;

        while(nextNode!=0)
        {
            if(curNode->stockno>nextNode->stockno)
            {
                swap1(&curNode->stockno, &nextNode->stockno);
                swap2(curNode->name, nextNode->name);
                swap2(curNode->quantity, nextNode->quantity);
                swap3(&curNode->price, &nextNode->price);
            }
            nextNode = nextNode->next;
        }
        curNode = curNode->next;
    }
    printf("\nRecord is Now Sorted\n");
}


void swap1( int *a, int *b)
{
    int temp;
    temp  = *a;
    *a = *b;
    *b = temp;
}


void swap3(float *x, float *y)
{
    float temp;
    temp  = *x;
    *x = *y;
    *y = temp;
}


void swap2(char *str1, char *str2)
{
    char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    free(temp);
}

int main()
{
    head = NULL;
    int choice;
    char name[100];
    char quantity[100];
    int stockno;
    float price;
    printf("1 to insert stock details\n2 to search for stock details\n3 to delete stock details\n4 to update stock details\n5 to display all stock details");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter stock number: ");
                scanf("%d", &stockno);
                printf("Enter name: ");
                scanf("%s", name);
printf("Enter quantity number: ");
                scanf("%s", quantity);
 printf("Enter price: ");
                scanf("%f", &price);
                insert(stockno, name, quantity, price);
                break;

            case 2:
                printf("Enter stock number to search: ");
                scanf("%d", &stockno);
                search(stockno);
                break;

            case 3:
                printf("Enter stock number to delete: ");
                scanf("%d", &stockno);
                Delete(stockno);
                break;

case 4:
                printf("Enter stock number to update: ");
                scanf("%d", &stockno);
                update(stockno);
                break;
 case 5:
                display();
                break;
        }

    } while (choice != 0);
}


