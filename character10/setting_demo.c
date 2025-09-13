#include <stdio.h>
#include <stdlib.h>

typedef struct GameSettings {
	float volume;
	int resolution_x;
	int resolution_y;
	int difficulty;
} GameSettings;

void save_game_settings(const GameSettings *settings, const char *filename);
void load_game_settings(GameSettings *settings, const char *filename);

int main() {

	// fread
	// fwrite

	// 读写二进制
	// GameSettings settings = {0.75, 1920, 1080, 2};

	// save_game_settings(&settings, "game_settings.bin");

	// GameSettings loaded_settings;

	// load_game_settings(&loaded_settings, "game_settings.bin");

	// printf("游戏设置加载!\n");
	// printf("Volume: %f\nResolution: %d x %d \nDifficulty: %d\n", loaded_settings.volume,
	// loaded_settings.resolution_x,
	//        loaded_settings.resolution_y, loaded_settings.difficulty);

	return 0;
}

void save_game_settings(const GameSettings *settings, const char *filename) {
	FILE *file;
	file = fopen(filename, "wb");
	if (file == NULL) {
		perror("无法打开文件进行写入操作");
		return;
	}

	fwrite(settings, sizeof(GameSettings), 1, file);
	fclose(file);
}

void load_game_settings(GameSettings *settings, const char *filename) {
	FILE *file;
	file = fopen(filename, "rb");
	if (file == NULL) {
		perror("无法打开文件进行读取操作");
		return;
	}

	fread(settings, sizeof(GameSettings), 1, file);
	fclose(file);
}