#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 事件的处理框架

// 组织一场派对，你是主人
// 有人敲门（Event），你要去开门（根据这个特定事件你要做的行动Action,Function）
// 当音乐停止（Event），你要切换下一首(Function)

// Event -> Function

// 1. 定义事件类型和事件处理函数签名：
// 首先我们定义游戏中可能发生的事件类型，以及处理这些函数的签名
// 2. 实现事件注册和分发机制：
// 实现一个机制，允许为不同的类型的事件注册处理函数，并且在相应的事件发生时调用这些函数
// 3. 定义事件处理函数： 现在我们为游戏中的每一种事件类型定义具体的事件处理函数
// 4. 在游戏中使用事件处理系统：
// main中注册事件处理函数，并且模拟事件的发生来演示系统的工作流程。

typedef enum {
    PLAYER_ATTACK,
    PLAYER_MOVE,
    EVENT_COUNT // 记录事件的总数
} GameEventType;

typedef void (*EventHandler)(const char *playerName);

EventHandler eventHandlers[EVENT_COUNT]; // 事件处理函数的数组
// 声明了一个数组，这个数组的每一个元素都是EventHandler类型的函数指针，意味着每个数组元素都可以存储一个指向函数的指针，这个函数符合EventHandler的签名，它接受一个
// const char* 的参数类型并且返回void

// 注册事件处理函数
void registerEventHandler(GameEventType eventType, EventHandler handler);

// 分发事件
void dispatchEvent(GameEventType eventType, const char *playerName);

void handlePlayerAttack(const char *playerName);
void handlePlayerMove(const char *playerName);

int main(void) {
    // 注册事件处理函数
    registerEventHandler(PLAYER_ATTACK, handlePlayerAttack);
    registerEventHandler(PLAYER_MOVE, handlePlayerMove);

    // .....
    // 假如中间有各种各样的处理
    // 突然！事件发生了
    dispatchEvent(PLAYER_ATTACK, "Hero");
    dispatchEvent(PLAYER_MOVE, "Hero");

    return EXIT_SUCCESS;
}

void registerEventHandler(GameEventType eventType, EventHandler handler) {
    if (eventType < EVENT_COUNT) {
        eventHandlers[eventType] = handler;
        // TODO...
    } else {
        // TODO 可以在这里处理无效的eventType,
        fprintf(stderr, "Invalid eventType: %d\n", eventType);
    }
}

void dispatchEvent(GameEventType eventType, const char *playerName) {
    if (eventHandlers[eventType] != NULL) {
        eventHandlers[eventType](playerName);
    }
}

void handlePlayerAttack(const char *playerName) {
    printf("%s attacks!\n", playerName);
}
void handlePlayerMove(const char *playerName) {
    printf("%s moves!\n", playerName);
}