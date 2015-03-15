
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ncurses.h>

const char * FDEFAULT = "HackerTyper.c";
const int NDEFAULT = 3;

void loadFile(FILE **, const char *);
void hackType(FILE *, const int);

int main(int argc, const char * argv[]) {

	FILE * fp;
	const char * fname, * opt;
	int nc;

	fname = FDEFAULT;
	nc = NDEFAULT;
	while (--argc > 0) {
		opt = *++argv;
		if (opt[0] == '-') {
			while (strlen(opt)) {
				switch(*++opt) {
					case 'f':
						if (--argc > 0)
							fname = *++argv;
						break;
					case 'c':
						if (--argc > 0)
							if (!(nc = atoi(*++argv)))
								nc = NDEFAULT;
						break;
				}
			}
		}
	}
	loadFile(&fp, fname);
	hackType(fp, nc);
}

void loadFile(FILE ** fp, const char * fname) {
	*fp = fopen(fname, "r");
	assert(*fp);
}

void hackType(FILE * fp, const int nc) {
	
	int i, c;
	initscr();
	noecho();
	cbreak();
	scrollok(stdscr, TRUE);
	attron(A_BOLD);
	if (has_colors() == TRUE) {
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		attron(COLOR_PAIR(1));
	}
	while (1) {
		getch();
		for (i = 0; i < nc; ++i) {
			if ((c = getc(fp)) == EOF) {
				fseek(fp, 0, SEEK_SET);
				c = getc(fp);
			}
			addch(c);
			refresh();
		}
		refresh();
	}
	endwin();

} 
