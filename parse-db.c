/*
 * $Id$
 *
 * @(#) parse-db.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void
usage(void)
{
	fprintf(stderr, "usage: parse-db"
	    " -f registry prefix ...\n");
	exit(1);
}

int
main(int argc, char *argv[])
{
	int	 chr;
	char	*db;
	char	*prefix;

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

	if (argc - optind != 1)
		usage();
		/* NOTREACHED */

	prefix = argv[optind];

#ifdef DEBUG
	fprintf(stderr, "DEBUG: DB = %s, PREFIX = %s\n", db, prefix);
#endif

	return 0;
}

