#ifndef LOG_H
#define LOG_H

extern unsigned char terminal_row;
extern unsigned char terminal_column;
extern unsigned char terminal_color;


void init_terminal();
void write_char(char c, unsigned char color, unsigned char x, unsigned char y);
void move_cursor(unsigned short pos);
void clear();

#endif
