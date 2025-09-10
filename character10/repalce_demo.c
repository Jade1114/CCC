#define _GNU_SOURCE
#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int update_log_record_s(const char *filename, const char *search_str, const char *replace_str);

int main(void) {

	const char *log_file = "temp.log";
	const char *search_str = "Memory usage exceeed 80% of available memory.";
	const char *repalce_str = "\n[2023-02-14T12:36:00Z] [INFO] Memory usage is back to normal levels.";

	int result = update_log_record_s(log_file, search_str, repalce_str);

	if (result != 0) {
		char error_msg[256];
		strerror_r(errno, error_msg, sizeof(error_msg));
		fprintf(stderr, "An error occurred: %s\n", error_msg);
	} else {
		printf("Record updated successfully.\n");
	}

	fcloseall();

	return 0;
}

int update_log_record_s(const char *filename, const char *search_str, const char *replace_str) {
	if (filename == NULL || search_str == NULL || replace_str == NULL) {
		return EINVAL; // 返回无效参数错误
	}

	FILE *file_ptr = NULL;

	file_ptr = fopen(filename, "r+");

	if (file_ptr == NULL) {
		char error_msg[256];
		strerror_r(errno, error_msg, sizeof(error_msg));

		fprintf(stderr, "Failed to open config for reading: %s\n", error_msg);
		exit(EXIT_FAILURE);
	}

	char buffer[BUFFER_SIZE];
	long pos = 0;
	int found = 0;

	while (fgets(buffer, BUFFER_SIZE, file_ptr) != NULL) {
		if (strstr(buffer, search_str) != NULL) {
			found = 1;
			pos = ftell(file_ptr) - (long)strlen(buffer) - 1;
			break;
		}
	}

	if (found) {
		fseek(file_ptr, pos, SEEK_SET);

		// 计算替换文本与原文本的长度差异
		size_t replace_len = strlen(replace_str);
		size_t search_len = strlen(search_str);

		if (replace_len > BUFFER_SIZE - 1 || search_len > BUFFER_SIZE - 1) {
			fclose(file_ptr);
			return ERANGE; // 返回错误码，表示字符串长度超出范围
		}

		// 写入新纪录之前，清除所在位置的行数据
		memset(buffer, ' ', strlen(buffer) - 1); // 用空格填充，保持文件大小不变

		buffer[strlen(buffer) - 1] = ' '; // 保留换行符

		fseek(file_ptr, pos, SEEK_SET); // 重新回到标记行的开始

		fputs(buffer, file_ptr); // 清除原来行的内容

		fseek(file_ptr, pos, SEEK_SET);

		int result = fputs(replace_str, file_ptr); // 写入替换的字符串

		if (result == EOF) {
			fclose(file_ptr);
			return errno;
		}
	} else {
		fclose(file_ptr);
		return ENOENT; // 返回未找到的匹配项
	}

	fclose(file_ptr);

	return 0;
}