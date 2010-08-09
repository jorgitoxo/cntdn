/* Header for cntdn

   James Stanley 2010 */

#ifndef CNTDN_H_INC
#define CNTDN_H_INC

#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define BUFLEN 4096

/* cntdn.c */
void die(const char *reason);
char *get_line(void);

/* opts.c */
extern char *program_name;

extern int players;
extern int timer;
extern char *format;
extern int nocolour;

void parse_opts(int argc, char **argv);

/* players.c */
typedef struct {
  char *raw_name;
  char *name;
  int length;
  char *word;
  int answer;
  int score;
} Player;
extern Player *player;

void make_players(void);
void show_scores(int endgame);

/* strings.c */
extern const char *letter_colour;
extern const char *colour_off;
extern const char const *colour[];
extern const int num_colours;

const char *get_name(void);
char get_vowel(void);
char get_consonant(void);

/* games.c */
void letters_round(void);
void numbers_round(void);
void teatime_teaser(void);
void conundrum(void);

/* dictcorner.c */
void origin_of_words(void);
void guest_chat(void);

#endif