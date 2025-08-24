#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double price;
    int quantity;
} item;

typedef struct {
    item *cart_items;
    int count;
    int total_capacity;
} cart;

void initialize(cart *c)
{
    printf("Enter initial cart capacity: ");
    scanf("%d", &c -> total_capacity);

    c -> cart_items = (item *)malloc((c -> total_capacity) * sizeof(item));

    c -> count = 0;
}

cart addItemsToCart(cart c)
{
    char name[100];
    int index;
    int flag = 0;

    index = c.count;

    if (c.count == c.total_capacity)
    {
        flag = 1;
        c.total_capacity *= 2;

        c.cart_items = (item *)realloc(c.cart_items, c.total_capacity * sizeof(item));
    }

    printf("Enter item name: ");
    scanf("%s", name);
    c.cart_items[index].name = (char *)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(c.cart_items[index].name, name);

    printf("Enter price: ");
    scanf("%lf", &c.cart_items[index].price);
    printf("Enter quantity: ");
    scanf("%d", &c.cart_items[index].quantity);

    if (flag)
    {
        printf("Array resized to capacity: %d\n", c.total_capacity);

        flag = 0;
    }

    printf("Item added.\n");
    c.count++;

    return c;
}

int searchItem(cart c)
{
    int i;
    char search_name[100];
    int found = 0;

    printf("Enter the name that you search: ");
    scanf("%s", search_name);

    for (i = 0; i < c.count; i++)
    {
        if (strcmp(c.cart_items[i].name, search_name) == 0)
        {
            found = 1;

            return i;
        }
    }

    if (!found)
    {
        printf("Item not found.\n");

        return -1;
    }
}

cart removeItem(cart c)
{
    int i;
    char remove_name[100];
    int found = 0;
    int index;

    printf("Enter item name to remove: ");
    scanf("%s", remove_name);

    for (i = 0; i < c.count; i++)
    {
        if (strcmp(c.cart_items[i].name, remove_name) == 0)
        {
            found = 1;
            index = i;

            break;
        }
    }

    if (found)
    {
        free(c.cart_items[index].name);

        for (i = index; i < c.count - 1; i++)
        {
            c.cart_items[i] = c.cart_items[i + 1];
        }
    
        c.count--;

        printf("Item removed.\n");
    }

    else
    {
        printf("Item not found.\n");
    }


    if (c.count < (c.total_capacity / 2))
    {
        c.total_capacity = c.count;

        c.cart_items = (item *)realloc(c.cart_items, c.total_capacity * sizeof(item));
    }

    return c;
}

void printCart(cart c)
{
    int i;
    double sum = 0;

    printf("---------------------------------------------------\n");
    printf("Name       Price      Quantity        Subtotal\n");
    printf("---------------------------------------------------\n");
    for (i = 0; i < c.count; i++)
    {
        printf("%-6s %8.2f %10d %18.2f\n", c.cart_items[i].name, c.cart_items[i].price, 
                c.cart_items[i].quantity, c.cart_items[i].price * c.cart_items[i].quantity);

        sum += c.cart_items[i].price * c.cart_items[i].quantity;
    }
    printf("---------------------------------------------------\n");
    printf("Total cart value: %.2f\n", sum);
}

void freeCart(cart c)
{
    int i;

    for (i = 0; i < c.count; i++)
    {
        free(c.cart_items[i].name);
    }
    free(c.cart_items);
}

int main()
{
    cart c;
    int flag = 0;
    int choice;
    int index;

    initialize(&c);

    printf("\n1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. Search Item\n");
    printf("4. Print Cart\n");
    printf("5. Exit\n");

    while (!flag)
    {
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                c = addItemsToCart(c);
                break;

            case 2:
                c = removeItem(c);
                break;

            case 3:
                index = searchItem(c);
                if (index != -1)
                {
                    printf("Name: %s\n", c.cart_items[index].name);
                    printf("Price: %.2f\n", c.cart_items[index].price);
                    printf("Quantity: %d\n", c.cart_items[index].quantity);
                }
                break;

            case 4:
                printCart(c);
                break;

            case 5:
                flag = 1;
                printf("Freeing memory... Goodbye!\n");
                freeCart(c);
                return 1;

            default:
                printf("Invalid value. Enter 1, 2, 3, 4 or 5.\n");
        }
    }

    return 0;
}
