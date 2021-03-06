#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include "list.h"
#include "isprog.h"

struct path_segment {
	char *path;
	struct list_head list;
};

static struct list_head head;

static void parse_path(void)
{
	struct path_segment *tmp;
	char *path, *p;

	path = strdup(getenv("PATH"));

	INIT_LIST_HEAD(&head);

	p = path;
	for (;;) {
		tmp = malloc(sizeof(struct path_segment));
		tmp->path = p;
		list_add_tail(&tmp->list, &head);
		p = strchr(p, ':');
		if (!p)
			break;
		*p = '\0';
		p++;
	}
}

/* Check if file exists and is exectable by "others" (i.e. user) */
static int is_ixoth(char *filename)
{
	struct stat sb;

	return (stat(filename, &sb) == 0 && sb.st_mode & S_IXOTH);
}

int isprog(const char *filename)
{
	char prog[4096], *p;
	struct path_segment *tmp;
	int pos, cmd_length;
	static int is_path_parsed;

	if (!is_path_parsed) {
		parse_path();
		++is_path_parsed;
	}

	/* ignore options/arguments */
	p = strchr(filename, ' ');
	if (p)
		cmd_length = p - filename;
	else
		cmd_length = strlen(filename);

	list_for_each_entry(tmp, &head, list) {
		strcpy(prog, tmp->path);
		pos = strlen(tmp->path);
		prog[pos++] = '/';
		strncpy(prog + pos, filename, cmd_length);
		prog[pos + cmd_length] = '\0';

		if (is_ixoth(prog))
			return 1;
	}

	return 0;
}
