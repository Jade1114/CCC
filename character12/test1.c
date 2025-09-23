#include <inttypes.h>
#include <stdio.h>
#include <time.h>

int main(void) {
	// 获取当前的时间戳
	time_t now = time(NULL);

	struct tm local_time;
	struct tm utc_time;

	// 正确的调用方式
	localtime_r(&now, &local_time);
	gmtime_r(&now, &utc_time);

	char local_time_str[80];
	char utc_time_str[80];
	strftime(local_time_str, sizeof(local_time_str), "%Y-%m-%d %H:%M:%S", &local_time);
	strftime(utc_time_str, sizeof(utc_time_str), "%Y-%m-%d %H:%M:%S", &utc_time);

	// 输出
	printf("当前时间戳: %" PRIdMAX "\n", (intmax_t)now);
	printf("本地时间: %s\n", local_time_str);
	printf("UTC 时间: %s\n", utc_time_str);

	return 0;
}