//Modify this file to change what commands output to your statusbar, and recompile using the make command.
#define PATH(name)                       "$HOME/.local/bin/"name

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/

  {"",PATH("dwmb-date"),        0,      10},
  {"",PATH("dwmb-netstatus"),   0,      11},

  #ifdef HOST_DISASTER
    {"","backlightctl -g -q",   0,      2},
    {"",PATH("dwmb-battery"),   0,      1},
  #endif

};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
