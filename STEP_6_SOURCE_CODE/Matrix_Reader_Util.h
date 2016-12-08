#ifndef __MATRIX_READER_UTIL_H__
#define __MATRIX_READER_UTIL_H__

/*****************************/
/* Last Token Start in Lexer */
/*****************************/
extern int Matrix_Reader_start_token_position;

/**********************/
/* Remember New Lines */
/**********************/
void Matrix_Reader_New_Line(void);

/*******************************/
/* Matrix Reader Error Handler */
/*******************************/
void Matrix_Reader_Error_Handler(int pos, char *message,...);

#endif