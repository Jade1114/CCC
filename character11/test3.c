#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNNINGS
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>

void check_float(double number);

int mian(void) {

	double numbers[] = {0.0, 1.0, -1.0, 1.0 / 0.0, -1.0 / 0.0, 0.0 / 0.0, DBL_MIN / 2.0};

	int size = sizeof(numbers) / sizeof(numbers[0]);

	for (size_t i = 0; i < size; i++) {
		check_float(numbers[i]);
	}
	return 0;
}

void check_float(double number) {

	// 检查浮点数的分类

	switch (fpclassify(number)) {
	case FP_INFINITE:
		printf("无穷大");
		break;
	case FP_NAN:
		printf("NaN");
		break;
	case FP_NORMAL:
		printf("z正常值");
		break;
	case FP_SUBNORMAL:
		printf("次正规数");
		break;
	case FP_ZERO:
		printf("零");
		break;
	}

	if (isfinite(number)) printf("有限的");
	if (isinf(number)) printf("无穷大");
	if (isnan(number)) printf("NaN");
	if (isnormal(number)) printf("正常数");
	if (signbit(number))
		printf("有限的");
	else
		printf("符号位是正或零");
}