/*
 * Copyright (C) 2010, 2011 Christian Jahn
 *
 * @(#)parse-db.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char *db = "db";

void
usage(void)
{
	(void) fprintf(stderr, "usage: parse-db"
	    " -f registry prefix ...\n");
	exit(1);
}

int
main(int argc, char *argv[])
{
	int chr;

	while ((chr = getopt(argc, argv, "+f:")) > 0) {
		switch (chr) {
		case 'f':
			db = optarg;
			break;
		default:
			usage();
			/* NOTREACHED */
		}
	}

	argc -= optind;
	argv += optind;

	if (argc < 1)
		usage();
		/* NOTREACHED */

#ifdef DEBUG
	(void) fprintf(stderr, "DEBUG: DB = %s\n", db);
#endif

	return 0;
}

