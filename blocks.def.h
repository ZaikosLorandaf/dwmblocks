//Modify this file to change what commands output to your statusbar, and recompile using the make command.
#define PATH(name)                       "$HOME/.local/bin/dwm-blocks/"name

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/

  {"",PATH("date-dwm"),     0,      10},

  #ifdef HOST_DISASTER
    {"",PATH("bright-dwm"), 0,      2},
    {"",PATH("bat-dwm"),    0,      1},
  #endif

};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
