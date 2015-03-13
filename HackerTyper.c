
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ncurses.h>

const char * FDEFAULT = "HackerTyper.c";
const int NDEFAULT = 3;

void loadFile(FILE *, char *);
void hackType(FILE *, int);

int main(int argc, const char * argv[]) {

	FILE * fp;
	char * fname, * opt;
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
	loadFile(fp, fname);
	hackType(fp, nc);
}

void loadFile(FILE * fp, char * fname) {
	fp = fopen(fname, "r");
	assert(fp);
}

void hackType(FILE * fp, int nc) {

	printf("%d\n", nc);

}

