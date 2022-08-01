#ifndef __XLCOL_H__
#define __XLCOL_H__

/* 定数宣言 (#defineではなくstatic constにしているのは意図的) */
#define RESULT_STR_LENGTH (16)
// static const int RESULT_STR_LENGTH = 16; /* 変換後の文字列受け取りバッファの確保容量 */

/**
 * @brief 関数の終了コード定義
 */
typedef enum {
    RESULT_OK = 0, /* 正常終了 */
    RESULT_ERR_ILLEGAL_FORMAT = 1, /* 入力文字列不正 */
    RESULT_ERR_BUFFER_ERROR = 2, /* 受け取りバッファで確保した領域が不足 */
} RESULT;

/* プロトタイプ宣言 */
extern RESULT excel_to_lotus(const char *srcstr, char *dststr, int dstbuf);
extern RESULT lotus_to_excel(const char *srcstr, char *dststr, int dstbuf);

#endif
