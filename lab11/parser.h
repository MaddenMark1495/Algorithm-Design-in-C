#ifdef PARSER_H
#define PARSER_H
int is_phone_number(char* word);
int is_date(char* word);
int looks_like_name(const char* word);
int is_email(char* word);

#endif
