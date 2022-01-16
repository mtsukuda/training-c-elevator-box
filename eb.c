//------------------------------------------------
//  エレベーターカゴ手配プログラム
//------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//------------------------------------------------
//  エレベーターカゴ構造体
//------------------------------------------------
typedef struct {
    char direction; //u -> 上方向, d -> 下方向, s -> 停止中
    int current; //現在の階数
} elvbox;

//------------------------------------------------
//  関数宣言
//------------------------------------------------
void elvBoxesInfo (elvbox [], int);
int makeRandomNumber (int);


//------------------------------------------------
//  概　要：一番近いエレベーターカゴを探す機能
//  引  数：elvbox    現在のエレベーター情報が入っている配列
//        ：int    エレベーターカゴの最大値
//  戻り値：一番近いエレベーターカゴ番号（0スタート）
//------------------------------------------------
int findElevatorBox (elvbox boxes[], int elvMax)
{
    // 課題の条件は以下の通り
    // ①一番近いエレベーター
    // ②方向が同じ or 停止中
    // ③同じ条件のエレベーターの場合、番号が若い方が優先
    return 0;
}

//------------------------------------------------
//  概　要：システムのエントリーポイント（main関数）
//  引  数：なし
//  戻り値：0: 正常、0以外: 異常
//------------------------------------------------
int main()
{
    int i = 0;
    char command[256] = {}; // 入力コマンドバッファ
    elvbox boxes[3]; // エレベーターカゴデータ
    int myFloor = 1; // 現在の階数
    int myDirection = 0; // 行きたい方向

    // 乱数初期化
    srand((unsigned int)time(NULL));

    // 初期表示メッセージ
    printf("***** エレベーターカゴ手配プログラム🛗\n");
    printf("***** このプログラムは呼び出された階で一番近い階のエレベーターカゴを手配します💪\n");
    printf("\n");

    for (;;) {
        printf("現在の階数を入力してください💁‍♀️: ");
        scanf("%s", command);

        /* 入力値に Q か q が入力されたら for ループを抜ける */
        if(strcmp(command, "Q") == 0 || strcmp(command, "q") == 0) {
            printf("プログラムを終了します...👋");
            return 0;
        }

        if (atoi(command) < 1 || atoi(command) > 20) {
            printf("階数は1階〜20階までです\n");
            continue;
        }

        /* 入力された現在の階数を myFloor 変数にセット */
        myFloor = atoi(command);

        for (;;) {
            printf("行きたい方向を番号で入力してください 1:⬆️  2:⬇️ : ");
            scanf("%s", command);
    
            if (atoi(command) < 1 || atoi(command) > 2) {
                printf("指定できる方向は 1=>上、2=>下 のどちらかです\n");
                continue;
            }

            if (atoi(command) == 1 && myFloor == 20) {
                printf("最上階にいるので指定できる方向は 2=>下 のみです\n");
                continue;
            }

            if (atoi(command) == 2 && myFloor == 1) {
                printf("一階にいるので指定できる方向は 1=>上 のみです\n");
                continue;
            }
            break;
        }
        break;
    }

    // エレベーターの現在位置をランダムに生成
    elvBoxesInfo(boxes, 3);

    printf("==> エレベーター情報：\n");
    for (i=0; i<3; i++) {
        printf("    %d号基:\n", i+1);
        printf("      現在地: %d\n", boxes[i].current);
        printf("      状　態: %c\n", boxes[i].direction);
    }

    // 一番近いエレベーターカゴを探して返す
    printf("\n==> 一番近いエレベーターカゴ🛗 : %d号基\n", findElevatorBox(boxes, 3) + 1);

    return 0;
}

//------------------------------------------------
//  概　要：エレベーター情報を自動生成する関数（テスト用）
//  引  数：elvbox    エレベーターカゴ変数（配列）
//       ：int    エレベーターカゴ最大数
//  戻り値：なし
//------------------------------------------------
void elvBoxesInfo (elvbox boxes[], int elvMax)
{
    int i = 0;
    int stat = 0;

    for (i=0; i<elvMax; i++) {
      boxes[i].current = makeRandomNumber(20);
      stat = makeRandomNumber(3);
      // printf("%d\n", stat);
      switch(stat)
      {
          case 1: boxes[i].direction = 'u'; break;
          case 2: boxes[i].direction = 'd'; break;
          case 3: boxes[i].direction = 's'; break;
      }
    }
}

//------------------------------------------------
//  概　要：乱数最大値で指定された間の乱数を生成する関数
//  引  数：int    乱数最大値
//  戻り値：乱数値
//------------------------------------------------
int makeRandomNumber (int randMax)
{
    return (int)(rand() % randMax + 1);
}
