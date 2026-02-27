#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// 事件系统
// 监听器
// 触发器

#define EXP_PER_LEVEL 100  // 每个等级需要的经验值
#define MAX_LEVEL 10       // 最高级假设是10
#define MAX_HINTS_COUNT 10 // 宝藏提示的数量
#define MAX_LISTENERS 10   //

typedef struct {
    int32_t exp;
    int32_t level;
} Player;

typedef struct {
    int level;
    const char *mapName;
} MapUnlock;

typedef void (*LevelUpListener)(Player *);

typedef struct {
    LevelUpListener listeners[MAX_LISTENERS];
    int listenerCount;
} EventSystem;

EventSystem eventSystem = {0};
// 可以增加例如，地图等事件监听器

// 用于注册新的监听器
void addLevelUpListener(LevelUpListener listener) {
    if (eventSystem.listenerCount < MAX_LISTENERS) {
        eventSystem.listeners[eventSystem.listenerCount++] = listener;
    }
}

// 用于在玩家升级时所触发的所有注册的监听器
void triggerLevelUpEvent(Player *player) {
    for (int i = 0; i < eventSystem.listenerCount; i++) {
        eventSystem.listeners[i](player);
    }
}

void increase_exp(Player *player, int32_t amount) {
    player->exp += amount;
    printf("获得 %d 点经验，当前经验为 %d \n", amount, player->exp);

    while (player->exp >= EXP_PER_LEVEL && player->level < MAX_LEVEL) {
        player->exp -= EXP_PER_LEVEL;
        player->level++;
        triggerLevelUpEvent(player);
    }
}

// 升级一次提供宝藏提示
void treasureHintProvider(Player *player) {
    static const char *hints[MAX_LEVEL] = {"提示1: 宝藏隐藏在古老的瀑布后面",
                                           "提示2: 寻找被遗忘的失落之剑",
                                           "提示3: 探索神秘的地下洞穴",
                                           "提示4: 解开远古神庙的谜题",
                                           "提示5: 寻找沙漠中的绿洲",
                                           "提示6: 攀登雪山寻找隐藏的山洞",
                                           "提示7: 深入海底探索沉船",
                                           "提示8: 穿越时空裂缝",
                                           "提示9: 收集七颗龙珠",
                                           "提示10: 挑战最终BOSS"};

    if (player->level > 0 && player->level <= MAX_LEVEL) {
        printf("%s\n", hints[player->level - 1]);
    }
}

// 升级监听器，如果升级的话给个提示
void levelUpAnnouncer(Player *player) {
    printf("恭喜你升级到了 %d 级!\n", player->level);
}

void unlockNewAbility(Player *player) {
    printf("解锁了新的能力: ");
    // 可使用表驱动法
    switch (player->level) {
    case 3:
        printf("二段跳!\n");
        break;
    case 5:
        printf("水下呼吸!\n");
        break;
    case 7:
        printf("隐身!\n");
        break;
    case 9:
        printf("解锁法宝!\n");
        break;
    default:
        printf("没有新能力!\n");
        break;
    }
}

void unlockMap(Player *player) {
    printf("解锁了新的地图: ");

    // 表驱动数据
    MapUnlock mapTable[] = {{2, "青青草原"},
                            {4, "火焰山"},
                            {6, "冰雪峡谷"},
                            {8, "天空之城"},
                            {10, "魔王领域"}};

    int tableSize = sizeof(mapTable) / sizeof(mapTable[0]);
    int found = 0;

    for (int i = 0; i < tableSize; i++) {
        if (player->level == mapTable[i].level) {
            printf("%s!\n", mapTable[i].mapName);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("没有新地图!\n");
    }
}

int main(void) {

    Player player = {0, 1};

    // 添加升级时间监听器
    addLevelUpListener(levelUpAnnouncer);
    addLevelUpListener(unlockNewAbility);
    addLevelUpListener(treasureHintProvider);
    addLevelUpListener(unlockMap);

    // 模拟游戏过程中获得经验

    increase_exp(&player, 50);
    increase_exp(&player, 75);
    increase_exp(&player, 200);
    increase_exp(&player, 40);

    printf("最终等级：%d, 剩余经验: %d\n", player.level, player.exp);

    return 0;
}
