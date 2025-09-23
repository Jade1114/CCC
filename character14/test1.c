#include <stdio.h>
#include <stdlib.h>

/*
    工厂(Factory) : 生产产品，付给一个初始的产品id和产品价格
    批发商(wholesaler) : 从工厂获取产品，可能会更新产品和id和价格
    零售商(Retailer) : 从批发商处获取产品，可能会进一步更新产品的id和价格

    工厂只负责生产产品，并且初始化产品的属性
    批发商和零售商只能接收工厂提供的产品，并且更新它的属性
*/

typedef struct {
	int id;
	float price;
} Product;

Product *create_product(int id, float price);

void update_by_wholesaler(Product *product, int new_id, float new_price);

void update_by_retailer(Product *product, int new_id, float new_price);

int main(void) {

	int a = 10; // 一个普通的int变量

	int *ptr = &a; // 一个指向int变量a的指针

	int **pptr = &ptr; // 一个指向指针ptr的指针

	Product *product1 = create_product(1, 10.0);

	printf("Product1 ID: %d, Price : %.2f\n", product1->id, product1->price);

	Product *product2 = create_product(2, 20.0);

	printf("Product2 ID: %d, Price : %.2f\n", product2->id, product2->price);

	printf("Again ---- Product1 ID: %d, Price : %.2f\n", product1->id, product1->price);

	free(product1);
	free(product2);

	return 0;
}

Product *create_product(int id, float price) {
	Product *product = (Product *)malloc(sizeof(Product));

	if (product == NULL) {
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	product->id = id;
	product->price = price;

	printf("Inside ----ID: %d, Price : %.2f, Address: %p\n", product->id, product->price, (void *)product);

	return product;
}
