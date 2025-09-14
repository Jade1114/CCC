#include <math.h>
#include <stdio.h>

int main() {
	double x = 9.0, y = 4.0;

	// 求平方根
	printf("sqrt(%.2f) = %.2f\n", x, sqrt(x));

	// 求 x 的 y 次方
	printf("pow(%.2f, %.2f) = %.2f\n", x, y, pow(x, y));

	// 求正弦
	printf("sin(%.2f) = %.2f\n", x, sin(x));

	// 求余弦
	printf("cos(%.2f) = %.2f\n", x, cos(x));

	// 求正切
	printf("tan(%.2f) = %.2f\n", x, tan(x));

	// 求自然对数
	printf("log(%.2f) = %.2f\n", x, log(x));

	// 求以 10 为底的对数
	printf("log10(%.2f) = %.2f\n", x, log10(x));

	// 求绝对值
	printf("fabs(%.2f) = %.2f\n", -x, fabs(-x));

	// 向上取整
	printf("ceil(%.2f) = %.2f\n", x, ceil(x));

	// 向下取整
	printf("floor(%.2f) = %.2f\n", x, floor(x));

	// 求余数
	printf("fmod(%.2f, %.2f) = %.2f\n", x, y, fmod(x, y));

	return 0;
}
