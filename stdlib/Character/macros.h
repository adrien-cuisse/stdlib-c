
#ifndef STRING_MACROS_HEADER
#define STRING_MACROS_HEADER




#define IS_DIGIT(character) (((character) >= '0') && ((character) <= '9'))
#define IS_NOT_DIGIT(character) (! IS_DIGIT((character)))
#define DIGIT_VALUE(character) ((character) - '0')

#define IS_UPPER_LETTER(character) (((character) >= 'A') && ((character) <= 'Z'))
#define IS_LOWER_LETTER(character) (((character) >= 'a') && ((character) <= 'z'))
#define IS_LETTER(character) ((IS_LOWER_LETTER((character))) || (IS_LOWER_LETTER((character))))

#define IS_ALPHA_NUMERIC(character) ((IS_DIGIT((character))) || (IS_LETTER((character))))

#define IS_STRING_END(character) ('\0' == (character))
#define IS_NOT_STRING_END(character) (! IS_STRING_END((character)))




#endif /* STRING_MACROS_HEADER */
