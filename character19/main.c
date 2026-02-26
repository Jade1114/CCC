#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

struct item {
    int32_t id;
    char name[MAX_NAME_LENGTH];
    int32_t quantity;
    float price;
};

void print_inventory(const struct item inventory[], int32_t item_count);

int32_t add_item(struct item inventory[], int32_t *item_count, int32_t id,
                 const char *name, int32_t quantity, float price);

int32_t update_quantity(struct item inventory[], int32_t item_count, int32_t id,
                        int32_t new_quantity);

// TODO 修改名字，价格等函数

int32_t main(void) {
    struct item inventory[MAX_ITEMS];

    int32_t item_count = 0;

    add_item(inventory, &item_count, 1, "Laptop", 10, 999.99f);

    add_item(inventory, &item_count, 2, "Mouse", 50, 19.99f);

    add_item(inventory, &item_count, 3, "Keyboard", 30, 49.99f);

    printf("Initial Inventory:\n");
    print_inventory(inventory, item_count);

    update_quantity(inventory, item_count, 2, 45);

    printf("\n Updateed Inventory:\n");
    print_inventory(inventory, item_count);

    return 0;
}

void print_inventory(const struct item inventory[], int32_t item_count) {
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int32_t i = 0; i < item_count; i++) {
        printf("%" PRId32 "\t%-15s\t%" PRId32 "\t\t%.2f\n", inventory[i].id,
               inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int32_t add_item(struct item inventory[], int32_t *item_count, int32_t id,
                 const char *name, int32_t quantity, float price) {
    if (*item_count >= MAX_ITEMS) {
        return 0;
    }

    inventory[*item_count].id = id;
    strlcpy(inventory[*item_count].name, name,
            sizeof(inventory[*item_count].name));
    inventory[*item_count].quantity = quantity;
    inventory[*item_count].price = price;

    (*item_count)++;

    return 1;
}

int32_t update_quantity(struct item inventory[], int32_t item_count, int32_t id,
                        int32_t new_quantity) {
    for (int32_t i = 0; i < item_count; i++) {
        if (inventory[i].id == id) {
            inventory[i].quantity = new_quantity;
            return 1;
        }
    }
    return 0;
}
