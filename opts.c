/* Option parsing for cntdn

   James Stanley 2010 */

#include "cntdn.h"

char *program_name;

int players = 1;
int timer = 30;
char *format = "llllngtllllontlllnc";
int nocolour = 0;

static struct option opts[] = {
  { "format",    required_argument, NULL, 'f' },
  { "help",      no_argument,       NULL, 'h' },
  { "no-colour", no_argument,       NULL, 'n' },
  { "players",   required_argument, NULL, 'p' },
  { "timer",     required_argument, NULL, 't' },
  { NULL,        0,                 NULL, 0 }
};

static void usage(void) {
  printf(
  "cntdn - countdown game simulator\n"
  "Usage: %s [OPTIONS...]\n"
  "\n"
  "Options:\n"
  "  -c, --colour       Enable coloured output (default if stdout is a\n"
  "                     terminal)\n"
  "  -f, --format=STR   Set the game format as described below\n"
  "                     (default: llllngtllllontlllnc)\n"
  "  -h, --help         Display this help\n"
  "  -n, --no-colour    Disable coloured output\n"
  "  -p, --players=N    Set number of players (default: 1)\n"
  "  -t, --timer=N      Set round timer in seconds (default: 30)\n"
  "\n"
  "The game format is described as a series of characters corresponding to\n"
  "game rounds. The letter meanings are:\n"
  " l - Letters round        n - Numbers round        g - Guest chat\n"
  " t - Teatime teaser       o - Origin of words      c - Countdown conundrum\n"
  "\n"
  "Report bugs to James Stanley <james@incoherency.co.uk>\n"
  , program_name);
}

/* parse command line options. this function exit()'s if appropriate */
void parse_opts(int argc, char **argv) {
  int c;

  program_name = argv[0];

  if(!isatty(STDOUT_FILENO)) nocolour = 1;

  opterr = 1;

  while((c = getopt_long(argc, argv, "cf:hnp:t:", opts, NULL)) != -1) {
    switch(c) {
      case 'c': nocolour = 0;           break;
      case 'f': format = optarg;        break;
      case 'h': usage(); exit(0);       break;
      case 'n': nocolour = 1;           break;
      case 'p': players = atoi(optarg); break;
      case 't': timer = atoi(optarg);   break;
      default:  exit(1);                break;
    }
  }
}