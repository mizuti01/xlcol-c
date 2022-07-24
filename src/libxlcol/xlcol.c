#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>

#include "xlcol.h"

/**
 * @brief 'A'を0とした基数を返す その際、小文字は大文字と同一視
 * 
 * @param cols 文字
 * @return int 基数
 */
static int colbase(char cols)
{
    return toupper(cols)-'A';
}

/**
 * @brief Excel型式(A,AAなど)の列表記を数値文字列に変換する
 * 
 * @param srcstr Excel型式の列表記
 * @param dststr 数値に変換した文字列を格納するポインタ
 * @param dstbuf dststrで確保している領域
 * @return RESULT 終了コード
 */
RESULT excel_to_lotus(const char *srcstr, char *dststr, int dstbuf)
{
    int len=strlen(srcstr);
    int coll;
    char strbuf[RESULT_STR_LENGTH];

    if (len == 1) {
        coll=colbase(srcstr[0]);
    } else if (len == 2) {
        coll=colbase(srcstr[0])*26+colbase(srcstr[1])+26;
    } else if (len == 3) {
        coll=colbase(srcstr[0])*26*26+colbase(srcstr[1])*26+colbase(srcstr[2])+26+26*26;
    } else {
        return RESULT_ERR_ILLEGAL_FORMAT;
    }
    coll++;
    snprintf(strbuf, sizeof(strbuf), "%d", coll);
    if (strlen(strbuf) > dstbuf) {
        return RESULT_ERR_BUFFER_ERROR;
    }
    strcpy(dststr, strbuf);
    return RESULT_OK;
}

/**
 * @brief 数値形式で表記されている列番号をExcel形式に変換する
 * 
 * @param srcstr 数値形式の文字列(10進正値でなければならない)
 * @param dststr Excel型式の列番号を格納するポインタ
 * @param dstbuf strstrで確保している領域
 * @return RESULT 終了コード
 */
RESULT lotus_to_excel(const char *srcstr, char *dststr, int dstbuf)
{
    int colnum=atoi(srcstr);
    char strbuf[RESULT_STR_LENGTH];

    memset(strbuf, 0, sizeof(strbuf));
    if (colnum>0 && colnum <=26) {
        colnum-=1;
        strbuf[0]=(colnum-1)+'A';
    } else if (colnum > 26 && colnum <= 26+26*26) {
        colnum-=27;
        strbuf[0]=colnum/26+'A';
        strbuf[1]=colnum%26+'A';
    } else if (colnum > 26+26*26 && colnum <= 26+26*26+26*26*26) {
        colnum-=26*26+26+1;
        strbuf[0]=colnum/(26*26)+'A';
        strbuf[1]=(colnum/26)%26+'A';
        strbuf[2]=colnum%26+'A';
    } else {
        return RESULT_ERR_ILLEGAL_FORMAT;
    }
    if (strlen(strbuf) > dstbuf) {
        return RESULT_ERR_BUFFER_ERROR;
    }
    strcpy(dststr, strbuf);
    return RESULT_OK;
}