#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNNINGS
#include <errno.h>
#include <float.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>

int main(void) {

	double group1_max_temp = 35.5;
	double group2_max_temp = 37.2;

	double group1_min_temp = -5.0;
	double group2_min_temp = -3.8;

	double max_temp = fmax(group1_max_temp, group2_max_temp);
	printf("max_temp : %.2f °C\n", max_temp);
	double min_temp = fmin(group1_min_temp, group2_min_temp);
	printf("min_temp: %.2f °C\n", min_temp);

	double temp_diff_max =
	        fdim(group1_max_temp, group2_max_temp); // 注意参数顺序 第一个参数比第二个小的话结果直接为0 而不是差值
	printf("%.2f\n", temp_diff_max);

	double temp_diff_min = fdim(group1_min_temp, group2_min_temp);
	printf("%.2f\n", temp_diff_min);
	return 0;
}