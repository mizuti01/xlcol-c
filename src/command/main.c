#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <memory.h>
#include <ctype.h>

#include "xlcol.h"

/**
 * @brief メイン関数
 * 
 * @param argc 引数の数
 * @param argv 引数の実体
 * @return int 終了コード
 */
int main(int argc, char *argv[])
{
    const char *arg, *argp;
    bool type_lotus=false, type_excel=false, type_other=false;
    RESULT result;
    char strbuf[RESULT_STR_LENGTH];

    /* 引数チェック */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <column>\n", argv[0]);
        fprintf(stderr, "  Column accepts Number format or Excel format.\n");
        exit(1);
    }
    arg = argv[1];
 
    /* 入力値・入力タイプチェック */
    argp = arg;
    while (*argp != '\0') {
        if (isdigit(*argp)) {
            type_lotus = true;
        } else if (isalpha(*argp)) {
            type_excel = true;
        } else {
            type_other = true;
        }
        argp++;
    }

    memset(strbuf, 0, sizeof(strbuf));

    /* 入力型によって変換処理を実行する 不正入力であればエラー終了 */
    if (type_excel && !type_lotus && !type_other) {
        result = excel_to_lotus(arg, strbuf, sizeof(strbuf));
    } else if (type_lotus && !type_excel && !type_other) {
        result = lotus_to_excel(arg, strbuf, sizeof(strbuf));
    } else {
        fprintf(stderr, "Error: Illegal format for column.\n");
        exit(1);
    }  

    /* 変換結果が正常なら結果を表示 
       失敗した場合はエラー終了    */
    if (result == RESULT_OK)
    {
        puts(strbuf);
    } else {
        switch (result)
        {
        case RESULT_ERR_ILLEGAL_FORMAT:
            /* 不正フォーマット(Excel型式で4桁超えもしくは数値形式で18278超え) */
            fprintf(stderr, "Error: Illegal format for column.\n");
            break;
        
        case RESULT_ERR_BUFFER_ERROR:
            /* 受け取りバッファ不足 (通常このコマンドでは発生し得ない) */
            fprintf(stderr, "Error: Internal error. (Buffer overflow)\n");
            break;
        
        default:
            /* その他のエラー */
            fprintf(stderr, "Error: Unknown error\n");
            break;
        }
        exit(1);
    }
    return 0;
}