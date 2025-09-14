#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNNINGS
#include <errno.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>

int main(void) {

	double number = 0.0;
	double result = 0.0;

	printf("请输入一个数字以计算其平方根:\n");
	scanf("%lf", &number);

	errno = 0;

	result = sqrt(number);

	// 检查sqrt函数是否出错
	if (errno == EDOM) {
		printf("错误: 输入值为负数，无法计算其平方根!\n");
	} else if (errno == ERANGE) {
		printf("错误： 结果超出范围!\n");
	} else if (errno == HUGE_VAL) {
		printf("错误: 结果超出范围! 返回HUGE_VAL!\n");
	} else {
		printf("数字 %.2f的平方根为: %.2f", number, result);
	}

	return 0;
}