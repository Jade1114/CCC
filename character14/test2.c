#include <stdio.h>
#include <stdlib.h>

/*
	工厂(Factory) : 生产产品，付给一个初始的产品id和产品价格
	批发商(wholesaler) : 从工厂获取产品，可能会更新产品和id和价格
	零售商(Retailer) : 从批发商处获取产品，可能会进一步更新产品的id和价格

	工厂只负责生产产品，并且初始化产品的属性
	批发商和零售商只能接收工厂提供的产品，并且更新它的属性
*/

typedef struct
{
	int id;
	float price;
	const char *manufacturer;
} Product;

Product *create_product(int id, float price, const char *manufacturer);

const char *get_manufacturer(Product **product_ptrs);

int main(void)
{

	Product *product = create_product(1, 10.0, "hszx factory");

	printf("Product ID: %d, Price : %.2f, Manufacturer : %s\n", product->id, product->price, product->manufacturer);

	// 批发商从工厂获取产品
	Product *wholesaler_product = product;

	// 零售商获取产品,并且联系工厂
	Product **retailer_prooduct = &wholesaler_product;

	// 解引 *
	printf("Retailer --- Product ID: %d, Price : %.2f, Manuefacturer : %s\n", (*retailer_prooduct)->id,
		   (*retailer_prooduct)->price, (*retailer_prooduct)->manufacturer);

	const char *manufacturer_info = get_manufacturer(retailer_prooduct);

	printf("Retailer contacted factory through wholesaler: Manufacturer : %s\n\n", manufacturer_info);

	free(product);

	return 0;
}

Product *create_product(int id, float price, const char *manufacturer)
{
	Product *product = (Product *)malloc(sizeof(Product));

	if (product == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	product->id = id;
	product->price = price;
	product->manufacturer = manufacturer;

	return product;
}

const char *get_manufacturer(Product **product_ptrs)
{
	return (*product_ptrs)->manufacturer;
	// return (**product_ptrs).manufacturer;
}